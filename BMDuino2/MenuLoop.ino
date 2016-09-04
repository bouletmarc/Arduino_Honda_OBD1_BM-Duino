//Upload each part of menu that need to upload with a loop (rapid refresh)
void MenuLoop() {
  
  if (lcd_menu == 3) {
    //Display Menu
    PopDisplayRPM();
    PopDisplayVSS();
    PopDisplayIAT();
    PopDisplayECT();
    PopDisplayAFR();
    PopDisplayinHg();
    PopDisplayMAP();
    PopDisplayBATT();
    PopDisplayTPS();
    PopDisplayIGN();
    PopDisplayO2();
    PopDisplayCONSO();
    PopDisplayVTEC();
  } else if (lcd_menu == 5) {
    //BeeR Menu
    PopBeeMRRPM();
  } else if (lcd_menu == 10 && Prog_BoardType == 1){
    //Table Menu
    PopBoardDisplayTable();
  } else if (lcd_menu == 10 && Prog_BoardType == 2){
    //Graphic Menu
    PopBoardDisplayGraphic();
  }
  
  //Display millis
  if (displayMillis) {
    PopDisplayMillis();
  }
}

//####################################################################################################################################################################
//####################################################################################################################################################################

void PopDisplayMillis() {
  ClearArea(290, 0, 319, 14);

  long FPS = 1000/(millis() - LastMillis);

  if (FPS >= 1000) {
    FPS = 999;
  }

  //Set millis Text
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print(String(FPS), 292, 2);

  //Set Last millis
  LastMillis = millis();
}
