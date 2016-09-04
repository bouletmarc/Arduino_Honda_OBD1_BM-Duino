//##################################################################################

void PopBeeMRMenu() {
  //Clear
   myGLCD.clrScr();

  //Set Itinial Values
  myGLCD.setBackColor(0, 0, 0);

  //Title
  myGLCD.setColor(0, 140, 0);
  myGLCD.setFont(BigFont);
  myGLCD.print("BeeM*R Rev Limiter", CENTER, 24);

  //Enabled#Disabled
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(12, 56, 80, 70);
  if (BeeMREnabled) {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ENABLED", 16, 58);
  } else {
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("DISABLED", 16, 58);
  }

  if (BeeMREnabled) {
    //Mode
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(110, 56, 308, 70);
    myGLCD.print("Mode :", 114, 58);
    myGLCD.setColor(255, 255, 0);
    if (BeeMRMode == 0) {
      myGLCD.print("Datalogging Input", 170, 58);
    } else {
      myGLCD.print("ICM Wire Input", 170, 58);
    }
  
    //Launch
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(12, 76, 145, 90);
    myGLCD.print("Launch :", 16, 78);
    if (BeeMRLaunchEnabled) {
      myGLCD.setColor(0, 255, 0);
      myGLCD.print("ENABLED", 81, 78);
    } else {
      myGLCD.setColor(255, 0, 0);
      myGLCD.print("DISABLED", 81, 78);
    }
  
    //VSS Speed
    if (BeeMRLaunchEnabled) {
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(149, 76, 308, 90);
      myGLCD.print("Max VSS Speed :", 155, 78);
      myGLCD.setColor(255, 255, 0);
      myGLCD.printNumI(BeeMRLaunchVSS, 284, 78);
    }
  
    //Separator Line
    myGLCD.setColor(255, 255, 0);
    myGLCD.drawLine(0, 96, 319, 96);
  
    //Limiter RPM
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(12, 102, 160, 116);
    myGLCD.print("Limiter RPM :", 16, 104);
    myGLCD.setColor(255, 255, 0);
    myGLCD.printNumI(BeeMRRevRPM, 126, 104);
  
    //Launch RPM
    if (BeeMRLaunchEnabled) {
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(164, 102, 308, 116);
      myGLCD.print("Launch RPM :", 168, 104);
      myGLCD.setColor(255, 255, 0);
      myGLCD.printNumI(BeeMRLaunchRPM, 272, 104);
    }
  
    //Check For Input Mode
    if (BeeMRMode == 0) {
      //Limiter Time
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(12, 120, 218, 134);
      myGLCD.print("Limiter Cut Time :", 16, 122);
      myGLCD.setColor(255, 255, 0);
      myGLCD.printNumI(BeeMRRevCutTime, 166, 122);
      myGLCD.setColor(255, 255, 255);
      myGLCD.print("ms", 200, 122);
    
      //Launch Time
      if (BeeMRLaunchEnabled) {
        myGLCD.setColor(255, 255, 255);
        myGLCD.drawRect(12, 138, 210, 152);
        myGLCD.print("Launch Cut Time :", 16, 140);
        myGLCD.setColor(255, 255, 0);
        myGLCD.printNumI(BeeMRLaunchCutTime, 156, 140);
        myGLCD.setColor(255, 255, 255);
        myGLCD.print("ms", 192, 140);
      }
    } else {
      //Limiter Cut
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(12, 120, 220, 134);
      myGLCD.print("Limiter Cut RPM :", 16, 122);
      myGLCD.setColor(255, 255, 0);
      myGLCD.printNumI(BeeMRRevCutRPM, 162, 122);
      myGLCD.setColor(255, 255, 255);
      myGLCD.print("rpm", 196, 122);
    
      //Launch Cut
      if (BeeMRLaunchEnabled) {
        myGLCD.setColor(255, 255, 255);
        myGLCD.drawRect(12, 138, 212, 152);
        myGLCD.print("Launch Cut RPM :", 16, 140);
        myGLCD.setColor(255, 255, 0);
        myGLCD.printNumI(BeeMRLaunchCutRPM, 152, 140);
        myGLCD.setColor(255, 255, 255);
        myGLCD.print("rpm", 188, 140);
      }
    }
  }

  //Add Rpm Text
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(BigFont);
  myGLCD.print("RPM", 16, 176);

  if (BeeMREnabled) {
    //Add Bottom Infos Text
    myGLCD.setFont(SmallFont);
    myGLCD.setColor(255, 255, 255);
    myGLCD.print("Launch VSS", 50, 224);
    if (BeeMRLaunchEnabled) {
      myGLCD.print("Launch", 160, 224);
    }
    myGLCD.print("Limiter", 238, 224);
  }

  //Back Button
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont);
  myGLCD.drawRect(0, 220, 44, 239);
  myGLCD.print("BACK", 6, 224);
}

//##################################################################################

void PopBeeMRRPM() {
  ClearArea(74, 176, 180, 196);
  
  //Set
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 255, 255);
  myGLCD.printNumI(Display_Rpm, 76, 176);

  if (BeeMREnabled) {
    BeeMRGetBottomInfos();
  }
}

//##################################################################################

void BeeMRGetBottomInfos() {
  //Get VSS States
  if (Display_Vss <= BeeMRLaunchVSS) {
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillCircle(144, 228, 8);
  } else {
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillCircle(144, 228, 8);
  }

  //Get Launch States
  if (BeeMRLaunchEnabled) {
    if (BeeMRLanching) {
      myGLCD.setColor(0, 255, 0);
      myGLCD.fillCircle(222, 228, 8);
    } else {
      myGLCD.setColor(255, 0, 0);
      myGLCD.fillCircle(222, 228, 8);
    }
  }

  //Get Rev Limiting States
  if (BeeMRRevLimiting) {
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillCircle(308, 228, 8);
  } else {
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillCircle(306, 228, 8);
  }
}
