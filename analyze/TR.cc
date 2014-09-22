#include "TR.h"
TR tr;
namespace tas {
	const float &pfmet() { return tr.pfmet(); }
	const float &pfmet_phi() { return tr.pfmet_phi(); }
	const float &pfsumet() { return tr.pfsumet(); }
	const vector<float> &calotower_detid() { return tr.calotower_detid(); }
	const vector<float> &calotower_emEnergy() { return tr.calotower_emEnergy(); }
	const vector<float> &calotower_emEt() { return tr.calotower_emEt(); }
	const vector<float> &calotower_eta() { return tr.calotower_eta(); }
	const vector<float> &calotower_hadEnergy() { return tr.calotower_hadEnergy(); }
	const vector<float> &calotower_hadEt() { return tr.calotower_hadEt(); }
	const vector<float> &calotower_outerEnergy() { return tr.calotower_outerEnergy(); }
	const vector<float> &calotower_outerEt() { return tr.calotower_outerEt(); }
	const vector<float> &calotower_phi() { return tr.calotower_phi(); }
	const vector<float> &pfjet_eta() { return tr.pfjet_eta(); }
	const vector<float> &pfjet_phi() { return tr.pfjet_phi(); }
	const vector<float> &pfjet_pt() { return tr.pfjet_pt(); }
	const vector<float> &pfjet_pt20_eta() { return tr.pfjet_pt20_eta(); }
	const vector<float> &pfjet_pt20_phi() { return tr.pfjet_pt20_phi(); }
	const vector<float> &pfjet_pt20_pt() { return tr.pfjet_pt20_pt(); }
	const vector<float> &track_eta() { return tr.track_eta(); }
	const vector<float> &track_phi() { return tr.track_phi(); }
	const vector<float> &track_pt() { return tr.track_pt(); }
	const vector<float> &track_pt10_eta() { return tr.track_pt10_eta(); }
	const vector<float> &track_pt10_phi() { return tr.track_pt10_phi(); }
	const vector<float> &track_pt10_pt() { return tr.track_pt10_pt(); }
	const vector<float> &puInfo_trueNumInteractions() { return tr.puInfo_trueNumInteractions(); }
	const vector<int> &puInfo_bunchCrossing() { return tr.puInfo_bunchCrossing(); }
	const vector<int> &puInfo_nPUvertices() { return tr.puInfo_nPUvertices(); }
	const unsigned int &n_pf_ch() { return tr.n_pf_ch(); }
	const unsigned int &n_pf_e() { return tr.n_pf_e(); }
	const unsigned int &n_pf_gamma() { return tr.n_pf_gamma(); }
	const unsigned int &npfjets() { return tr.npfjets(); }
	const unsigned int &npfjets_pt20() { return tr.npfjets_pt20(); }
	const unsigned int &n_pf_mu() { return tr.n_pf_mu(); }
	const unsigned int &n_pf_nh() { return tr.n_pf_nh(); }
	const unsigned int &ntowers() { return tr.ntowers(); }
	const unsigned int &ntracks() { return tr.ntracks(); }
	const unsigned int &ntracks_pt1() { return tr.ntracks_pt1(); }
	const unsigned int &ntracks_pt10() { return tr.ntracks_pt10(); }
	const unsigned int &ntracks_pt5() { return tr.ntracks_pt5(); }
	const unsigned int &nvertices() { return tr.nvertices(); }
}
