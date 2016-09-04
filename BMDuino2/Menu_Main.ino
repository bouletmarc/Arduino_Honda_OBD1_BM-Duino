void PopMainMenu() {
  //Clear
   myGLCD.clrScr();

  //Set Itinial Values
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(0, 0, 0);

  //Title
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("MAIN MENU", CENTER, 18);

  //Set Display Rect
   myGLCD.drawRect(40, 50, 280, 80);
   myGLCD.drawRect(40, 90, 280, 120);
   myGLCD.drawRect(40, 130, 280, 160);
   myGLCD.drawRect(40, 170, 280, 200);

  //Set Options
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("Displays", CENTER, 57);
  myGLCD.print("Datalogger", CENTER, 97);
  myGLCD.print("BeeM*R", CENTER, 137);
  myGLCD.print("Customize", CENTER, 177);

  String VERSION = SetVersionInfos();

  //Set Bottom Desc
  myGLCD.setFont(SmallFont);
  myGLCD.print("BM-Duino " + VERSION, 8, 228);
  myGLCD.print("By Bouletmarc", 210, 228);
}
