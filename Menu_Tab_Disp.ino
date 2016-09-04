//##################################################################################

void PopProgrammingMenu() {
  //Clear
  myGLCD.clrScr();

  //Set Itinial Values
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(0, 0, 0);

  //Title
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("DATALOGGER", CENTER, 18);

  //Set Display Rect
  myGLCD.drawRect(15, 70, 230, 100);
  myGLCD.drawRect(15, 150, 230, 180);

  //Set Options
  myGLCD.setColor(0, 255, 0);
  myGLCD.print("TABLES BOARD", 27, 77);
  myGLCD.print("GRAPHIC BOARD", 19, 157);

  //Draw Table Boards
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(250, 60, 300, 110);
  
  myGLCD.drawLine(250, 70, 300, 70);
  myGLCD.drawLine(250, 80, 300, 80);
  myGLCD.drawLine(250, 90, 300, 90);
  myGLCD.drawLine(250, 100, 300, 100);

  myGLCD.drawLine(260, 60, 260, 110);
  myGLCD.drawLine(270, 60, 270, 110);
  myGLCD.drawLine(280, 60, 280, 110);
  myGLCD.drawLine(290, 60, 290, 110);

  //Draw Graphics Boards
  myGLCD.setColor(55, 55, 55);
  myGLCD.drawLine(250, 160, 300, 160);
  myGLCD.drawLine(275, 130, 275, 190);
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawLine(250, 185, 255, 180);
  myGLCD.drawLine(255, 180, 260, 170);
  myGLCD.drawLine(260, 170, 265, 150);
  myGLCD.drawLine(265, 150, 270, 135);
  myGLCD.drawLine(270, 135, 275, 155);
  myGLCD.drawLine(275, 155, 280, 160);
  myGLCD.drawLine(280, 160, 285, 150);
  myGLCD.drawLine(285, 150, 290, 175);
  myGLCD.drawLine(290, 175, 295, 185);
  myGLCD.drawLine(295, 185, 300, 189);

  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(250, 130, 300, 190);

  //Back Button
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont);
  myGLCD.drawRect(0, 220, 44, 239);
  myGLCD.print("BACK", 6, 224);
}

//##################################################################################

void PopProgSelectionMenu() {
  //Clear
  myGLCD.clrScr();

  //Title
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("SET BOARD SETTINGS", CENTER, 18);

  //Reset Variables (Board#2 Graphics)
  if (Prog_BoardType == 2) {
    Prog_XMin = 0;
    Prog_XMax = 30;
  }

  //Set Display Rect
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(16, 52, 158, 68);
  myGLCD.drawRect(16, 74, 158, 90);
  if (Prog_BoardType == 1) {
    myGLCD.drawRect(16, 96, 158, 112);
    myGLCD.drawRect(16, 116, 158, 134);
    myGLCD.drawRect(16, 140, 158, 156);
    myGLCD.drawRect(16, 162, 158, 178);
  }
  myGLCD.drawRect(162, 52, 304, 68);
  if (Prog_BoardType == 1) {
    myGLCD.drawRect(162, 74, 304, 90);
    myGLCD.drawRect(162, 96, 304, 112);
    myGLCD.drawRect(162, 220, 304, 239);
  }

  //Set Options
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  if (Prog_BoardType == 1) {
    myGLCD.print("Rows", 18, 54);
    myGLCD.print("Cols", 18, 76);
    myGLCD.print("XMin", 18, 98);
    myGLCD.print("XMax", 18, 120);
    myGLCD.print("YMin", 18, 142);
    myGLCD.print("YMax", 18, 164);
  } else {
    myGLCD.print("YMin", 18, 54);
    myGLCD.print("YMax", 18, 76);
  }
  
  myGLCD.print("Log", 164, 54);
  if (Prog_BoardType == 1) {
    myGLCD.print("X", 164, 76);
    myGLCD.print("Y", 164, 98);
    myGLCD.print("LOAD PRESET", 190, 224);
  }

  //Set Open
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(16, 186, 158, 214);
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 255, 0);
  myGLCD.print("OPEN", 50, 192);

  //Set Board
  myGLCD.setColor(55, 55, 55);
  myGLCD.drawLine(220, 160, 300, 160);
  myGLCD.drawLine(260, 120, 260, 200);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(220, 120, 300, 200);

  //Set Text
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 0);
  if (Prog_BoardType == 1) {
    myGLCD.printNumI(Prog_Rows, 72, 54);
    myGLCD.printNumI(Prog_Cols, 72, 76);
    myGLCD.printNumI(Prog_XMin, 72, 98);
    myGLCD.printNumI(Prog_XMax, 72, 120);
    myGLCD.printNumI(Prog_YMin, 72, 142);
    myGLCD.printNumI(Prog_YMax, 72, 164);
  } else {
    myGLCD.printNumI(Prog_YMin, 72, 54);
    myGLCD.printNumI(Prog_YMax, 72, 76);
  }
  myGLCD.print(ConvertProgIntToString(Prog_Log_Value, 1), 214, 54);
  if (Prog_BoardType == 1) {
    myGLCD.print(ConvertProgIntToString(Prog_X_ID, 0), 214, 76);
    myGLCD.print(ConvertProgIntToString(Prog_Y_ID, 0), 214, 98);
  }

  //Set Board Text
  if (Prog_BoardType == 1) {
    myGLCD.print(ConvertProgIntToString(Prog_X_ID, 0), 246, 204);
    myGLCD.print(ConvertProgIntToString(Prog_Y_ID, 0), 206, 173, -90);
    myGLCD.print(ConvertProgIntToString(Prog_Log_Value, 1) + "=?", 165, 200);
  } else {
    myGLCD.print("Time", 246, 204);
    myGLCD.print(ConvertProgIntToString(Prog_Log_Value, 1), 206, 173, -90);
  }

  //Back Button
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont);
  myGLCD.drawRect(0, 220, 44, 239);
  myGLCD.print("BACK", 6, 224);
}

//####################################################################################################################################################################
//####################################################################################################################################################################

void PopBoardDisplayMenu() {
  //Clear
  myGLCD.clrScr();

  //Reset Variables
  Prog_NextUpdate = 0;

  //Title
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 140, 0);
  myGLCD.print("BOARD DISPLAY", CENTER, 4);

  //Set X&Y Name
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  if (Prog_BoardType == 1) {
    myGLCD.print(ConvertProgIntToString(Prog_X_ID, 0), CENTER, 224);
    myGLCD.print(ConvertProgIntToString(Prog_Y_ID, 0), 0, 130, -90);
  } else {
    myGLCD.print("Time (sec)", CENTER, 224);
    myGLCD.print(ConvertProgIntToString(Prog_Log_Value, 1), 0, 130, -90);
  }

  //Set Min and Max Text
  myGLCD.setColor(255, 255, 0);
  myGLCD.printNumI(Prog_YMin, 0, 210);
  myGLCD.printNumI(Prog_YMax, 0, 10);
  myGLCD.printNumI(Prog_XMin, 46, 224);
  myGLCD.printNumI(Prog_XMax, 282, 224);

  int XPos = 14;
  int YPos = 20;
  //Size X = 300
  //Size Y = 200

  //Set Middle Lines
  if (Prog_BoardType == 1) {
    myGLCD.setColor(255, 255, 255);
    for (int i=1; i <= Prog_Rows-1; i++){
      int RowYpos = ((200 / Prog_Rows) * i) + YPos;
      myGLCD.drawLine(14, RowYpos, 314, RowYpos);
    }
    for (int i=1; i <= Prog_Cols-1; i++){
      int ColXpos = ((300 / Prog_Cols) * i) + XPos;
      myGLCD.drawLine(ColXpos, 20, ColXpos, 220);
    }
  }

  //Draw Background Rect
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(14, 20, 314, 220);

  //Back Button
  myGLCD.setFont(SmallFont);
  myGLCD.drawRect(0, 220, 44, 239);
  myGLCD.print("BACK", 6, 224);
}
