//Set Your Injector Size. Default : 240cc
int injsize = 240;

//Set the Datalogging Addresse to the correct one for your ECU (these addresse are for Crome >= 1.4, Work with P30 bin)
byte ADDR_RPMLOW  = 0x10;
byte ADDR_RPMHIGH = 0x11;
byte ADDR_LOCAM   = 0x12;
byte ADDR_HICAM   = 0x13;
byte ADDR_MAP     = 0x14;
byte ADDR_TPS     = 0x15;
//byte ADDR_COL     = 0x16;
byte ADDR_INJLOW  = 0x17;
byte ADDR_INJHIGH = 0x18;
byte ADDR_IGN     = 0x19;
//byte ADDR_KNOCK   = 0x1A;
byte ADDR_IAT     = 0x1B;
byte ADDR_VSS     = 0x1C;
byte ADDR_ECT     = 0x1D;
//byte ADDR_BARO    = 0x1E;
byte ADDR_BATT    = 0x1F;
byte ADDR_O2      = 0x20;
byte ADDR_VTEC    = 0x22;

unsigned int ecuTimeout = 5000;

//##################################################################################

void GetData(){
  //Get RPM&Speed Raw Values
  float speedRaw=ecuRead(ADDR_VSS);
  unsigned int rpmLowRaw=ecuRead(ADDR_RPMLOW);
  unsigned int rpmHighRaw=ecuRead(ADDR_RPMHIGH);
  int RPM = 1851562/((rpmHighRaw * 256) + rpmLowRaw);
  
  //Reset Rpm Display
  if (RPM < 0) {
    RPM = 0;
  } else if (RPM > 9999) {
    RPM = 9999;
  }

  //Set RPM & Speed Display
  Display_Rpm     = RPM;
  //Display_Rpm   = .92*Display_Rpm+.08*RPM;        //Simple IIR filter to smooth out the digital rpm read out
  //Display_Vss   = .4*speedRaw;    //MPH
  Display_Vss     = speedRaw;         //KMH

  //Get&Set All Others Displays
  if (lcd_menu == 3 | lcd_menu == 10) {
    float ECTTempRaw=ecuRead(ADDR_ECT);
    float IATRaw=ecuRead(ADDR_IAT);
    int o2Raw=ecuRead(ADDR_O2);
    float mapRaw=ecuRead(ADDR_MAP);
    float tpsRaw=ecuRead(ADDR_TPS);
    unsigned int lowInjRaw=ecuRead(ADDR_INJLOW);
    unsigned int highInjRaw=ecuRead(ADDR_INJHIGH);
    unsigned int ignRaw=ecuRead(ADDR_IGN);
    float batteryRaw = ecuRead(ADDR_BATT);
    int vtecRaw=ecuRead(ADDR_VTEC);

    //Set Between Values
    float altitudeOffset = -10.87*(float(EEPROM.read(2))*5/256)+30.48;
    float Fake_inHg = -10.87*(float(mapRaw)*5/256)+30.48;
    Fake_inHg = Fake_inHg-altitudeOffset;  //now inHg is guage Vac and no longer absolute vac
    tpsRaw = (0.4716 * tpsRaw) - 11.3184;

    //Get Vtec
    bool VtecActive = false;
    if (vtecRaw == 67) {
      VtecActive = true;
    }

    Display_ECT     = calcTemp(ECTTempRaw, UseFareneith);
    Display_IAT     = calcTemp(IATRaw, UseFareneith);
    Display_AFR   = (2*o2Raw) + 10;
    //Display_AFR     = (float(o2Raw)*5/256)*2+9.6; //AFR o2 for zietronix widebands
    Display_inHg    = constrain(Fake_inHg,0,50);
    Display_MAP     = (1764/255)*mapRaw;    //mBar
    Display_BATT    = (26.0 * batteryRaw) / 270.0;
    Display_TPS     = constrain(tpsRaw, 0, 100);
    Display_IGN     = (0.25 * ignRaw) - 6;
    Display_O2      = o2Raw;
    Display_CONSO   = constrain(calcConso(), 0.0001, 50.0);
    Display_VTEC    = VtecActive;

    if(Display_Rpm<30){   //28 is the rpm that it displays when engine is off
      EEPROM.write(2,mapRaw); 
    }
  }
}

//##################################################################################

byte ecuRead(byte ecuAddress) {
  Serial3.write(ecuAddress);
  unsigned int time=0;
  while(Serial3.available() == 0 && time < ecuTimeout) time+=1;
  if (time >= ecuTimeout) return 0x00;  
  else return Serial3.read();
}

//##################################################################################

float calcConso() {
  unsigned int lowInjRaw=ecuRead(ADDR_INJLOW);
  unsigned int highInjRaw=ecuRead(ADDR_INJHIGH);
  
  float injValue = ((highInjRaw * 256) + lowInjRaw)  / 352;
  float dutyCycle = (Display_Rpm * injValue) / 1200;
  float hundredkm = ((60 / Display_Vss) * 100) / 60;     //minutes needed to travel 100km
  return (hundredkm * ((injsize / 100) * dutyCycle)) / 1000;
}

//##################################################################################

float calcTemp(int raw, bool Far) {
  if (Far) {
    //Fareneith
    if(raw>45)
      return -.8334*float(raw) + 194.25;
    else if(raw<=45)
      return -2.3529*float(raw) + 263.0;
  } else {
    //Celcius
    raw = raw / 51;
    raw = (0.1423*pow(raw,6)) - (2.4938*pow(raw,5))  + (17.837*pow(raw,4)) - (68.698*pow(raw,3)) + (154.69*pow(raw,2)) - (232.75*raw) + 284.24;
    return ((raw - 32)*5)/9;
  }
}

//##################################################################################

void CheckForBeeMR(){
  //Enable Launch
  if (BeeMRLaunchEnabled && BeeMRLanching == false && Display_Rpm >= BeeMRLaunchRPM && Display_Vss <= BeeMRLaunchVSS) {
    BeeMRLanching = true;
    digitalWrite(RelayPin, HIGH);
    digitalWrite(RelayPin2, HIGH);
    if (BeeMRMode == 0) {
      //Reload Menu
      if (lcd_menu == 5) {
        PopBeeMRRPM();
      }
      //1st Wait (Relay Activation Time)
      delay(RelayActivaionTime);
      //Disable By Time
      delay(BeeMRLaunchCutTime);
      BeeMRLanching = false;
      digitalWrite(RelayPin, LOW);
      digitalWrite(RelayPin2, LOW);
      //2rd Wait (Relay Activation Time)
      delay(RelayActivaionTime);
    }
  }

  //Enable Limiter
  if (BeeMRRevLimiting == false && Display_Rpm >= BeeMRRevRPM) {
    if ((BeeMRLaunchEnabled && Display_Vss > BeeMRLaunchVSS) | BeeMRLaunchEnabled == false) {
      BeeMRRevLimiting = true;
      digitalWrite(RelayPin, HIGH);
      digitalWrite(RelayPin2, HIGH);
      if (BeeMRMode == 0) {
        //Reload Menu
        if (lcd_menu == 5) {
          PopBeeMRRPM();
        }
        //Disable By Time
        delay(BeeMRRevCutTime);
        BeeMRRevLimiting = false;
        digitalWrite(RelayPin, LOW);
        digitalWrite(RelayPin2, LOW);
        Display_Rpm -= 100;
      }
    }
  }

  //Disable By Rpm
  if (BeeMRMode == 1) {
    if (BeeMRLanching && Display_Rpm <= BeeMRLaunchRPM - BeeMRLaunchCutRPM) {
      BeeMRLanching = false;
      digitalWrite(RelayPin, LOW);
      digitalWrite(RelayPin2, LOW);
    }
    if (BeeMRRevLimiting && Display_Rpm <= BeeMRRevRPM - BeeMRRevCutRPM) {
      BeeMRRevLimiting = false;
      digitalWrite(RelayPin, LOW);
      digitalWrite(RelayPin2, LOW);
    }
  }
}

//####################################################################################################################################################################
//####################################################################################################################################################################
