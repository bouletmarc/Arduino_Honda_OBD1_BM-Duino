// Set Update Notes
String VERSION      = "v1.2.2";
String UPDT_NOTES1  = "  -Dual Relays Output";
String UPDT_NOTES2  = "  -More Outputs";
String UPDT_NOTES3  = "  -Better Inputting";
String UPDT_NOTES4  = "  -Better BeeMR";
String UPDT_NOTES5  = "  -Faster Start Menu";

String SetVersionInfos() {
  return VERSION;
}

String SetUpdateInfos(String Current) {
  if (Current == "Note1") {
    return UPDT_NOTES1;
  } else if (Current == "Note2") {
    return UPDT_NOTES2;
  } else if (Current == "Note3") {
    return UPDT_NOTES3;
  } else if (Current == "Note4") {
    return UPDT_NOTES4;
  } else if (Current == "Note5") {
    return UPDT_NOTES5;
  }
}
