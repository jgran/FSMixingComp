// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"

// TR
#include "TR.h"
#include "tools.h"

using namespace std;
using namespace tas;

int ScanChain( TChain* chain, string fileName){

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  TFile* f = new TFile(Form("%s", fileName.c_str()), "RECREATE");

  TH1F *h_pfmet = new TH1F("h_pfmet", "h_pfmet", 15,0,150);
  TH1F *h_pfmet_phi = new TH1F("h_pfmet_phi", "h_pfmet_phi", 70,-3.5,3.5);
  TH1F *h_pfsumet = new TH1F("h_pfsumet", "h_pfsumet", 50,0,2500);
  TH1F *h_calotower_eta = new TH1F("h_calotower_eta", "h_calotower_eta", 120,-6,6);
  TH1F *h_calotower_phi = new TH1F("h_calotower_phi", "h_calotower_phi", 70,-3.5,3.5);
  TH1F *h_calotower_emEnergy = new TH1F("h_calotower_emEnergy", "h_calotower_emEnergy", 25,-100,150);
  TH1F *h_calotower_emEt = new TH1F("h_calotower_emEt", "h_calotower_emEt", 30,-10,20);
  TH1F *h_calotower_hadEnergy = new TH1F("h_calotower_hadEnergy", "h_calotower_hadEnergy", 15,0,150);
  TH1F *h_calotower_hadEt = new TH1F("h_calotower_hadEt", "h_calotower_hadEt", 10,0,10);
  TH1F *h_npfjets = new TH1F("h_npfjets", "h_npfjets", 15,0,150);
  TH1F *h_pfjet_eta = new TH1F("h_pfjet_eta", "h_pfjet_eta", 120,-6,6);
  TH1F *h_pfjet_phi = new TH1F("h_pfjet_phi", "h_pfjet_phi", 70,-3.5,3.5);
  TH1F *h_pfjet_pt = new TH1F("h_pfjet_pt", "h_pfjet_pt", 25,0,50);
  TH1F *h_npfjets_pt20 = new TH1F("h_npfjets_pt20", "h_npfjets_pt20", 10,0,10);
  TH1F *h_pfjet_pt20_eta = new TH1F("h_pfjet_pt20_eta", "h_pfjet_pt20_eta", 120,-6,6);
  TH1F *h_pfjet_pt20_phi = new TH1F("h_pfjet_pt20_phi", "h_pfjet_pt20_phi", 70,-3.5,3.5);
  TH1F *h_pfjet_pt20_pt = new TH1F("h_pfjet_pt20_pt", "h_pfjet_pt20_pt", 15,0,150);
  TH1F *h_track_eta = new TH1F("h_track_eta", "h_track_eta", 120,-6,6);
  TH1F *h_track_phi = new TH1F("h_track_phi", "h_track_phi", 70,-3.5,3.5);
  TH1F *h_track_pt = new TH1F("h_track_pt", "h_track_pt", 20,0,20);
  TH1F *h_track_pt10_eta = new TH1F("h_track_pt10_eta", "h_track_pt10_eta", 120,-6,6);
  TH1F *h_track_pt10_phi = new TH1F("h_track_pt10_phi", "h_track_pt10_phi", 70,-3.5,3.5);
  TH1F *h_track_pt10_pt = new TH1F("h_track_pt10_pt", "h_track_pt10_pt", 30,0,30);
  TH1F *h_puInfo_trueNumInteractions = new TH1F("h_puInfo_trueNumInteractions", "h_puInfo_trueNumInteractions", 70,0,70);
  TH1F *h_puInfo_nPUvertices = new TH1F("h_puInfo_nPUvertices", "h_puInfo_nPUvertices", 70,0,70);
  TH1F *h_n_pf_ch = new TH1F("h_n_pf_ch", "h_n_pf_ch", 30,0,1500);
  TH1F *h_n_pf_gamma = new TH1F("h_n_pf_gamma", "h_n_pf_gamma", 50,0,500);
  TH1F *h_n_pf_mu = new TH1F("h_n_pf_mu", "h_n_pf_mu", 5,0,5);
  TH1F *h_n_pf_nh = new TH1F("h_n_pf_nh", "h_n_pf_nh", 70,0,70);
  TH1F *h_ntowers = new TH1F("h_ntowers", "h_ntowers", 200,0,2000);
  TH1F *h_ntracks = new TH1F("h_ntracks", "h_ntracks", 150,0,1500);
  TH1F *h_ntracks_pt1 = new TH1F("h_ntracks_pt1", "h_ntracks_pt1", 40,0,400);
  TH1F *h_ntracks_pt5 = new TH1F("h_ntracks_pt5", "h_ntracks_pt5", 10,0,10);
  TH1F *h_ntracks_pt10 = new TH1F("h_ntracks_pt10", "h_ntracks_pt10", 5,0,5);
  TH1F *h_nvertices = new TH1F("h_nvertices", "h_nvertices", 50,0,50);

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("Events");
    TTreeCache::SetLearnEntries(10);
    tree->SetCacheSize(128*1024*1024);
    tr.Init(tree);
    
    // Loop over Events in current file
    if( nEventsTotal >= nEventsChain ) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
    
      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      tree->LoadTree(event);
      tr.GetEntry(event);
      ++nEventsTotal;
    
      // Progress
      TR::progress( nEventsTotal, nEventsChain );

      tools::Fill1D(h_pfmet, tr.pfmet(), 1.0);
      tools::Fill1D(h_pfmet_phi, tr.pfmet_phi(), 1.0);
      tools::Fill1D(h_pfsumet, tr.pfsumet(), 1.0);
      for(unsigned int i=0; i<tr.calotower_eta().size(); i++){
        tools::Fill1D(h_calotower_eta, tr.calotower_eta().at(i), 1.0);
        tools::Fill1D(h_calotower_phi, tr.calotower_phi().at(i), 1.0);
        tools::Fill1D(h_calotower_emEnergy, tr.calotower_emEnergy().at(i), 1.0);
        tools::Fill1D(h_calotower_emEt, tr.calotower_emEt().at(i), 1.0);
        tools::Fill1D(h_calotower_hadEnergy, tr.calotower_hadEnergy().at(i), 1.0);
        tools::Fill1D(h_calotower_hadEt, tr.calotower_hadEt().at(i), 1.0);
      }
      tools::Fill1D(h_npfjets, tr.npfjets(), 1.0);
      for(unsigned int i=0; i<tr.pfjet_eta().size(); i++){
        tools::Fill1D(h_pfjet_eta, tr.pfjet_eta().at(i), 1.0);
        tools::Fill1D(h_pfjet_phi, tr.pfjet_phi().at(i), 1.0);
        tools::Fill1D(h_pfjet_pt, tr.pfjet_pt().at(i), 1.0);
      }
      tools::Fill1D(h_npfjets_pt20, tr.npfjets_pt20(), 1.0);
      for(unsigned int i=0; i<tr.pfjet_pt20_eta().size(); i++){
        tools::Fill1D(h_pfjet_pt20_eta, tr.pfjet_pt20_eta().at(i), 1.0);
        tools::Fill1D(h_pfjet_pt20_phi, tr.pfjet_pt20_phi().at(i), 1.0);
        tools::Fill1D(h_pfjet_pt20_pt, tr.pfjet_pt20_pt().at(i), 1.0);
      }
      for(unsigned int i=0; i<tr.track_eta().size(); i++){
        tools::Fill1D(h_track_eta, tr.track_eta().at(i), 1.0);
        tools::Fill1D(h_track_phi, tr.track_phi().at(i), 1.0);
        tools::Fill1D(h_track_pt, tr.track_pt().at(i), 1.0);
      }
      for(unsigned int i=0; i<tr.track_pt10_eta().size(); i++){
        tools::Fill1D(h_track_pt10_eta, tr.track_pt10_eta().at(i), 1.0);
        tools::Fill1D(h_track_pt10_phi, tr.track_pt10_phi().at(i), 1.0);
        tools::Fill1D(h_track_pt10_pt, tr.track_pt10_pt().at(i), 1.0);
      }
      for(unsigned int i=0; i<tr.puInfo_trueNumInteractions().size(); i++){
        tools::Fill1D(h_puInfo_trueNumInteractions, tr.puInfo_trueNumInteractions().at(i), 1.0);
        tools::Fill1D(h_puInfo_nPUvertices, tr.puInfo_nPUvertices().at(i), 1.0);
      }
      tools::Fill1D(h_n_pf_ch, tr.n_pf_ch(), 1.0);
      tools::Fill1D(h_n_pf_gamma, tr.n_pf_gamma(), 1.0);
      tools::Fill1D(h_n_pf_mu, tr.n_pf_mu(), 1.0);
      tools::Fill1D(h_n_pf_nh, tr.n_pf_nh(), 1.0);
      tools::Fill1D(h_ntowers, tr.ntowers(), 1.0);
      tools::Fill1D(h_ntracks, tr.ntracks(), 1.0);
      tools::Fill1D(h_ntracks_pt1, tr.ntracks_pt1(), 1.0);
      tools::Fill1D(h_ntracks_pt5, tr.ntracks_pt5(), 1.0);
      tools::Fill1D(h_ntracks_pt10, tr.ntracks_pt10(), 1.0);
      tools::Fill1D(h_nvertices, tr.nvertices(), 1.0);

    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  f->Write();
  
  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  return 0;
}
