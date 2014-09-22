{
  gROOT->ProcessLine(".L libTools.so");
  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch1 = new TChain("Events"); 
  ch1->Add("NEWMIXINGFILES");
  ScanChain(ch1, "newMixing_hists.root"); 

  TChain *ch2 = new TChain("Events"); 
  ch2->Add("OLDMIXINGFILES");
  ScanChain(ch2, "oldMixing_hists.root"); 
}
