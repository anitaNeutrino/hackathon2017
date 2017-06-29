{
  /* Load all the ANITA stuff when ROOT is run automatically */ 
  gSystem->Load("${ANITA_UTIL_INSTALL_DIR}/lib/libRootFftwWrapper.so") && gSystem->Load("$ANITA_UTIL_INSTALL_DIR/lib/libRootFftwWrapper.dylib");
  gSystem->Load("${ANITA_UTIL_INSTALL_DIR}/lib/libAnitaEvent.so") && gSystem->Load("$ANITA_UTIL_INSTALL_DIR/lib/libAnitaEvent.dylib"); 
  gSystem->Load("${ANITA_UTIL_INSTALL_DIR}/lib/libAnitaCorrelator.so") && gSystem->Load("$ANITA_UTIL_INSTALL_DIR/lib/libAnitaCorrelator.dylib"); 
  gSystem->Load("${ANITA_UTIL_INSTALL_DIR}/lib/libAnitaAnalysis.so") && gSystem->Load("$ANITA_UTIL_INSTALL_DIR/lib/libAnitaAnalysis.dylib"); 
  gSystem->Load("${ANITA_UTIL_INSTALL_DIR}/lib/libUCorrelator.so") && gSystem->Load("$ANITA_UTIL_INSTALL_DIR/lib/libUCorrelator.dylib"); 
 

  /** prettier plots */ 
  gStyle->SetNumberContours(255);
  gStyle->SetPalette(kTemperatureMap);
}
