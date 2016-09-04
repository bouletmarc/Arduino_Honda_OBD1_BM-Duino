//#################################################################
//#################################################################
//#################################################################
//File Writer (set string values to a certain file)
/*
void SetFileValues(String FileName, String FileVal) {
  //Load File
  LoadFileQuick(FileName);

  //Write File
  LoadedFile.print(FileVal);

  //Close File
  CloseFile();
}

//#################################################################
//#################################################################
//#################################################################
//File Loading Manager (also Close)

void LoadFileQuick(String FileName) {
  LoadedFile.open(FileName, O_RDWR | O_CREAT | O_AT_END);
  //LoadedFile.open(SDFolder + "/" + FileName, O_RDWR);
}

void LoadFile(String FileName) {
  //Set File
  LoadedFile.open(SDFolder + "/" + FileName, O_RDWR);

  //Set Internal Vars
  int LinesNumber = GetLinesNumber();
  CurrentStringCheck = LoadedFile.readString();

  //Lines Loop
  for (int i=1; i <= LinesNumber; i++){
    //Get Line String
    CurrentLineCheck = GetLineFromString(CurrentStringCheck);

    //Set Removal Line for Later
    String Removal = CurrentLineCheck;
    
    //Get Separator Distance
    int DistanceSeparator = GetSeparatorDistance(CurrentLineCheck);

    if (DistanceSeparator >= 2) {
      String StringName = GetStringName(CurrentLineCheck, DistanceSeparator);
      String StringVal = GetStringVal(CurrentLineCheck);

      //Set Valuse
      SetLoadingValues(StringName, StringVal);
      
      //Remove Current Line
      int RemoveInt = Removal.length();
      CurrentStringCheck = CurrentStringCheck.substring(1, RemoveInt + 2);
    } else {
      //Send Error
      
    }
  }

  //Close (Finished to load, no more needed)
  LoadedFile.close();
}

void CloseFile() {
  LoadedFile.close();
}

//#################################################################
//#################################################################
//#################################################################
//Files String Loading Functions

int GetLinesNumber () {
  String ThisString = LoadedFile.readString();
  int StringLength = ThisString.length();
  int LineNumber = 1;
  for (int CharInt=1; CharInt <= StringLength; CharInt++){
    //Get Char
    char CurrentChar = ThisString.charAt(CharInt);
    //Separator Found
    if (CurrentChar == '\n') {
      LineNumber ++;
    }
  }

  return LineNumber;
}

int GetNewLineDistance (String ThisString) {
  int LineLength = ThisString.length();
  for (int CharInt=1; CharInt <= LineLength; CharInt++){
    //Get Char
    char CurrentChar = ThisString.charAt(CharInt);
    //Separator Found
    if (CurrentChar == '\n') {
      return CharInt;
    }
    //no newline found
    if (CharInt == LineLength && CurrentChar != '\n') {
      return 0;
    }
  }
}

int GetSeparatorDistance (String ThisString) {
  int LineLength = ThisString.length();
  for (int CharInt=1; CharInt <= LineLength; CharInt++){
    //Get Char
    String CurrentChar = (String)ThisString.charAt(CharInt);
    //Separator Found
    if (CurrentChar == ";") {
      return CharInt;
    }
    //Line Error Format, no separator found
    if (CharInt == LineLength && CurrentChar != ";") {
      return 0;
    }
  }
}

String GetLineFromString (String ThisString) {
    //Get Distance From NewLine
    char CurrentLineChar;
    int DistanceNewline = GetNewLineDistance(ThisString);
    
    //Set Line Char
    if (DistanceNewline != 0) {
      for (int CharInt=1; CharInt < DistanceNewline; CharInt++){
        CurrentLineChar += CurrentStringCheck.charAt(CharInt);
      }
    } else {
      for (int CharInt=1; CharInt <= CurrentStringCheck.length(); CharInt++){
        CurrentLineChar += CurrentStringCheck.charAt(CharInt);
      }
    }

    return (String)CurrentLineChar;
}

String GetStringName (String ThisString, int DistanceSeparator) {
  char CurrentLineChar;

  //Set Line Char
  for (int CharInt=1; CharInt < DistanceSeparator; CharInt++){
     CurrentLineChar += CurrentStringCheck.charAt(CharInt);
  }

  String ThisName = (String)CurrentLineChar;

  //Remove This Result for next String Check
  CurrentLineCheck = CurrentLineCheck.substring(1, DistanceSeparator + 1);

  return ThisName;
}

String GetStringVal (String ThisString) {
  char CurrentLineChar;
  int LineLength = ThisString.length();

  //Set Line Char
  for (int CharInt=1; CharInt <= LineLength; CharInt++){
     CurrentLineChar += CurrentStringCheck.charAt(CharInt);
  }

  return (String)CurrentLineChar;
}

//#################################################################
//#################################################################
//#################################################################
//Check Load Or Make File

void CheckForFiles(String FileName) {
  if(sd.exists(FileName)) {
    LoadFile(FileName);
  } else {
    MakeFile(FileName);
  }
}

void MakeFile(String FileName) {
  //Load File
  LoadFileQuick(FileName);

  //Set Initial Values (Write File)
  if (FileName == "LOG.txt") {
    LoadedFile.print("");
  } else if (FileName == "MENU_Settings.txt") {
    LoadedFile.print("");
  } else if (FileName == "OBD_Settings.txt") {
    LoadedFile.print("");
  } else if (FileName == "OBD_Tables.txt") {
    LoadedFile.print("");
  } else if (FileName == "OBD_BeeMR.txt") {
    LoadedFile.print("");
  }// else if (FileName == ".txt") {
   // LoadedFile.print("");
  //}

  //Close File
  CloseFile();
}

//#################################################################
//#################################################################
//#################################################################

void SetLoadingValues(String StringName, String StringVal) {
  if (StringName = "") {
    
  }
}
*/
