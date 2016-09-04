void CheckForInput() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    TouchSomething = false;
  }
  
  while (myTouch.dataAvailable() == true && TouchSomething == false) {
    myTouch.read();
    long x = myTouch.getX();
    long y = myTouch.getY();

    if ((x!=-1) and (y!=-1)){
      //lcd_menu = 1 MainMenu
      //lcd_menu = 2 Programming
      //lcd_menu = 3 Display
      //lcd_menu = 4 Customize
      //lcd_menu = 5 BeeM*R
      //lcd_menu = 6 SelectionMenu (for Rpm, time, etc) #USED FOR BEEM*R VARIABLES
      //lcd_menu = 7 Board SelectionMenu (for X,Y Tables Values, etc)
      //lcd_menu = 8 SelectionMenu (for Rpm, time, etc) #USED FOR DATALOGGER BOARDS
      //lcd_menu = 9 SelectionMenu (for Log, X&Y, Str)  #USED FOR DATALOGGER BOARDS
      //lcd_menu = 10 Boards Diplays
      //lcd_menu = 11 Load Presets
      //####################  START MENU   #####################
      //Change From Start Menu to Main
      if (lcd_menu == 0 && readyopen) {
          lcd_menu = 1;
          PopMainMenu();
          TouchSomething = true;
      }
      //###################   MAIN MENU   #####################
      if (lcd_menu == 1) {
        //Change From Main To Display
        if (x > 40 && x < 280 && y > 50 && y < 80 && TouchSomething == false) {
            lcd_menu = 3;
            PopDisplayMenu();
            TouchSomething = true;
        }
        //Change From Main To Programming
        if (x > 40 && x < 280 && y > 90 && y < 120 && TouchSomething == false) {
            lcd_menu = 2;
            PopProgrammingMenu();
            TouchSomething = true;
        }
        //Change From Main To BeeM*R
        if (x > 40 && x < 280 && y > 130 && y < 160 && TouchSomething == false) {
            lcd_menu = 5;
            PopBeeMRMenu();
            TouchSomething = true;
        }
      }
      //##################   BACK BUTTON   ####################
      if (x > 0 && x < 44 && y > 220 && y <= 239 && lcd_menu >= 2  && lcd_menu != 6 && TouchSomething == false) {
          if (lcd_menu != 7) {
            //Go to Main Menu
            lcd_menu = 1;
            PopMainMenu();
          } else {
            //Got to Datalogger
            lcd_menu = 2;
            PopProgrammingMenu();
          }
          TouchSomething = true;
      }
      //################  DATALOGGER MODE SELECTION   ##################
      if (lcd_menu == 2) {
        //Pop Tables Selection
        if (x > 15 && x < 230 && y > 70 && y <= 100 && TouchSomething == false) {
            lcd_menu = 7;
            Prog_BoardType = 1;
            PopProgSelectionMenu();
            TouchSomething = true;
        }
        //Pop Graphics Selection
        if (x > 15 && x < 230 && y > 150 && y <= 180 && TouchSomething == false) {
            lcd_menu = 7;
            Prog_BoardType = 2;
            PopProgSelectionMenu();
            TouchSomething = true;
        }
      }
      //################  DATALOGGER SELECTION   ##################
      if (lcd_menu == 7) {
        //Pop Rows Selection
        if (x > 16 && x < 158 && y >= 52 && y <= 68 && TouchSomething == false) {
          lcd_menu = 8;
          if (Prog_BoardType == 1) {
            CurrentSelection = 10;
            PopIntSelectionMenu(Prog_Rows);
          } else {
            CurrentSelection = 14;
            PopIntSelectionMenu(Prog_YMin);
          }
          TouchSomething = true;
        }
        //Pop Cols Selection
        if (x > 16 && x < 158 && y >= 74 && y <= 90 && TouchSomething == false) {
          lcd_menu = 8;
          if (Prog_BoardType == 1) {
            CurrentSelection = 11;
            PopIntSelectionMenu(Prog_Cols);
          } else {
            CurrentSelection = 15;
            PopIntSelectionMenu(Prog_YMax);
          }
          TouchSomething = true;
        }
        //Pop Log Selection
        if (x > 162 && x < 304 && y >= 52 && y <= 68 && TouchSomething == false) {
          CurrentSelection = 16;
          lcd_menu = 9;
          Prog_BoardMode = 1;
          PopStringSelectionMenu(Prog_Log_Value);
          TouchSomething = true;
        }
        //Pop Board Display Menu
        if (x > 16 && x < 158 && y >= 186 && y <= 214 && TouchSomething == false) {
          lcd_menu = 10;
          PopBoardDisplayMenu();
          TouchSomething = true;
        }
        //TABLES BOARD SELECTION ONLY HERE
        if (Prog_BoardType == 1) {
          //Pop XMin Selection
          if (x > 16 && x < 158 && y >= 96 && y <= 112 && TouchSomething == false) {
            CurrentSelection = 12;
            lcd_menu = 8;
            PopIntSelectionMenu(Prog_XMin);
            TouchSomething = true;
          }
          //Pop XMax Selection
          if (x > 16 && x < 158 && y >= 116 && y <= 134 && TouchSomething == false) {
            CurrentSelection = 13;
            lcd_menu = 8;
            PopIntSelectionMenu(Prog_XMax);
            TouchSomething = true;
          }
          //Pop YMin Selection
          if (x > 16 && x < 158 && y >= 140 && y <= 156 && TouchSomething == false) {
            CurrentSelection = 14;
            lcd_menu = 8;
            PopIntSelectionMenu(Prog_YMin);
            TouchSomething = true;
          }
          //Pop YMax Selection
          if (x > 16 && x < 158 && y >= 162 && y <= 178 && TouchSomething == false) {
            CurrentSelection = 15;
            lcd_menu = 8;
            PopIntSelectionMenu(Prog_YMax);
            TouchSomething = true;
          }
          //Pop X Selection
          if (x > 162 && x < 304 && y >= 74 && y <= 90 && TouchSomething == false) {
            CurrentSelection = 17;
            lcd_menu = 9;
            Prog_BoardMode = 0;
            PopStringSelectionMenu(Prog_X_ID);
            TouchSomething = true;
          }
          //Pop Y Selection
          if (x > 162 && x < 304 && y >= 96 && y <= 112 && TouchSomething == false) {
            CurrentSelection = 18;
            lcd_menu = 9;
            Prog_BoardMode = 0;
            PopStringSelectionMenu(Prog_Y_ID);
            TouchSomething = true;
          }
          //Pop Load Preset Menu
          if (x > 162 && x < 304 && y >= 220 && y <= 239 && TouchSomething == false) {
            lcd_menu = 11;
            PopPresetSelectionMenu();
            TouchSomething = true;
          }
        }
      }
      //################  PRESET SELECTION   ##################
      if (lcd_menu == 11) {
        //Select#1
        if (x > 60 && x < 260 && y >= 120 && y <= 142 && TouchSomething == false) {
          lcd_menu = 7;
          SetPreset(1);
          PopProgSelectionMenu();
          TouchSomething = true;
        }
        //Select#2
        if (x > 60 && x < 260 && y >= 144 && y <= 164 && TouchSomething == false) {
          lcd_menu = 7;
          SetPreset(2);
          PopProgSelectionMenu();
          TouchSomething = true;
        }
        //Select#3
        if (x > 60 && x < 260 && y >= 166 && y <= 187 && TouchSomething == false) {
          lcd_menu = 7;
          SetPreset(3);
          PopProgSelectionMenu();
          TouchSomething = true;
        }
        //Select#4
        if (x > 60 && x < 260 && y >= 189 && y <= 210 && TouchSomething == false) {
          lcd_menu = 7;
          SetPreset(4);
          PopProgSelectionMenu();
          TouchSomething = true;
        }
      }
      //################  BeeM*R OPTIONS   ##################
      //Disable or Enable Launch Control
      if (lcd_menu == 5) {
        //Disable or Enable BeeM*R
        if (x > 12 && x < 80 && y > 56 && y <= 70 && TouchSomething == false) {
            if (BeeMREnabled) {
              BeeMREnabled = false;
            } else {
              BeeMREnabled = true;
            }
            PopBeeMRMenu();
            TouchSomething = true;
        }
        if (BeeMREnabled) {
          //Disable or Enable Launch Control
          if (x > 12 && x < 145 && y > 76 && y <= 90 && TouchSomething == false) {
              if (BeeMRLaunchEnabled) {
                BeeMRLaunchEnabled = false;
              } else {
                BeeMRLaunchEnabled = true;
              }
              PopBeeMRMenu();
              TouchSomething = true;
          }
          //Change BeeM*R Mode
          if (x > 110 && x < 308 && y > 56 && y <= 70 && TouchSomething == false) {
              if (BeeMRMode == 0) {
                BeeMRMode = 1;
              } else {
                BeeMRMode = 0;
              }
              PopBeeMRMenu();
              TouchSomething = true;
          }
        }
      }
      //################  BeeM*R SELECTION   ##################
      if (lcd_menu == 5 && BeeMREnabled) {
        //Pop Vss Selection
        if (x > 149 && x < 308 && y > 76 && y <= 90 && BeeMRLaunchEnabled && TouchSomething == false) {
            CurrentSelection = 1;
            lcd_menu = 6;
            PopIntSelectionMenu(BeeMRLaunchVSS);
            TouchSomething = true;
        }
        //Pop Limiter Selection
        if (x > 12 && x < 160 && y > 102 && y <= 116 && TouchSomething == false) {
            CurrentSelection = 2;
            lcd_menu = 6;
            PopIntSelectionMenu(BeeMRRevRPM);
            TouchSomething = true;
        }
        //Pop Launch Selection
        if (x > 164 && x < 308 && y > 102 && y <= 116 && BeeMRLaunchEnabled && TouchSomething == false) {
            CurrentSelection = 3;
            lcd_menu = 6;
            PopIntSelectionMenu(BeeMRLaunchRPM);
            TouchSomething = true;
        }
        //BEEMR MODE0 AND MODE1 OPTIONS
        if (BeeMRMode == 0) {
          //Pop Limiter Time Selection
          if (x > 12 && x < 218 && y > 120 && y <= 134 && TouchSomething == false) {
              CurrentSelection = 4;
              lcd_menu = 6;
              PopIntSelectionMenu(BeeMRRevCutTime);
              TouchSomething = true;
          }
          //Pop Launch Time Selection
          if (x > 12 && x < 210 && y > 138 && y <= 152 && BeeMRLaunchEnabled && TouchSomething == false) {
              CurrentSelection = 5;
              lcd_menu = 6;
              PopIntSelectionMenu(BeeMRLaunchCutTime);
              TouchSomething = true;
          }
        } else if (BeeMRMode == 1) {
          //Pop Limiter Cut Selection
          if (x > 12 && x < 220 && y > 120 && y <= 134 && TouchSomething == false) {
              CurrentSelection = 6;
              lcd_menu = 6;
              PopIntSelectionMenu(BeeMRRevCutRPM);
              TouchSomething = true;
          }
          //Pop Launch Cut Selection
          if (x > 12 && x < 212 && y > 138 && y <= 152 && BeeMRLaunchEnabled && TouchSomething == false) {
              CurrentSelection = 7;
              lcd_menu = 6;
              PopIntSelectionMenu(BeeMRLaunchCutRPM);
              TouchSomething = true;
          }
        }
      }
      //################  SELECTION MENU   ##################
      if (lcd_menu == 6 | lcd_menu == 8 | lcd_menu == 9) {
        //Select #1
        if (x > 60 && x < 126 && y > 120 && y <= 142) {
          if (lcd_menu != 9) {
            TempValue1 = (TempValue1 * 10) + 1;
            SelectionMenuValText(TempValue1);
          } else {
            TempValue1 = 0;
            StringSelectionMenuValText(TempValue1);
          }
          TouchSomething = true;
        }
        //Select #2
        if (x > 129 && x < 192 && y > 120 && y <= 142) {
          if (lcd_menu != 9) {
            TempValue1 = (TempValue1 * 10) + 2;
            SelectionMenuValText(TempValue1);
          } else {
            TempValue1 = 1;
            StringSelectionMenuValText(TempValue1);
          }
          TouchSomething = true;
        }
        //Select #3
        if (x > 194 && x < 260 && y > 120 && y <= 142) {
          if (lcd_menu != 9) {
            TempValue1 = (TempValue1 * 10) + 3;
            SelectionMenuValText(TempValue1);
          } else {
            TempValue1 = 2;
            StringSelectionMenuValText(TempValue1);
          }
          TouchSomething = true;
        }
        //Select #4
        if (x > 60 && x < 126 && y > 144 && y <= 164) {
          if (lcd_menu != 9) {
            TempValue1 = (TempValue1 * 10) + 4;
            SelectionMenuValText(TempValue1);
          } else {
            TempValue1 = 3;
            StringSelectionMenuValText(TempValue1);
          }
          TouchSomething = true;
        }
        //Select #5
        if (x > 129 && x < 192 && y > 144 && y <= 164) {
          if (lcd_menu != 9) {
            TempValue1 = (TempValue1 * 10) + 5;
            SelectionMenuValText(TempValue1);
          } else {
            TempValue1 = 4;
            StringSelectionMenuValText(TempValue1);
          }
          TouchSomething = true;
        }
        //Select #6
        if (x > 194 && x < 260 && y > 144 && y <= 164) {
          if (lcd_menu != 9) {
            TempValue1 = (TempValue1 * 10) + 6;
            SelectionMenuValText(TempValue1);
          } else {
            TempValue1 = 5;
            StringSelectionMenuValText(TempValue1);
          }
          TouchSomething = true;
        }
        //DONT SELECT #7 to #0 while in certain string Menu (datalogger X&Y menu)
        if (CurrentSelection != 17  && CurrentSelection != 18) {
          //Select #7
          if (x > 60 && x < 126 && y > 166 && y <= 187) {
            if (lcd_menu != 9) {
              TempValue1 = (TempValue1 * 10) + 7;
              SelectionMenuValText(TempValue1);
            } else {
              TempValue1 = 6;
              StringSelectionMenuValText(TempValue1);
            }
            TouchSomething = true;
          }
          //Select #8
          if (x > 129 && x < 192 && y > 166 && y <= 187) {
            if (lcd_menu != 9) {
              TempValue1 = (TempValue1 * 10) + 8;
              SelectionMenuValText(TempValue1);
            } else {
              TempValue1 = 7;
              StringSelectionMenuValText(TempValue1);
            }
            TouchSomething = true;
          }
          //Select #9
          if (x > 194 && x < 260 && y > 166 && y <= 187) {
            if (lcd_menu != 9) {
              TempValue1 = (TempValue1 * 10) + 9;
              SelectionMenuValText(TempValue1);
            } else {
              TempValue1 = 8;
              StringSelectionMenuValText(TempValue1);
            }
            TouchSomething = true;
          }
          //Select #0
          if (x > 129 && x < 192 && y > 189 && y <= 210) {
            TempValue1 = (TempValue1 * 10);
            SelectionMenuValText(TempValue1);
            TouchSomething = true;
          }
          //Select <--
          if (x > 194 && x < 260 && y > 189 && y <= 210) {
            TempValue1 = 0;
            SelectionMenuValText(TempValue1);
            TouchSomething = true;
          }
        }
        //Select OK
        if (x > 60 && x < 126 && y > 189 && y <= 210) {
          //Set BeeM*R Menu Value
          if (lcd_menu == 6) {
            if (CurrentSelection == 1) {
              BeeMRLaunchVSS = TempValue1;
            } else if (CurrentSelection == 2) {
              BeeMRRevRPM = TempValue1;
            } else if (CurrentSelection == 3) {
              BeeMRLaunchRPM = TempValue1;
            } else if (CurrentSelection == 4) {
              BeeMRRevCutTime = TempValue1;
            } else if (CurrentSelection == 5) {
              BeeMRLaunchCutTime = TempValue1;
            } else if (CurrentSelection == 6) {
              BeeMRRevCutRPM = TempValue1;
            } else if (CurrentSelection == 7) {
              BeeMRLaunchCutRPM = TempValue1;
            }
            //Return Back to BeeM*R Menu
            lcd_menu = 5;
            PopBeeMRMenu();
          }
          //Set Datalogger Int Menu Value
          if (lcd_menu == 8) {
            if (CurrentSelection == 10) {
              Prog_Rows = TempValue1;
            } else if (CurrentSelection == 11) {
              Prog_Cols = TempValue1;
            } else if (CurrentSelection == 12) {
              Prog_XMin = TempValue1;
            } else if (CurrentSelection == 13) {
              Prog_XMax = TempValue1;
            } else if (CurrentSelection == 14) {
              Prog_YMin = TempValue1;
            } else if (CurrentSelection == 15) {
              Prog_YMax = TempValue1;
            }
            //Return Back to Board Menu
            lcd_menu = 7;
            PopProgSelectionMenu();
          }
          //Set Datalogger String Menu Value
          if (lcd_menu == 9) {
            if (CurrentSelection == 16) {
              Prog_Log_Value = TempValue1;
            } else if (CurrentSelection == 17) {
              Prog_X_ID = TempValue1;
            } else if (CurrentSelection == 18) {
              Prog_Y_ID = TempValue1;
            }
            //Return Back to Board Menu
            lcd_menu = 7;
            PopProgSelectionMenu();
          }
          TouchSomething = true;
        }
      }
    }

    //Set Timer for Touch Something
    if (TouchSomething) {
      previousMillis = currentMillis;
    }
  }
}
