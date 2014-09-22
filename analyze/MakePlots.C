{
gROOT->ProcessLine(".L Plotter.C");

plot("pfmet", true, "PFMET [GeV]", "Events/10 GeV");
plot("pfmet_phi", false, "PFMET Phi", "Events/0.1");
plot("pfsumet", false, "PF SumET [GeV]", "Events/50 GeV");
plot("calotower_eta", false, "CaloTower Eta", "Events/0.1");
plot("calotower_phi", false, "CaloTower Phi", "Events/0.1");
plot("calotower_emEnergy", true, "CaloTower em Energy [GeV]", "Events/10 GeV");
plot("calotower_emEt", true, "CaloTower em E_{T} [GeV]", "Events/1 GeV");
plot("calotower_hadEnergy", true, "CaloTower had Energy [GeV]", "Events/10 GeV");
plot("calotower_hadEt", true, "CaloTower had E_{T} [GeV]", "Events/1 GeV");
plot("npfjets", false, "Num PFJets", "Events/10");
plot("pfjet_eta", false, "PFJet Eta", "Events/0.1");
plot("pfjet_phi", false, "PFJet Phi", "Events/0.1");
plot("pfjet_pt", true, "PFJet p_{T}", "Events/2 GeV");
plot("npfjets_pt20", false, "Num PFJets, p_{T} > 20 GeV", "Events/10");
plot("pfjet_pt20_eta", false, "PFJet Eta, p_{T} > 20 GeV", "Events/0.1");
plot("pfjet_pt20_phi", false, "PFJet Phi, p_{T} > 20 GeV", "Events/0.1");
plot("pfjet_pt20_pt", false, "PFJet P_{T}, p_{T} > 20 GeV", "Events/5 GeV");
plot("track_eta", false, "Track Eta", "Events/0.1");
plot("track_phi", false, "Track Phi", "Events/0.1");
plot("track_pt", true, "Track p_{T}", "Events/1 GeV");
plot("track_pt10_eta", false, "Track Eta, p_{T} > 10 GeV", "Events/0.1");
plot("track_pt10_phi", false, "Track Phi, p_{T} > 10 GeV", "Events/0.1");
plot("track_pt10_pt", true, "Track p_{T}, p_{T} > 10 GeV", "Events/1 GeV");
plot("puInfo_trueNumInteractions", false, "True Num Interactions", "Events/1");
plot("puInfo_nPUvertices", false, "Num PU Vertices", "Events/1");
plot("n_pf_ch", false, "Num Charged Hadron PFCands", "Events/50");
plot("n_pf_gamma", false, "Num Photon PFCands", "Events/10");
plot("n_pf_mu", false, "Num Muon PFCands", "Events/1");
plot("n_pf_nh", false, "Num Neutral Hadron PFCands", "Events/1");
plot("ntowers", false, "Num Calo Towers", "Events/10");
plot("ntracks", false, "Num Tracks", "Events/10");
plot("ntracks_pt1", false, "Num Tracks, p_{T} > 1 GeV", "Events/10");
plot("ntracks_pt5", false, "Num Tracks, p_{T} > 5 GeV", "Events/10");
plot("ntracks_pt10", false, "Num Tracks, p_{T} > 10 GeV", "Events/10");
plot("nvertices", false, "Num Vertices", "Events/1");

}
