// -*- C++ -*-
#ifndef TR_H
#define TR_H
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std; 
class TR {
private: 
protected: 
	unsigned int index;
	float pfmet_;
	TBranch *pfmet_branch;
	bool pfmet_isLoaded;
	float pfmet_phi_;
	TBranch *pfmet_phi_branch;
	bool pfmet_phi_isLoaded;
	float pfsumet_;
	TBranch *pfsumet_branch;
	bool pfsumet_isLoaded;
	vector<float> calotower_detid_;
	TBranch *calotower_detid_branch;
	bool calotower_detid_isLoaded;
	vector<float> calotower_emEnergy_;
	TBranch *calotower_emEnergy_branch;
	bool calotower_emEnergy_isLoaded;
	vector<float> calotower_emEt_;
	TBranch *calotower_emEt_branch;
	bool calotower_emEt_isLoaded;
	vector<float> calotower_eta_;
	TBranch *calotower_eta_branch;
	bool calotower_eta_isLoaded;
	vector<float> calotower_hadEnergy_;
	TBranch *calotower_hadEnergy_branch;
	bool calotower_hadEnergy_isLoaded;
	vector<float> calotower_hadEt_;
	TBranch *calotower_hadEt_branch;
	bool calotower_hadEt_isLoaded;
	vector<float> calotower_outerEnergy_;
	TBranch *calotower_outerEnergy_branch;
	bool calotower_outerEnergy_isLoaded;
	vector<float> calotower_outerEt_;
	TBranch *calotower_outerEt_branch;
	bool calotower_outerEt_isLoaded;
	vector<float> calotower_phi_;
	TBranch *calotower_phi_branch;
	bool calotower_phi_isLoaded;
	vector<float> pfjet_eta_;
	TBranch *pfjet_eta_branch;
	bool pfjet_eta_isLoaded;
	vector<float> pfjet_phi_;
	TBranch *pfjet_phi_branch;
	bool pfjet_phi_isLoaded;
	vector<float> pfjet_pt_;
	TBranch *pfjet_pt_branch;
	bool pfjet_pt_isLoaded;
	vector<float> pfjet_pt20_eta_;
	TBranch *pfjet_pt20_eta_branch;
	bool pfjet_pt20_eta_isLoaded;
	vector<float> pfjet_pt20_phi_;
	TBranch *pfjet_pt20_phi_branch;
	bool pfjet_pt20_phi_isLoaded;
	vector<float> pfjet_pt20_pt_;
	TBranch *pfjet_pt20_pt_branch;
	bool pfjet_pt20_pt_isLoaded;
	vector<float> track_eta_;
	TBranch *track_eta_branch;
	bool track_eta_isLoaded;
	vector<float> track_phi_;
	TBranch *track_phi_branch;
	bool track_phi_isLoaded;
	vector<float> track_pt_;
	TBranch *track_pt_branch;
	bool track_pt_isLoaded;
	vector<float> track_pt10_eta_;
	TBranch *track_pt10_eta_branch;
	bool track_pt10_eta_isLoaded;
	vector<float> track_pt10_phi_;
	TBranch *track_pt10_phi_branch;
	bool track_pt10_phi_isLoaded;
	vector<float> track_pt10_pt_;
	TBranch *track_pt10_pt_branch;
	bool track_pt10_pt_isLoaded;
	vector<float> puInfo_trueNumInteractions_;
	TBranch *puInfo_trueNumInteractions_branch;
	bool puInfo_trueNumInteractions_isLoaded;
	vector<int> puInfo_bunchCrossing_;
	TBranch *puInfo_bunchCrossing_branch;
	bool puInfo_bunchCrossing_isLoaded;
	vector<int> puInfo_nPUvertices_;
	TBranch *puInfo_nPUvertices_branch;
	bool puInfo_nPUvertices_isLoaded;
	unsigned int n_pf_ch_;
	TBranch *n_pf_ch_branch;
	bool n_pf_ch_isLoaded;
	unsigned int n_pf_e_;
	TBranch *n_pf_e_branch;
	bool n_pf_e_isLoaded;
	unsigned int n_pf_gamma_;
	TBranch *n_pf_gamma_branch;
	bool n_pf_gamma_isLoaded;
	unsigned int npfjets_;
	TBranch *npfjets_branch;
	bool npfjets_isLoaded;
	unsigned int npfjets_pt20_;
	TBranch *npfjets_pt20_branch;
	bool npfjets_pt20_isLoaded;
	unsigned int n_pf_mu_;
	TBranch *n_pf_mu_branch;
	bool n_pf_mu_isLoaded;
	unsigned int n_pf_nh_;
	TBranch *n_pf_nh_branch;
	bool n_pf_nh_isLoaded;
	unsigned int ntowers_;
	TBranch *ntowers_branch;
	bool ntowers_isLoaded;
	unsigned int ntracks_;
	TBranch *ntracks_branch;
	bool ntracks_isLoaded;
	unsigned int ntracks_pt1_;
	TBranch *ntracks_pt1_branch;
	bool ntracks_pt1_isLoaded;
	unsigned int ntracks_pt10_;
	TBranch *ntracks_pt10_branch;
	bool ntracks_pt10_isLoaded;
	unsigned int ntracks_pt5_;
	TBranch *ntracks_pt5_branch;
	bool ntracks_pt5_isLoaded;
	unsigned int nvertices_;
	TBranch *nvertices_branch;
	bool nvertices_isLoaded;
public: 
void Init(TTree *tree) {
  tree->SetMakeClass(1);
	pfmet_branch = 0;
	if (tree->GetAlias("pfmet") != 0) {
		pfmet_branch = tree->GetBranch(tree->GetAlias("pfmet"));
		if (pfmet_branch) {pfmet_branch->SetAddress(&pfmet_);}
	}
	pfmet_phi_branch = 0;
	if (tree->GetAlias("pfmet_phi") != 0) {
		pfmet_phi_branch = tree->GetBranch(tree->GetAlias("pfmet_phi"));
		if (pfmet_phi_branch) {pfmet_phi_branch->SetAddress(&pfmet_phi_);}
	}
	pfsumet_branch = 0;
	if (tree->GetAlias("pfsumet") != 0) {
		pfsumet_branch = tree->GetBranch(tree->GetAlias("pfsumet"));
		if (pfsumet_branch) {pfsumet_branch->SetAddress(&pfsumet_);}
	}
	calotower_detid_branch = 0;
	if (tree->GetAlias("calotower_detid") != 0) {
		calotower_detid_branch = tree->GetBranch(tree->GetAlias("calotower_detid"));
		if (calotower_detid_branch) {calotower_detid_branch->SetAddress(&calotower_detid_);}
	}
	calotower_emEnergy_branch = 0;
	if (tree->GetAlias("calotower_emEnergy") != 0) {
		calotower_emEnergy_branch = tree->GetBranch(tree->GetAlias("calotower_emEnergy"));
		if (calotower_emEnergy_branch) {calotower_emEnergy_branch->SetAddress(&calotower_emEnergy_);}
	}
	calotower_emEt_branch = 0;
	if (tree->GetAlias("calotower_emEt") != 0) {
		calotower_emEt_branch = tree->GetBranch(tree->GetAlias("calotower_emEt"));
		if (calotower_emEt_branch) {calotower_emEt_branch->SetAddress(&calotower_emEt_);}
	}
	calotower_eta_branch = 0;
	if (tree->GetAlias("calotower_eta") != 0) {
		calotower_eta_branch = tree->GetBranch(tree->GetAlias("calotower_eta"));
		if (calotower_eta_branch) {calotower_eta_branch->SetAddress(&calotower_eta_);}
	}
	calotower_hadEnergy_branch = 0;
	if (tree->GetAlias("calotower_hadEnergy") != 0) {
		calotower_hadEnergy_branch = tree->GetBranch(tree->GetAlias("calotower_hadEnergy"));
		if (calotower_hadEnergy_branch) {calotower_hadEnergy_branch->SetAddress(&calotower_hadEnergy_);}
	}
	calotower_hadEt_branch = 0;
	if (tree->GetAlias("calotower_hadEt") != 0) {
		calotower_hadEt_branch = tree->GetBranch(tree->GetAlias("calotower_hadEt"));
		if (calotower_hadEt_branch) {calotower_hadEt_branch->SetAddress(&calotower_hadEt_);}
	}
	calotower_outerEnergy_branch = 0;
	if (tree->GetAlias("calotower_outerEnergy") != 0) {
		calotower_outerEnergy_branch = tree->GetBranch(tree->GetAlias("calotower_outerEnergy"));
		if (calotower_outerEnergy_branch) {calotower_outerEnergy_branch->SetAddress(&calotower_outerEnergy_);}
	}
	calotower_outerEt_branch = 0;
	if (tree->GetAlias("calotower_outerEt") != 0) {
		calotower_outerEt_branch = tree->GetBranch(tree->GetAlias("calotower_outerEt"));
		if (calotower_outerEt_branch) {calotower_outerEt_branch->SetAddress(&calotower_outerEt_);}
	}
	calotower_phi_branch = 0;
	if (tree->GetAlias("calotower_phi") != 0) {
		calotower_phi_branch = tree->GetBranch(tree->GetAlias("calotower_phi"));
		if (calotower_phi_branch) {calotower_phi_branch->SetAddress(&calotower_phi_);}
	}
	pfjet_eta_branch = 0;
	if (tree->GetAlias("pfjet_eta") != 0) {
		pfjet_eta_branch = tree->GetBranch(tree->GetAlias("pfjet_eta"));
		if (pfjet_eta_branch) {pfjet_eta_branch->SetAddress(&pfjet_eta_);}
	}
	pfjet_phi_branch = 0;
	if (tree->GetAlias("pfjet_phi") != 0) {
		pfjet_phi_branch = tree->GetBranch(tree->GetAlias("pfjet_phi"));
		if (pfjet_phi_branch) {pfjet_phi_branch->SetAddress(&pfjet_phi_);}
	}
	pfjet_pt_branch = 0;
	if (tree->GetAlias("pfjet_pt") != 0) {
		pfjet_pt_branch = tree->GetBranch(tree->GetAlias("pfjet_pt"));
		if (pfjet_pt_branch) {pfjet_pt_branch->SetAddress(&pfjet_pt_);}
	}
	pfjet_pt20_eta_branch = 0;
	if (tree->GetAlias("pfjet_pt20_eta") != 0) {
		pfjet_pt20_eta_branch = tree->GetBranch(tree->GetAlias("pfjet_pt20_eta"));
		if (pfjet_pt20_eta_branch) {pfjet_pt20_eta_branch->SetAddress(&pfjet_pt20_eta_);}
	}
	pfjet_pt20_phi_branch = 0;
	if (tree->GetAlias("pfjet_pt20_phi") != 0) {
		pfjet_pt20_phi_branch = tree->GetBranch(tree->GetAlias("pfjet_pt20_phi"));
		if (pfjet_pt20_phi_branch) {pfjet_pt20_phi_branch->SetAddress(&pfjet_pt20_phi_);}
	}
	pfjet_pt20_pt_branch = 0;
	if (tree->GetAlias("pfjet_pt20_pt") != 0) {
		pfjet_pt20_pt_branch = tree->GetBranch(tree->GetAlias("pfjet_pt20_pt"));
		if (pfjet_pt20_pt_branch) {pfjet_pt20_pt_branch->SetAddress(&pfjet_pt20_pt_);}
	}
	track_eta_branch = 0;
	if (tree->GetAlias("track_eta") != 0) {
		track_eta_branch = tree->GetBranch(tree->GetAlias("track_eta"));
		if (track_eta_branch) {track_eta_branch->SetAddress(&track_eta_);}
	}
	track_phi_branch = 0;
	if (tree->GetAlias("track_phi") != 0) {
		track_phi_branch = tree->GetBranch(tree->GetAlias("track_phi"));
		if (track_phi_branch) {track_phi_branch->SetAddress(&track_phi_);}
	}
	track_pt_branch = 0;
	if (tree->GetAlias("track_pt") != 0) {
		track_pt_branch = tree->GetBranch(tree->GetAlias("track_pt"));
		if (track_pt_branch) {track_pt_branch->SetAddress(&track_pt_);}
	}
	track_pt10_eta_branch = 0;
	if (tree->GetAlias("track_pt10_eta") != 0) {
		track_pt10_eta_branch = tree->GetBranch(tree->GetAlias("track_pt10_eta"));
		if (track_pt10_eta_branch) {track_pt10_eta_branch->SetAddress(&track_pt10_eta_);}
	}
	track_pt10_phi_branch = 0;
	if (tree->GetAlias("track_pt10_phi") != 0) {
		track_pt10_phi_branch = tree->GetBranch(tree->GetAlias("track_pt10_phi"));
		if (track_pt10_phi_branch) {track_pt10_phi_branch->SetAddress(&track_pt10_phi_);}
	}
	track_pt10_pt_branch = 0;
	if (tree->GetAlias("track_pt10_pt") != 0) {
		track_pt10_pt_branch = tree->GetBranch(tree->GetAlias("track_pt10_pt"));
		if (track_pt10_pt_branch) {track_pt10_pt_branch->SetAddress(&track_pt10_pt_);}
	}
	puInfo_trueNumInteractions_branch = 0;
	if (tree->GetAlias("puInfo_trueNumInteractions") != 0) {
		puInfo_trueNumInteractions_branch = tree->GetBranch(tree->GetAlias("puInfo_trueNumInteractions"));
		if (puInfo_trueNumInteractions_branch) {puInfo_trueNumInteractions_branch->SetAddress(&puInfo_trueNumInteractions_);}
	}
	puInfo_bunchCrossing_branch = 0;
	if (tree->GetAlias("puInfo_bunchCrossing") != 0) {
		puInfo_bunchCrossing_branch = tree->GetBranch(tree->GetAlias("puInfo_bunchCrossing"));
		if (puInfo_bunchCrossing_branch) {puInfo_bunchCrossing_branch->SetAddress(&puInfo_bunchCrossing_);}
	}
	puInfo_nPUvertices_branch = 0;
	if (tree->GetAlias("puInfo_nPUvertices") != 0) {
		puInfo_nPUvertices_branch = tree->GetBranch(tree->GetAlias("puInfo_nPUvertices"));
		if (puInfo_nPUvertices_branch) {puInfo_nPUvertices_branch->SetAddress(&puInfo_nPUvertices_);}
	}
	n_pf_ch_branch = 0;
	if (tree->GetAlias("n_pf_ch") != 0) {
		n_pf_ch_branch = tree->GetBranch(tree->GetAlias("n_pf_ch"));
		if (n_pf_ch_branch) {n_pf_ch_branch->SetAddress(&n_pf_ch_);}
	}
	n_pf_e_branch = 0;
	if (tree->GetAlias("n_pf_e") != 0) {
		n_pf_e_branch = tree->GetBranch(tree->GetAlias("n_pf_e"));
		if (n_pf_e_branch) {n_pf_e_branch->SetAddress(&n_pf_e_);}
	}
	n_pf_gamma_branch = 0;
	if (tree->GetAlias("n_pf_gamma") != 0) {
		n_pf_gamma_branch = tree->GetBranch(tree->GetAlias("n_pf_gamma"));
		if (n_pf_gamma_branch) {n_pf_gamma_branch->SetAddress(&n_pf_gamma_);}
	}
	npfjets_branch = 0;
	if (tree->GetAlias("npfjets") != 0) {
		npfjets_branch = tree->GetBranch(tree->GetAlias("npfjets"));
		if (npfjets_branch) {npfjets_branch->SetAddress(&npfjets_);}
	}
	npfjets_pt20_branch = 0;
	if (tree->GetAlias("npfjets_pt20") != 0) {
		npfjets_pt20_branch = tree->GetBranch(tree->GetAlias("npfjets_pt20"));
		if (npfjets_pt20_branch) {npfjets_pt20_branch->SetAddress(&npfjets_pt20_);}
	}
	n_pf_mu_branch = 0;
	if (tree->GetAlias("n_pf_mu") != 0) {
		n_pf_mu_branch = tree->GetBranch(tree->GetAlias("n_pf_mu"));
		if (n_pf_mu_branch) {n_pf_mu_branch->SetAddress(&n_pf_mu_);}
	}
	n_pf_nh_branch = 0;
	if (tree->GetAlias("n_pf_nh") != 0) {
		n_pf_nh_branch = tree->GetBranch(tree->GetAlias("n_pf_nh"));
		if (n_pf_nh_branch) {n_pf_nh_branch->SetAddress(&n_pf_nh_);}
	}
	ntowers_branch = 0;
	if (tree->GetAlias("ntowers") != 0) {
		ntowers_branch = tree->GetBranch(tree->GetAlias("ntowers"));
		if (ntowers_branch) {ntowers_branch->SetAddress(&ntowers_);}
	}
	ntracks_branch = 0;
	if (tree->GetAlias("ntracks") != 0) {
		ntracks_branch = tree->GetBranch(tree->GetAlias("ntracks"));
		if (ntracks_branch) {ntracks_branch->SetAddress(&ntracks_);}
	}
	ntracks_pt1_branch = 0;
	if (tree->GetAlias("ntracks_pt1") != 0) {
		ntracks_pt1_branch = tree->GetBranch(tree->GetAlias("ntracks_pt1"));
		if (ntracks_pt1_branch) {ntracks_pt1_branch->SetAddress(&ntracks_pt1_);}
	}
	ntracks_pt10_branch = 0;
	if (tree->GetAlias("ntracks_pt10") != 0) {
		ntracks_pt10_branch = tree->GetBranch(tree->GetAlias("ntracks_pt10"));
		if (ntracks_pt10_branch) {ntracks_pt10_branch->SetAddress(&ntracks_pt10_);}
	}
	ntracks_pt5_branch = 0;
	if (tree->GetAlias("ntracks_pt5") != 0) {
		ntracks_pt5_branch = tree->GetBranch(tree->GetAlias("ntracks_pt5"));
		if (ntracks_pt5_branch) {ntracks_pt5_branch->SetAddress(&ntracks_pt5_);}
	}
	nvertices_branch = 0;
	if (tree->GetAlias("nvertices") != 0) {
		nvertices_branch = tree->GetBranch(tree->GetAlias("nvertices"));
		if (nvertices_branch) {nvertices_branch->SetAddress(&nvertices_);}
	}
  tree->SetMakeClass(0);
}
void GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		pfmet_isLoaded = false;
		pfmet_phi_isLoaded = false;
		pfsumet_isLoaded = false;
		calotower_detid_isLoaded = false;
		calotower_emEnergy_isLoaded = false;
		calotower_emEt_isLoaded = false;
		calotower_eta_isLoaded = false;
		calotower_hadEnergy_isLoaded = false;
		calotower_hadEt_isLoaded = false;
		calotower_outerEnergy_isLoaded = false;
		calotower_outerEt_isLoaded = false;
		calotower_phi_isLoaded = false;
		pfjet_eta_isLoaded = false;
		pfjet_phi_isLoaded = false;
		pfjet_pt_isLoaded = false;
		pfjet_pt20_eta_isLoaded = false;
		pfjet_pt20_phi_isLoaded = false;
		pfjet_pt20_pt_isLoaded = false;
		track_eta_isLoaded = false;
		track_phi_isLoaded = false;
		track_pt_isLoaded = false;
		track_pt10_eta_isLoaded = false;
		track_pt10_phi_isLoaded = false;
		track_pt10_pt_isLoaded = false;
		puInfo_trueNumInteractions_isLoaded = false;
		puInfo_bunchCrossing_isLoaded = false;
		puInfo_nPUvertices_isLoaded = false;
		n_pf_ch_isLoaded = false;
		n_pf_e_isLoaded = false;
		n_pf_gamma_isLoaded = false;
		npfjets_isLoaded = false;
		npfjets_pt20_isLoaded = false;
		n_pf_mu_isLoaded = false;
		n_pf_nh_isLoaded = false;
		ntowers_isLoaded = false;
		ntracks_isLoaded = false;
		ntracks_pt1_isLoaded = false;
		ntracks_pt10_isLoaded = false;
		ntracks_pt5_isLoaded = false;
		nvertices_isLoaded = false;
	}

void LoadAllBranches() 
	// load all branches
{
	if (pfmet_branch != 0) pfmet();
	if (pfmet_phi_branch != 0) pfmet_phi();
	if (pfsumet_branch != 0) pfsumet();
	if (calotower_detid_branch != 0) calotower_detid();
	if (calotower_emEnergy_branch != 0) calotower_emEnergy();
	if (calotower_emEt_branch != 0) calotower_emEt();
	if (calotower_eta_branch != 0) calotower_eta();
	if (calotower_hadEnergy_branch != 0) calotower_hadEnergy();
	if (calotower_hadEt_branch != 0) calotower_hadEt();
	if (calotower_outerEnergy_branch != 0) calotower_outerEnergy();
	if (calotower_outerEt_branch != 0) calotower_outerEt();
	if (calotower_phi_branch != 0) calotower_phi();
	if (pfjet_eta_branch != 0) pfjet_eta();
	if (pfjet_phi_branch != 0) pfjet_phi();
	if (pfjet_pt_branch != 0) pfjet_pt();
	if (pfjet_pt20_eta_branch != 0) pfjet_pt20_eta();
	if (pfjet_pt20_phi_branch != 0) pfjet_pt20_phi();
	if (pfjet_pt20_pt_branch != 0) pfjet_pt20_pt();
	if (track_eta_branch != 0) track_eta();
	if (track_phi_branch != 0) track_phi();
	if (track_pt_branch != 0) track_pt();
	if (track_pt10_eta_branch != 0) track_pt10_eta();
	if (track_pt10_phi_branch != 0) track_pt10_phi();
	if (track_pt10_pt_branch != 0) track_pt10_pt();
	if (puInfo_trueNumInteractions_branch != 0) puInfo_trueNumInteractions();
	if (puInfo_bunchCrossing_branch != 0) puInfo_bunchCrossing();
	if (puInfo_nPUvertices_branch != 0) puInfo_nPUvertices();
	if (n_pf_ch_branch != 0) n_pf_ch();
	if (n_pf_e_branch != 0) n_pf_e();
	if (n_pf_gamma_branch != 0) n_pf_gamma();
	if (npfjets_branch != 0) npfjets();
	if (npfjets_pt20_branch != 0) npfjets_pt20();
	if (n_pf_mu_branch != 0) n_pf_mu();
	if (n_pf_nh_branch != 0) n_pf_nh();
	if (ntowers_branch != 0) ntowers();
	if (ntracks_branch != 0) ntracks();
	if (ntracks_pt1_branch != 0) ntracks_pt1();
	if (ntracks_pt10_branch != 0) ntracks_pt10();
	if (ntracks_pt5_branch != 0) ntracks_pt5();
	if (nvertices_branch != 0) nvertices();
}

	float &pfmet()
	{
		if (not pfmet_isLoaded) {
			if (pfmet_branch != 0) {
				pfmet_branch->GetEntry(index);
			} else { 
				printf("branch pfmet_branch does not exist!\n");
				exit(1);
			}
			pfmet_isLoaded = true;
		}
		return pfmet_;
	}
	float &pfmet_phi()
	{
		if (not pfmet_phi_isLoaded) {
			if (pfmet_phi_branch != 0) {
				pfmet_phi_branch->GetEntry(index);
			} else { 
				printf("branch pfmet_phi_branch does not exist!\n");
				exit(1);
			}
			pfmet_phi_isLoaded = true;
		}
		return pfmet_phi_;
	}
	float &pfsumet()
	{
		if (not pfsumet_isLoaded) {
			if (pfsumet_branch != 0) {
				pfsumet_branch->GetEntry(index);
			} else { 
				printf("branch pfsumet_branch does not exist!\n");
				exit(1);
			}
			pfsumet_isLoaded = true;
		}
		return pfsumet_;
	}
	const vector<float> &calotower_detid()
	{
		if (not calotower_detid_isLoaded) {
			if (calotower_detid_branch != 0) {
				calotower_detid_branch->GetEntry(index);
			} else { 
				printf("branch calotower_detid_branch does not exist!\n");
				exit(1);
			}
			calotower_detid_isLoaded = true;
		}
		return calotower_detid_;
	}
	const vector<float> &calotower_emEnergy()
	{
		if (not calotower_emEnergy_isLoaded) {
			if (calotower_emEnergy_branch != 0) {
				calotower_emEnergy_branch->GetEntry(index);
			} else { 
				printf("branch calotower_emEnergy_branch does not exist!\n");
				exit(1);
			}
			calotower_emEnergy_isLoaded = true;
		}
		return calotower_emEnergy_;
	}
	const vector<float> &calotower_emEt()
	{
		if (not calotower_emEt_isLoaded) {
			if (calotower_emEt_branch != 0) {
				calotower_emEt_branch->GetEntry(index);
			} else { 
				printf("branch calotower_emEt_branch does not exist!\n");
				exit(1);
			}
			calotower_emEt_isLoaded = true;
		}
		return calotower_emEt_;
	}
	const vector<float> &calotower_eta()
	{
		if (not calotower_eta_isLoaded) {
			if (calotower_eta_branch != 0) {
				calotower_eta_branch->GetEntry(index);
			} else { 
				printf("branch calotower_eta_branch does not exist!\n");
				exit(1);
			}
			calotower_eta_isLoaded = true;
		}
		return calotower_eta_;
	}
	const vector<float> &calotower_hadEnergy()
	{
		if (not calotower_hadEnergy_isLoaded) {
			if (calotower_hadEnergy_branch != 0) {
				calotower_hadEnergy_branch->GetEntry(index);
			} else { 
				printf("branch calotower_hadEnergy_branch does not exist!\n");
				exit(1);
			}
			calotower_hadEnergy_isLoaded = true;
		}
		return calotower_hadEnergy_;
	}
	const vector<float> &calotower_hadEt()
	{
		if (not calotower_hadEt_isLoaded) {
			if (calotower_hadEt_branch != 0) {
				calotower_hadEt_branch->GetEntry(index);
			} else { 
				printf("branch calotower_hadEt_branch does not exist!\n");
				exit(1);
			}
			calotower_hadEt_isLoaded = true;
		}
		return calotower_hadEt_;
	}
	const vector<float> &calotower_outerEnergy()
	{
		if (not calotower_outerEnergy_isLoaded) {
			if (calotower_outerEnergy_branch != 0) {
				calotower_outerEnergy_branch->GetEntry(index);
			} else { 
				printf("branch calotower_outerEnergy_branch does not exist!\n");
				exit(1);
			}
			calotower_outerEnergy_isLoaded = true;
		}
		return calotower_outerEnergy_;
	}
	const vector<float> &calotower_outerEt()
	{
		if (not calotower_outerEt_isLoaded) {
			if (calotower_outerEt_branch != 0) {
				calotower_outerEt_branch->GetEntry(index);
			} else { 
				printf("branch calotower_outerEt_branch does not exist!\n");
				exit(1);
			}
			calotower_outerEt_isLoaded = true;
		}
		return calotower_outerEt_;
	}
	const vector<float> &calotower_phi()
	{
		if (not calotower_phi_isLoaded) {
			if (calotower_phi_branch != 0) {
				calotower_phi_branch->GetEntry(index);
			} else { 
				printf("branch calotower_phi_branch does not exist!\n");
				exit(1);
			}
			calotower_phi_isLoaded = true;
		}
		return calotower_phi_;
	}
	const vector<float> &pfjet_eta()
	{
		if (not pfjet_eta_isLoaded) {
			if (pfjet_eta_branch != 0) {
				pfjet_eta_branch->GetEntry(index);
			} else { 
				printf("branch pfjet_eta_branch does not exist!\n");
				exit(1);
			}
			pfjet_eta_isLoaded = true;
		}
		return pfjet_eta_;
	}
	const vector<float> &pfjet_phi()
	{
		if (not pfjet_phi_isLoaded) {
			if (pfjet_phi_branch != 0) {
				pfjet_phi_branch->GetEntry(index);
			} else { 
				printf("branch pfjet_phi_branch does not exist!\n");
				exit(1);
			}
			pfjet_phi_isLoaded = true;
		}
		return pfjet_phi_;
	}
	const vector<float> &pfjet_pt()
	{
		if (not pfjet_pt_isLoaded) {
			if (pfjet_pt_branch != 0) {
				pfjet_pt_branch->GetEntry(index);
			} else { 
				printf("branch pfjet_pt_branch does not exist!\n");
				exit(1);
			}
			pfjet_pt_isLoaded = true;
		}
		return pfjet_pt_;
	}
	const vector<float> &pfjet_pt20_eta()
	{
		if (not pfjet_pt20_eta_isLoaded) {
			if (pfjet_pt20_eta_branch != 0) {
				pfjet_pt20_eta_branch->GetEntry(index);
			} else { 
				printf("branch pfjet_pt20_eta_branch does not exist!\n");
				exit(1);
			}
			pfjet_pt20_eta_isLoaded = true;
		}
		return pfjet_pt20_eta_;
	}
	const vector<float> &pfjet_pt20_phi()
	{
		if (not pfjet_pt20_phi_isLoaded) {
			if (pfjet_pt20_phi_branch != 0) {
				pfjet_pt20_phi_branch->GetEntry(index);
			} else { 
				printf("branch pfjet_pt20_phi_branch does not exist!\n");
				exit(1);
			}
			pfjet_pt20_phi_isLoaded = true;
		}
		return pfjet_pt20_phi_;
	}
	const vector<float> &pfjet_pt20_pt()
	{
		if (not pfjet_pt20_pt_isLoaded) {
			if (pfjet_pt20_pt_branch != 0) {
				pfjet_pt20_pt_branch->GetEntry(index);
			} else { 
				printf("branch pfjet_pt20_pt_branch does not exist!\n");
				exit(1);
			}
			pfjet_pt20_pt_isLoaded = true;
		}
		return pfjet_pt20_pt_;
	}
	const vector<float> &track_eta()
	{
		if (not track_eta_isLoaded) {
			if (track_eta_branch != 0) {
				track_eta_branch->GetEntry(index);
			} else { 
				printf("branch track_eta_branch does not exist!\n");
				exit(1);
			}
			track_eta_isLoaded = true;
		}
		return track_eta_;
	}
	const vector<float> &track_phi()
	{
		if (not track_phi_isLoaded) {
			if (track_phi_branch != 0) {
				track_phi_branch->GetEntry(index);
			} else { 
				printf("branch track_phi_branch does not exist!\n");
				exit(1);
			}
			track_phi_isLoaded = true;
		}
		return track_phi_;
	}
	const vector<float> &track_pt()
	{
		if (not track_pt_isLoaded) {
			if (track_pt_branch != 0) {
				track_pt_branch->GetEntry(index);
			} else { 
				printf("branch track_pt_branch does not exist!\n");
				exit(1);
			}
			track_pt_isLoaded = true;
		}
		return track_pt_;
	}
	const vector<float> &track_pt10_eta()
	{
		if (not track_pt10_eta_isLoaded) {
			if (track_pt10_eta_branch != 0) {
				track_pt10_eta_branch->GetEntry(index);
			} else { 
				printf("branch track_pt10_eta_branch does not exist!\n");
				exit(1);
			}
			track_pt10_eta_isLoaded = true;
		}
		return track_pt10_eta_;
	}
	const vector<float> &track_pt10_phi()
	{
		if (not track_pt10_phi_isLoaded) {
			if (track_pt10_phi_branch != 0) {
				track_pt10_phi_branch->GetEntry(index);
			} else { 
				printf("branch track_pt10_phi_branch does not exist!\n");
				exit(1);
			}
			track_pt10_phi_isLoaded = true;
		}
		return track_pt10_phi_;
	}
	const vector<float> &track_pt10_pt()
	{
		if (not track_pt10_pt_isLoaded) {
			if (track_pt10_pt_branch != 0) {
				track_pt10_pt_branch->GetEntry(index);
			} else { 
				printf("branch track_pt10_pt_branch does not exist!\n");
				exit(1);
			}
			track_pt10_pt_isLoaded = true;
		}
		return track_pt10_pt_;
	}
	const vector<float> &puInfo_trueNumInteractions()
	{
		if (not puInfo_trueNumInteractions_isLoaded) {
			if (puInfo_trueNumInteractions_branch != 0) {
				puInfo_trueNumInteractions_branch->GetEntry(index);
			} else { 
				printf("branch puInfo_trueNumInteractions_branch does not exist!\n");
				exit(1);
			}
			puInfo_trueNumInteractions_isLoaded = true;
		}
		return puInfo_trueNumInteractions_;
	}
	const vector<int> &puInfo_bunchCrossing()
	{
		if (not puInfo_bunchCrossing_isLoaded) {
			if (puInfo_bunchCrossing_branch != 0) {
				puInfo_bunchCrossing_branch->GetEntry(index);
			} else { 
				printf("branch puInfo_bunchCrossing_branch does not exist!\n");
				exit(1);
			}
			puInfo_bunchCrossing_isLoaded = true;
		}
		return puInfo_bunchCrossing_;
	}
	const vector<int> &puInfo_nPUvertices()
	{
		if (not puInfo_nPUvertices_isLoaded) {
			if (puInfo_nPUvertices_branch != 0) {
				puInfo_nPUvertices_branch->GetEntry(index);
			} else { 
				printf("branch puInfo_nPUvertices_branch does not exist!\n");
				exit(1);
			}
			puInfo_nPUvertices_isLoaded = true;
		}
		return puInfo_nPUvertices_;
	}
	unsigned int &n_pf_ch()
	{
		if (not n_pf_ch_isLoaded) {
			if (n_pf_ch_branch != 0) {
				n_pf_ch_branch->GetEntry(index);
			} else { 
				printf("branch n_pf_ch_branch does not exist!\n");
				exit(1);
			}
			n_pf_ch_isLoaded = true;
		}
		return n_pf_ch_;
	}
	unsigned int &n_pf_e()
	{
		if (not n_pf_e_isLoaded) {
			if (n_pf_e_branch != 0) {
				n_pf_e_branch->GetEntry(index);
			} else { 
				printf("branch n_pf_e_branch does not exist!\n");
				exit(1);
			}
			n_pf_e_isLoaded = true;
		}
		return n_pf_e_;
	}
	unsigned int &n_pf_gamma()
	{
		if (not n_pf_gamma_isLoaded) {
			if (n_pf_gamma_branch != 0) {
				n_pf_gamma_branch->GetEntry(index);
			} else { 
				printf("branch n_pf_gamma_branch does not exist!\n");
				exit(1);
			}
			n_pf_gamma_isLoaded = true;
		}
		return n_pf_gamma_;
	}
	unsigned int &npfjets()
	{
		if (not npfjets_isLoaded) {
			if (npfjets_branch != 0) {
				npfjets_branch->GetEntry(index);
			} else { 
				printf("branch npfjets_branch does not exist!\n");
				exit(1);
			}
			npfjets_isLoaded = true;
		}
		return npfjets_;
	}
	unsigned int &npfjets_pt20()
	{
		if (not npfjets_pt20_isLoaded) {
			if (npfjets_pt20_branch != 0) {
				npfjets_pt20_branch->GetEntry(index);
			} else { 
				printf("branch npfjets_pt20_branch does not exist!\n");
				exit(1);
			}
			npfjets_pt20_isLoaded = true;
		}
		return npfjets_pt20_;
	}
	unsigned int &n_pf_mu()
	{
		if (not n_pf_mu_isLoaded) {
			if (n_pf_mu_branch != 0) {
				n_pf_mu_branch->GetEntry(index);
			} else { 
				printf("branch n_pf_mu_branch does not exist!\n");
				exit(1);
			}
			n_pf_mu_isLoaded = true;
		}
		return n_pf_mu_;
	}
	unsigned int &n_pf_nh()
	{
		if (not n_pf_nh_isLoaded) {
			if (n_pf_nh_branch != 0) {
				n_pf_nh_branch->GetEntry(index);
			} else { 
				printf("branch n_pf_nh_branch does not exist!\n");
				exit(1);
			}
			n_pf_nh_isLoaded = true;
		}
		return n_pf_nh_;
	}
	unsigned int &ntowers()
	{
		if (not ntowers_isLoaded) {
			if (ntowers_branch != 0) {
				ntowers_branch->GetEntry(index);
			} else { 
				printf("branch ntowers_branch does not exist!\n");
				exit(1);
			}
			ntowers_isLoaded = true;
		}
		return ntowers_;
	}
	unsigned int &ntracks()
	{
		if (not ntracks_isLoaded) {
			if (ntracks_branch != 0) {
				ntracks_branch->GetEntry(index);
			} else { 
				printf("branch ntracks_branch does not exist!\n");
				exit(1);
			}
			ntracks_isLoaded = true;
		}
		return ntracks_;
	}
	unsigned int &ntracks_pt1()
	{
		if (not ntracks_pt1_isLoaded) {
			if (ntracks_pt1_branch != 0) {
				ntracks_pt1_branch->GetEntry(index);
			} else { 
				printf("branch ntracks_pt1_branch does not exist!\n");
				exit(1);
			}
			ntracks_pt1_isLoaded = true;
		}
		return ntracks_pt1_;
	}
	unsigned int &ntracks_pt10()
	{
		if (not ntracks_pt10_isLoaded) {
			if (ntracks_pt10_branch != 0) {
				ntracks_pt10_branch->GetEntry(index);
			} else { 
				printf("branch ntracks_pt10_branch does not exist!\n");
				exit(1);
			}
			ntracks_pt10_isLoaded = true;
		}
		return ntracks_pt10_;
	}
	unsigned int &ntracks_pt5()
	{
		if (not ntracks_pt5_isLoaded) {
			if (ntracks_pt5_branch != 0) {
				ntracks_pt5_branch->GetEntry(index);
			} else { 
				printf("branch ntracks_pt5_branch does not exist!\n");
				exit(1);
			}
			ntracks_pt5_isLoaded = true;
		}
		return ntracks_pt5_;
	}
	unsigned int &nvertices()
	{
		if (not nvertices_isLoaded) {
			if (nvertices_branch != 0) {
				nvertices_branch->GetEntry(index);
			} else { 
				printf("branch nvertices_branch does not exist!\n");
				exit(1);
			}
			nvertices_isLoaded = true;
		}
		return nvertices_;
	}

  static void progress( int nEventsTotal, int nEventsChain ){
    int period = 1000;
    if(nEventsTotal%1000 == 0) {
      // xterm magic from L. Vacavant and A. Cerri
      if (isatty(1)) {
        if( ( nEventsChain - nEventsTotal ) > period ){
          float frac = (float)nEventsTotal/(nEventsChain*0.01);
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
          fflush(stdout);
        }
        else {
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", 100.);
          cout << endl;
        }
      }
    }
  }
  
};

#ifndef __CINT__
extern TR tr;
#endif

namespace tas {
	const float &pfmet();
	const float &pfmet_phi();
	const float &pfsumet();
	const vector<float> &calotower_detid();
	const vector<float> &calotower_emEnergy();
	const vector<float> &calotower_emEt();
	const vector<float> &calotower_eta();
	const vector<float> &calotower_hadEnergy();
	const vector<float> &calotower_hadEt();
	const vector<float> &calotower_outerEnergy();
	const vector<float> &calotower_outerEt();
	const vector<float> &calotower_phi();
	const vector<float> &pfjet_eta();
	const vector<float> &pfjet_phi();
	const vector<float> &pfjet_pt();
	const vector<float> &pfjet_pt20_eta();
	const vector<float> &pfjet_pt20_phi();
	const vector<float> &pfjet_pt20_pt();
	const vector<float> &track_eta();
	const vector<float> &track_phi();
	const vector<float> &track_pt();
	const vector<float> &track_pt10_eta();
	const vector<float> &track_pt10_phi();
	const vector<float> &track_pt10_pt();
	const vector<float> &puInfo_trueNumInteractions();
	const vector<int> &puInfo_bunchCrossing();
	const vector<int> &puInfo_nPUvertices();
	const unsigned int &n_pf_ch();
	const unsigned int &n_pf_e();
	const unsigned int &n_pf_gamma();
	const unsigned int &npfjets();
	const unsigned int &npfjets_pt20();
	const unsigned int &n_pf_mu();
	const unsigned int &n_pf_nh();
	const unsigned int &ntowers();
	const unsigned int &ntracks();
	const unsigned int &ntracks_pt1();
	const unsigned int &ntracks_pt10();
	const unsigned int &ntracks_pt5();
	const unsigned int &nvertices();
}
#endif
