void PopDisplayMenu() {
  myGLCD.clrScr();

  //Title
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("DISPLAY", CENTER, 18);

  //Set RPM
  myGLCD.setFont(SmallFont);
  myGLCD.print("RPM", 16, 66);

  //Set Speed
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("SPEED", 176, 66);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("Km/h", 280, 66);

  //Set IAT
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("IAT", 16, 86);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("C", 124, 86);

  //Set ECT
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("ECT", 176, 86);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("C", 280, 86);

  //Set AFR
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("AFR", 16, 106);

  //Set inHg
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("inHg", 176, 106);

  //Set MAP
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("MAP", 16, 126);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("mBar", 124, 126);

  //Set BATT
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("BATT", 176, 126);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("V", 280, 126);

  //Set TPS
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("TPS", 16, 146);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("%", 124, 146);

  //Set IGN
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("IGN.", 176, 146);

  //Set O2
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("O2", 16, 166);

  //Set Conso
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("CONS.", 176, 166);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("L/H", 280, 166);

  //Set VTEC
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("VTEC", 16, 186);

  //Lines
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawLine(0, 62, 319, 62);
  myGLCD.drawLine(0, 200, 319, 200);
  myGLCD.drawLine(160, 62, 160, 200);

   //Back Button
  myGLCD.drawRect(0, 220, 44, 239);
  myGLCD.print("BACK", 6, 224);
}

//##################################################################################

void PopDisplayRPM() {
  ClearArea(68, 64, 122, 78);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.printNumI(Display_Rpm, 70, 66);
}

//##################################################################################

void PopDisplayVSS() {
  ClearArea(229, 64, 262, 78);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.printNumI(Display_Vss, 231, 66);
}

//##################################################################################

void PopDisplayIAT() {
  ClearArea(68, 84, 122, 98);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_IAT), 70, 86);
}

//##################################################################################

void PopDisplayECT() {
  ClearArea(229, 84, 262, 98);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.printNumI(Display_ECT, 231, 86);
}

//##################################################################################

void PopDisplayAFR() {
  ClearArea(68, 104, 122, 118);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_AFR), 70, 106);
}

//##################################################################################

void PopDisplayinHg() {
  ClearArea(229, 104, 277, 118);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_inHg), 231, 106);
}

//##################################################################################

void PopDisplayMAP() {
  ClearArea(68, 124, 122, 138);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_MAP), 70, 126);
}

//##################################################################################

void PopDisplayBATT() {
  ClearArea(229, 124, 277, 138);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_BATT), 231, 126);
}

//##################################################################################

void PopDisplayTPS() {
  ClearArea(68, 144, 122, 158);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_TPS), 70, 146);
}

//##################################################################################

void PopDisplayIGN() {
  ClearArea(229, 144, 277, 158);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_IGN), 231, 146);
}

//##################################################################################

void PopDisplayO2() {
  ClearArea(68, 164, 122, 178);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_O2), 70, 166);
}

//##################################################################################

void PopDisplayCONSO() {
  ClearArea(229, 164, 277, 178);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  myGLCD.print(String(Display_CONSO), 231, 166);
}

//##################################################################################

void PopDisplayVTEC() {
  ClearArea(68, 184, 122, 198);
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  if (Display_VTEC) {
    myGLCD.print("ON", 70, 166);
  } else {
    myGLCD.print("OFF", 70, 186);
  }
}

//####################################################################################################################################################################
//####################################################################################################################################################################
