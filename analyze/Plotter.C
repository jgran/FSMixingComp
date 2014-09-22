#include "TMath.h"

void plot(std::string var = "pfmet", bool logScale = false, std::string xtitle = "pfmet [GeV]", std::string ytitle = "Events/20 GeV"){

  TFile *f_newMixing = new TFile( "newMixing_hists.root", "READ");
  TFile *f_oldMixing = new TFile( "oldMixing_hists.root", "READ");

  TH1F *h_newMixing = (TH1F*)f_newMixing->Get( Form("h_%s", var.c_str()) );
  TH1F *h_oldMixing = (TH1F*)f_oldMixing->Get( Form("h_%s", var.c_str()) );

  gStyle->SetOptStat("");
  gStyle->SetCanvasColor(0);
  gStyle->SetPadGridX(0);
  gStyle->SetPadGridY(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetFrameBorderMode(0);

  //Color
  h_newMixing->SetLineColor(kBlack);
  h_oldMixing->SetLineColor(kRed);

  //Range of Y Axis
  float ymax = TMath::Max(h_newMixing->GetMaximum(), h_oldMixing->GetMaximum());
  ymax += 0.1*ymax;
  h_newMixing->SetMaximum(ymax);
  h_oldMixing->SetMaximum(ymax);

  //Label axes
  h_oldMixing->GetXaxis()->SetTitle( Form("#bf{%s}", xtitle.c_str()) );
  h_oldMixing->GetYaxis()->SetTitle( Form("#bf{%s}", ytitle.c_str()) );
  h_oldMixing->GetXaxis()->SetTitleSize(0.04);
  h_oldMixing->GetYaxis()->SetTitleSize(0.04);

  TCanvas *c1 = new TCanvas();
  if(logScale) c1->SetLogy();
  h_oldMixing->Draw("E1HIST");
  h_newMixing->Draw("E1HISTSAME");

  //Legend
  TLegend *leg = new TLegend(0.65, .6, .85, .75);
  leg->AddEntry( h_newMixing , "New Mixing", "l" );
  leg->AddEntry( h_oldMixing , "Old Mixing", "l" );
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.03);
  leg->Draw();

  std::string plot_path = "plots/";

  c1->Print( Form("%s%s.pdf", plot_path.c_str(), var.c_str()) );
}
