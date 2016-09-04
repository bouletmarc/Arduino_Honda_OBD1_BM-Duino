void PopBoardDisplayTable() {
  //Set Values
  int CurrRows = 0;
  int CurrCols = 0;
  float LogFloat = GetBoardValue(1);
  float XValFloat = GetBoardValue(2);
  float YValFloat = GetBoardValue(3);
  Prog_LogFloatVal = false;
  Prog_XFloat = false;
  Prog_YFloat = false;

  //Set Log Float
  if (Prog_Log_Value >= 2 && Prog_Log_Value <= 7) {
    Prog_LogFloatVal = true;
  }

  //Set X Float
  if (Prog_Log_Value == 5) {
    Prog_XFloat = true;
  }

  //Set Y Float
  if (Prog_Log_Value == 5) {
    YValFloat = Display_TPS;
    Prog_YFloat = true;
  }

  //Get Rows Area
  for (int i=0; i <= Prog_Rows-1; i++){
    float Range = float(Prog_YMax - Prog_YMin);
    float Add = (Range/(Prog_Rows -1));
    float CurrVal = Prog_YMin + (Add * i);
    float MinVal = 0;
    float MaxVal = 0;
    //Set Min Val
    if (i == 0) {
      MinVal = -9999;
    } else {
      float LastVal = Prog_YMin + (Add * (i-1));
      MinVal = LastVal + ((CurrVal - LastVal)/2);
    }
    //Set Max Val
    if (i == Prog_Rows-1) {
      MaxVal = 9999;
    } else {
      float NextVal = Prog_YMin + (Add * (i+1));
      MaxVal = CurrVal + ((NextVal - CurrVal)/2);
    }
    //Set Current Rows
    if (YValFloat > MinVal && YValFloat <= MaxVal) {
      CurrRows = Prog_Rows - (i + 1);
    }
  }

  //Get Cols Area
  for (int i=0; i <= Prog_Cols-1; i++){
    float Range = float(Prog_XMax - Prog_XMin);
    float Add = (Range/(Prog_Cols -1));
    float CurrVal = Prog_XMin + (Add * i);
    float MinVal = 0;
    float MaxVal = 0;
    //Set Min Val
    if (i == 0) {
      MinVal = -9999;
    } else {
      float LastVal = Prog_XMin + (Add * (i-1));
      MinVal = LastVal + ((CurrVal - LastVal)/2);
    }
    //Set Max Val
    if (i == Prog_Cols-1) {
      MaxVal = 9999;
    } else {
      float NextVal = Prog_XMin + (Add * (i+1));
      MaxVal = CurrVal + ((NextVal - CurrVal)/2);
    }
    //Set Current Cols
    if (XValFloat > MinVal && XValFloat <= MaxVal) {
      CurrCols = i + 1;
    }
  }

  //Set the Value
  int XPos = 14;
  int YPos = 20;
  int TextXpos = (((300 / Prog_Cols) * CurrCols) + XPos) - 29;
  int TextYpos = (((200 / Prog_Rows) * CurrRows) + YPos);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(TextXpos, TextYpos, TextXpos + 30, TextYpos + 9);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont);
  if (Prog_LogFloatVal) {
    int Rounded = round(LogFloat * 10);
    String RoundedStr = String(Rounded);
    String UnRounded = String(round(Rounded / 10));
    String LastNumber = RoundedStr.substring(RoundedStr.length() - 1, RoundedStr.length());
    String EndStr = UnRounded + "." + LastNumber;
    myGLCD.print(EndStr, TextXpos, TextYpos);
  } else {
    myGLCD.print(String(int(ceil(LogFloat))), TextXpos, TextYpos);
  }

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
  myGLCD.drawRect(14, 20, 314, 220);
}
