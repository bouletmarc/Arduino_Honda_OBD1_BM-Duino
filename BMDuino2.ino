//################################################################################
//################################################################################
//####                                                                        ####
//####                          BM-DUINO V1.1                                 ####
//####                                                                        ####
//####   THIS IS A HONDA OBD1 DATALOGGER TO BE USED WITH A 3.2" TFT SCREEN    ####
//####                                                                        ####
//####                       MADE BY BOULETMARC                               ####
//####                                                                        ####
//####   CURRENT FEATURES :                                                   ####
//####   -CN2 Datalogger                                                      ####
//####   -Tables Board                                                        ####
//####   -Display Board                                                       ####
//####   -BeeM*R Rev Limiter                                                  ####
//####   -Customize Menu                                                      ####
//####                                                                        ####
//################################################################################
//################################################################################
//#include <SD.h> ###
//#include <SdFat.h>
//#include <SdStream.h> ###
//#include <SPI.h>
#include <UTFT.h>
#include <ITDB02_Touch.h>
#include <EEPROM.h>

//SdFat sd;

//int SD_CHIP_SELECT  = 53;  // SD chip select pin
//ArduinoOutStream cout(Serial);

// Set the parameters to the correct one for your TFT Scren
UTFT        myGLCD(SSD1289, 38, 39, 40, 41);
ITDB02_Touch  myTouch(6, 5, 4, 3, 2);

//Set the Relays Pin & Settings used to trigger the BeeM*R
int RelayPin = 50;
int RelayPin2 = 46;
float RelayActivaionTime = 10;

//Set SD Cards Folder and FileName
String SDFolder = "BM-Duino";
String LOG = "LOG.txt";
String MENU_Settings = "MENU_Settings.txt";         //Used for colors
String OBD_Settings = "OBD_Settings.txt";           //Used for Dataloging Memory Offsets, InjSize, etc
String OBD_Tables = "OBD_Tables.txt";
String OBD_BEEMR_Settings = "OBD_BeeMR.txt";

//Check if Display_Rpm changed get the rpm enought fast to not trigger the relay more than 1 time at high rpm.
//Record Values                                     -
//Suggest AFR                                       -
//Dont pop BeeM*R Selection while not enabled       -
//Tell if AFR are Lean or Rich + Color              -
//Temperature Coloring                              -

//fix graphics board                                -
//fix beemr slection for rpm input                  -DONE ?
//add fuel pump delay                               -NEED TO WORK WITH RELAY TO CONTROL 2 INPUT
//added relay activation time                       -DONE

//#####################################################################
//###             DONT EDIT ANYTHING BELLOW THIS LINE               ###
//#####################################################################
// Make Menu Variables
int lcd_menu              = 0;
int Display_Rpm           = 0;
int Display_Vss           = 0;
int Display_IAT           = 0;
int Display_ECT           = 0;
float Display_AFR         = 0;
float Display_inHg        = 0;    //inHg
int Display_MAP           = 0;    //mBar
float Display_BATT        = 0;
float Display_TPS         = 0;
float Display_IGN         = 0;
float Display_O2          = 0;
float Display_CONSO       = 0;
bool Display_VTEC         = 0;
//float Display_Altitude    = 0;

// Make Internal Variables
bool displayMillis        = true;
long LastMillis           = 0;        // used for last millis counter
long previousMillis       = 0;        // used for last Touch update
long interval             = 500;      // interval to enable back touch input (milliseconds)
bool TouchSomething       = false;
bool readyopen            = false;    //Used to see if its ready to run trought all menus (finished start loading)
bool UseFareneith         = false;
//int OBDTestValue          = 1;        //Used to check if the OBD are currently plugged and Running
//int Display_Mode          = 0;        // 0=6displays | 1=single displays
int TempValue1            = 0;
int TempValue2            = 0;
int TempValue3            = 0;
int TempValue4            = 0;
int TempValue5            = 0;
int CurrentSelection      = 0;        //1=vss | 2=limiter | 3=launch | 4=limitertime | 5=launchtime | 6=limitercut | 7=launchcut | MOARSS

//Make Programming Variables (Tables  Graphic Board)
int Prog_BoardType        = 0;      //1=Table 2=Graphic
int Prog_BoardMode        = 0;      //Used to get selection menu variables (logging vars or x&y vars)
int Prog_Rows             = 20;
int Prog_Cols             = 10;
int Prog_XMin             = 114;
int Prog_XMax             = 1035;
bool Prog_XFloat          = false;
int Prog_YMin             = 0;
int Prog_YMax             = 9000;
bool Prog_YFloat          = false;
int Prog_X_ID             = 1;      //0=RPM | 1=mBar | 2=SPEED | 4=IAT | 5=ECT | 6=TPS
int Prog_Y_ID             = 0;      //0=RPM | 1=mBar | 2=SPEED | 4=IAT | 5=ECT | 6=TPS
int Prog_Log_Value        = 2;      //0=IAT | 1=ECT | 2=AFR | 3=BATT | 4=TPS | 5=IGN | 6=O2 | 7=CONSO | 8=SPEED
bool Prog_LogFloatVal     = false;  //Log Float Value ? otherwise Log Integer
int Prog_LastX            = 0;      //used to get the last graphics posx
int Prog_LastY            = 0;      //used to get the last graphics posy
long Prog_NextUpdate       = 0;      //used for the next graphic menu update

// Make BeeM*R Variables
int BeeMRMode             = 0;        //Mode0 = Datalogging Input ||| Mode1 = Ignition Control Module Input
bool BeeMREnabled         = false;
bool BeeMRLaunchEnabled   = true;
int BeeMRRevRPM           = 8800;
int BeeMRLaunchRPM        = 3500;
int BeeMRRevCutRPM        = 400;
int BeeMRLaunchCutRPM     = 200;
int BeeMRRevCutTime       = 400;
int BeeMRLaunchCutTime    = 200;
int BeeMRLaunchVSS        = 8;
bool BeeMRLanching        = false;    //is currently in the launch control state
bool BeeMRRevLimiting     = false;    //is currently in the rev limiter state

// Texts Color Vars
int Txt1_R = 0;
int Txt1_G = 140;
int Txt1_B = 0;
int Txt2_R = 0;
int Txt2_G = 140;
int Txt2_B = 0;
int Txt3_R = 0;
int Txt3_G = 140;
int Txt3_B = 0;

// Border Colors Vars
int Col_Border_R = 0;
int Col_Border_G = 255;
int Col_Border_B = 0;

// File Vars
//SdFile LoadedFile;
String CurrentStringCheck = "";
String CurrentLineCheck = "";

// Fonts Vars
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
//##################################################################################

void setup() {
  //Init SD Card
  /*Serial.begin(9600);
  bool mysd = 0;
  while (!mysd) {
    if (!sd.begin(SD_CHIP_SELECT, SPI_FULL_SPEED)) {
      Serial.println(F("Card failed, or not present"));
      Serial.println(F("Retrying...."));
    } else {
      mysd = 1;
      Serial.println(F("Card initialised."));
    }
  }*/
  
  //Init DataLogger
  Serial3.begin(38400);
  
  //Initialize and Clear LCD
  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.clrScr();

  //Initialize and Set Precision of Touch Screen
  myTouch.InitTouch(LANDSCAPE);
  //myTouch.setPrecision(PREC_MEDIUM);
  myTouch.setPrecision(PREC_HI);

  //Init Relays
  pinMode(RelayPin, OUTPUT);
  pinMode(RelayPin2, OUTPUT);

  /*CheckForFiles(LOG);
  CheckForFiles(MENU_Settings);
  CheckForFiles(OBD_Settings);
  CheckForFiles(OBD_Tables);
  CheckForFiles(OBD_BEEMR_Settings);*/

  //Start Menu
  PopStartMenu();

  //Update EEPROM Read
  /*delay(10);
  if(EEPROM.read(0)>3){  //This takes care of the possible bug if the EEPROM has a non state value already stored
    EEPROM.write(0,0);   //update number to last display state value
  }
  displayState=EEPROM.read(0);*/

  GetData();
}

//##################################################################################

void loop() {
  //Get ECU Data
  GetData();

  //Check Data to Enable/Disable Running state of BeeM*R
  if (BeeMREnabled) {
    CheckForBeeMR();
  }

  //Refresh Menus
  MenuLoop();

  //Check For Inputing
  CheckForInput();
}
