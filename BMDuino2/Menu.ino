//##################################################################################

void ClearArea(int StartX, int StartY, int EndX, int EndY) {
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(StartX, StartY, EndX, EndY);
}

//##################################################################################

String ConvertProgIntToString(int Value, int Mode) {
  //MODE0 X&Y VALUE |||| 0=RPM | 1=mBar | 2=SPEED | 3=IAT | 4=ECT | 5=TPS
  //MODE1 LOG VALUE |||| 0=IAT | 1=ECT | 2=AFR | 3=BATT | 4=TPS | 5=IGN | 6=O2 | 7=CONSO | 8=SPEED
  if (Mode == 0) {
    if (Value == 0) {
      return "RPM";
    } else if (Value == 1) {
      return "mBar";
    } else if (Value == 2) {
      return "KM/H";
    } else if (Value == 3) {
      return "IAT";
    } else if (Value == 4) {
      return "ECT";
    } else if (Value == 5) {
      return "TPS";
    }
  } else if (Mode == 1) {
    if (Value == 0) {
      return "IAT";
    } else if (Value == 1) {
      return "ECT";
    } else if (Value == 2) {
      return "AFR";
    } else if (Value == 3) {
      return "BATT";
    } else if (Value == 4) {
      return "TPS";
    } else if (Value == 5) {
      return "IGN";
    } else if (Value == 6) {
      return "O2";
    } else if (Value == 7) {
      return "CONS.";
    } else if (Value == 8) {
      return "KM/H";
    }
  }
}

//##################################################################################

void SetPreset(int Preset) {
  //Prog_X_ID = 1;      //0=RPM | 1=mBar | 2=SPEED | 3=IAT | 4=ECT | 5=TPS
  //Prog_Y_ID = 0;      //0=RPM | 1=mBar | 2=SPEED | 3=IAT | 4=ECT | 5=TPS
  //Prog_Log_Value = 2; //0=IAT | 1=ECT | 2=AFR | 3=BATT | 4=TPS | 5=IGN | 6=O2 | 7=CONSO | 8=SPEED
    
  if (Preset == 1) {
    //Set Preset #1
    Prog_Rows = 20;
    Prog_Cols = 10;
    Prog_XMin = 114;
    Prog_XMax = 1035;
    Prog_YMin = 0;
    Prog_YMax = 9000;
    Prog_X_ID = 1;
    Prog_Y_ID = 0;
    Prog_Log_Value = 2;
  } else if (Preset == 2) {
    //Set Preset #2
    Prog_Rows = 20;
    Prog_Cols = 10;
    Prog_XMin = 114;
    Prog_XMax = 1035;
    Prog_YMin = 0;
    Prog_YMax = 9000;
    Prog_X_ID = 1;
    Prog_Y_ID = 0;
    Prog_Log_Value = 5;
  } else if (Preset == 3) {
    //Set Preset #3
    Prog_Rows = 20;
    Prog_Cols = 10;
    Prog_XMin = 114;
    Prog_XMax = 1035;
    Prog_YMin = 0;
    Prog_YMax = 9000;
    Prog_X_ID = 1;
    Prog_Y_ID = 0;
    Prog_Log_Value = 7;
  } else if (Preset == 4) {
    //Set Preset #4
    Prog_Rows = 20;
    Prog_Cols = 10;
    Prog_XMin = 40;
    Prog_XMax = 140;
    Prog_YMin = -40;
    Prog_YMax = 40;
    Prog_X_ID = 4;
    Prog_Y_ID = 3;
    Prog_Log_Value = 5;
  }
}

//##################################################################################

float GetBoardValue(int Mode) {
  //Mode1 = Log | Mode2 = XVal | Mode3 = YVal
  
  //Set Log Value
  if (Mode == 1) {
    if (Prog_Log_Value == 0) {
      return Display_IAT;
    } else if (Prog_Log_Value == 1) {
      return Display_ECT;
    } else if (Prog_Log_Value == 2) {
      return Display_AFR;
    } else if (Prog_Log_Value == 3) {
      return Display_BATT;
    } else if (Prog_Log_Value == 4) {
      return Display_TPS;
    } else if (Prog_Log_Value == 5) {
      return Display_IGN;
    } else if (Prog_Log_Value == 6) {
      return Display_O2;
    } else if (Prog_Log_Value == 7) {
      return Display_CONSO;
    } else if (Prog_Log_Value == 8) {
      return Display_Vss;
    }
  }

  //Set X Value
  if (Mode == 2) {
    if (Prog_X_ID == 0) {
      return Display_Rpm;
    } else if (Prog_X_ID == 1) {
      return Display_MAP;
    } else if (Prog_X_ID == 2) {
      return Display_Vss;
    } else if (Prog_X_ID == 3) {
      return Display_IAT;
    } else if (Prog_X_ID == 4) {
      return Display_ECT;
    } else if (Prog_X_ID == 5) {
      return Display_TPS;
    }
  }

  //Set Y Value
  if (Mode == 3) {
    if (Prog_Y_ID == 0) {
      return Display_Rpm;
    } else if (Prog_Y_ID == 1) {
      return Display_MAP;
    } else if (Prog_Y_ID == 2) {
      return Display_Vss;
    } else if (Prog_Y_ID == 3) {
      return Display_IAT;
    } else if (Prog_Y_ID == 4) {
      return Display_ECT;
    } else if (Prog_Y_ID == 5) {
      return Display_TPS;
    }
  }
}

//####################################################################

void PopIntSelectionMenu(int Current) {
  //Set Keypad Background
  myGLCD.setColor(55, 55, 55);
  myGLCD.fillRect(60, 120, 260, 210);

  //Set Keypad Rect
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(60, 120, 260, 210);

  //Hori Line
  myGLCD.drawLine(60, 143, 260, 143);
  myGLCD.drawLine(60, 165, 260, 165);
  myGLCD.drawLine(60, 188, 260, 188);

  //Verti Line
  myGLCD.drawLine(127, 120, 127, 210);
  myGLCD.drawLine(193, 120, 193, 210);

  //Set Text
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 255, 0);
  myGLCD.print("1", 86, 124);
  myGLCD.print("2", 154, 124);
  myGLCD.print("3", 220, 124);
  myGLCD.print("4", 86, 147);
  myGLCD.print("5", 154, 147);
  myGLCD.print("6", 220, 147);
  myGLCD.print("7", 86, 169);
  myGLCD.print("8", 154, 169);
  myGLCD.print("9", 220, 169);
  myGLCD.print("OK", 77, 192);
  myGLCD.print("0", 154, 192);
  myGLCD.print("<--", 202, 192);

  //Set Temp Value
  TempValue1 = Current;

  //Set Value Text
  SelectionMenuValText(Current);
}

//##################################################################################

void SelectionMenuValText(int Current) {
  myGLCD.setFont(BigFont);
  myGLCD.setColor(55, 55, 55);
  myGLCD.fillRect(100, 70, 220, 102);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(100, 70, 220, 102);
  myGLCD.setColor(255, 255, 0);
  myGLCD.printNumI(Current, CENTER, 80);
}

//####################################################################################################################################################################
//####################################################################################################################################################################

void PopStringSelectionMenu(int Current) {
  //Set Keypad Background
  myGLCD.setColor(55, 55, 55);
  myGLCD.fillRect(60, 120, 260, 210);

  //Set Keypad Rect
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(60, 120, 260, 210);

  //Hori Line
  myGLCD.drawLine(60, 143, 260, 143);
  myGLCD.drawLine(60, 165, 260, 165);
  myGLCD.drawLine(60, 188, 260, 188);

  //Verti Line
  myGLCD.drawLine(127, 120, 127, 210);
  myGLCD.drawLine(193, 120, 193, 210);

  //Set Text
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 0);

  //MODE0 X&Y VALUE |||| 0=RPM | 1=mBar | 2=SPEED | 3=IAT | 4=ECT | 5=TPS
  //MODE1 LOG VALUE |||| 0=IAT | 1=ECT | 2=AFR | 3=BATT | 4=TPS | 5=IGN | 6=O2 | 7=CONSO | 8=SPEED
  if (Prog_BoardMode == 0) {
    myGLCD.print("RPM", 80, 126);
    myGLCD.print("mBar", 144, 126);
    myGLCD.print("KM/H", 210, 126);
    myGLCD.print("IAT", 80, 149);
    myGLCD.print("ECT", 146, 149);
    myGLCD.print("TPS", 214, 149);
  } else if (Prog_BoardMode == 1) {
    myGLCD.print("IAT", 80, 126);
    myGLCD.print("ECT", 146, 126);
    myGLCD.print("AFR", 214, 126);
    myGLCD.print("BATT", 74, 149);
    myGLCD.print("TPS", 146, 149);
    myGLCD.print("IGN", 214, 149);
    myGLCD.print("O2", 82, 171);
    myGLCD.print("CONS.", 138, 171);
    myGLCD.print("KM/H", 210, 171);
  }
  myGLCD.setFont(BigFont);
  myGLCD.print("OK", 77, 192);

  //Set Temp Value
  TempValue1 = Current;

  //Set Value Text
  StringSelectionMenuValText(Current);
}

//##################################################################################

void StringSelectionMenuValText(int Current) {
  myGLCD.setFont(BigFont);
  myGLCD.setColor(55, 55, 55);
  myGLCD.fillRect(100, 70, 220, 102);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(100, 70, 220, 102);
  myGLCD.setColor(255, 255, 0);
  myGLCD.print(ConvertProgIntToString(Current, Prog_BoardMode), CENTER, 80);
}

//####################################################################################################################################################################
//####################################################################################################################################################################

void PopPresetSelectionMenu() {
  //Set Keypad Background
  myGLCD.setColor(55, 55, 55);
  myGLCD.fillRect(60, 120, 260, 210);

  //Set Keypad Rect
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(60, 120, 260, 210);

  //Hori Line
  myGLCD.drawLine(60, 143, 260, 143);
  myGLCD.drawLine(60, 165, 260, 165);
  myGLCD.drawLine(60, 188, 260, 188);

  //Set Text
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 0);
  myGLCD.print("1. RPM vs mBar --> AFR", 70, 126);
  myGLCD.print("2. RPM vs mBar --> IGN", 70, 149);
  myGLCD.print("3. RPM vs mBar --> CONS", 66, 171);
  myGLCD.print("4. IAT vs ECT --> AFR", 74, 192);
}
