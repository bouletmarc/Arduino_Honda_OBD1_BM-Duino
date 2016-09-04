void PopStartMenu() {
  //Clear
   myGLCD.clrScr();

   //Set Version & Update Infos
  String VERSION = SetVersionInfos();
  String UPDT_NOTES1  = SetUpdateInfos("Note1");
  String UPDT_NOTES2  = SetUpdateInfos("Note2");
  String UPDT_NOTES3  = SetUpdateInfos("Note3");
  String UPDT_NOTES4  = SetUpdateInfos("Note4");
  String UPDT_NOTES5  = SetUpdateInfos("Note5");

  //Set Itinial Values
  myGLCD.setColor(0, 255, 0);
  myGLCD.setBackColor(0, 0, 0);

  //Title
  myGLCD.setFont(BigFont);
  myGLCD.print("BM-DUINO", CENTER, 24);

  //Version
  myGLCD.setFont(SmallFont);
  myGLCD.print(VERSION, CENTER, 40);

  //Desc
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("This is a Honda OBD1 Datalogger.", CENTER, 82);
  myGLCD.print("It Read Rx&Tx Data of the CN2 Port.", CENTER, 94);

  //Update Notes
  myGLCD.print("  UPDATES NOTES :", LEFT, 156);
  myGLCD.print(UPDT_NOTES1, LEFT, 168);
  myGLCD.print(UPDT_NOTES2, LEFT, 180);
  myGLCD.print(UPDT_NOTES3, LEFT, 192);
  myGLCD.print(UPDT_NOTES4, LEFT, 204);
  myGLCD.print(UPDT_NOTES5, LEFT, 216);
  myGLCD.drawRect(8, 154, 312, 232);

  delay(1000);

  //Set Loading Rect
  myGLCD.drawRect(79, 118, 241, 128);
  myGLCD.setColor(0, 255, 0);

  //Animate Loading
  delay(150);
  myGLCD.fillRect(80, 119, 96, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 112, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 128, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 144, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 160, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 176, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 192, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 208, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 224, 127);
  delay(150);
  myGLCD.fillRect(80, 119, 240, 127);

  //Tap Anywhere
  myGLCD.print("- TAP ANYWHERE TO START -", CENTER, 135);

  readyopen = true;
}
