//#include "DataFormats/Common/interface/Handle.h"
#include "Study/BabyMaker/interface/BabyMaker.h"

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;


BabyMaker::BabyMaker(const edm::ParameterSet& iConfig) {

    produces<unsigned int> ("nvertices").setBranchAlias("nvertices");
    produces<unsigned int> ("ntracks").setBranchAlias("ntracks");
    produces<unsigned int> ("ntrackspt1").setBranchAlias("ntracks_pt1");
    produces<unsigned int> ("ntrackspt5").setBranchAlias("ntracks_pt5");
    produces<unsigned int> ("ntrackspt10").setBranchAlias("ntracks_pt10");
    produces<std::vector<float> > ("trackpt").setBranchAlias("track_pt");
    produces<std::vector<float> > ("tracketa").setBranchAlias("track_eta");
    produces<std::vector<float> > ("trackphi").setBranchAlias("track_phi");
    produces<std::vector<float> > ("trackpt10pt").setBranchAlias("track_pt10_pt");
    produces<std::vector<float> > ("trackpt10eta").setBranchAlias("track_pt10_eta");
    produces<std::vector<float> > ("trackpt10phi").setBranchAlias("track_pt10_phi");
    produces<unsigned int> ("npfjets").setBranchAlias("npfjets");
    produces<std::vector<float> > ("pfjetpt").setBranchAlias("pfjet_pt");
    produces<std::vector<float> > ("pfjeteta").setBranchAlias("pfjet_eta");
    produces<std::vector<float> > ("pfjetphi").setBranchAlias("pfjet_phi");
    produces<unsigned int> ("npfjetspt20").setBranchAlias("npfjets_pt20");
    produces<std::vector<float> > ("pfjetpt20pt").setBranchAlias("pfjet_pt20_pt");
    produces<std::vector<float> > ("pfjetpt20eta").setBranchAlias("pfjet_pt20_eta");
    produces<std::vector<float> > ("pfjetpt20phi").setBranchAlias("pfjet_pt20_phi");
    produces<unsigned int> ("npfch").setBranchAlias("n_pf_ch");
    produces<unsigned int> ("npfe").setBranchAlias("n_pf_e");
    produces<unsigned int> ("npfmu").setBranchAlias("n_pf_mu");
    produces<unsigned int> ("npfgamma").setBranchAlias("n_pf_gamma");
    produces<unsigned int> ("npfnh").setBranchAlias("n_pf_nh");
    produces<float> ("pfmet").setBranchAlias("pfmet");
    produces<float> ("pfmetphi").setBranchAlias("pfmet_phi");
    produces<float> ("pfsumet").setBranchAlias("pfsumet");
    produces<unsigned int> ("ntowers").setBranchAlias("ntowers");
    produces<std::vector<float> > ("calotowereta").setBranchAlias("calotower_eta");
    produces<std::vector<float> > ("calotowerphi").setBranchAlias("calotower_phi");
    produces<std::vector<float> > ("calotowerdetid").setBranchAlias("calotower_detid");
    produces<std::vector<float> > ("calotoweremEnergy").setBranchAlias("calotower_emEnergy");
    produces<std::vector<float> > ("calotowerhadEnergy").setBranchAlias("calotower_hadEnergy");
    produces<std::vector<float> > ("calotowerouterEnergy").setBranchAlias("calotower_outerEnergy");
    produces<std::vector<float> > ("calotoweremEt").setBranchAlias("calotower_emEt");
    produces<std::vector<float> > ("calotowerhadEt").setBranchAlias("calotower_hadEt");
    produces<std::vector<float> > ("calotowerouterEt").setBranchAlias("calotower_outerEt");


    primaryVertexInputTag_ = iConfig.getParameter<edm::InputTag>("primaryVertexInputTag");
    primaryVertexToken_ = consumes<reco::VertexCollection>(primaryVertexInputTag_);

    tracksInputTag_ = iConfig.getParameter<edm::InputTag>("tracksInputTag");
    tracksToken_ = consumes<reco::TrackCollection>(tracksInputTag_);

    pfJetsInputTag_ = iConfig.getParameter<edm::InputTag>   ("pfJetsInputTag");
    pfJetsToken_ = consumes<reco::PFJetCollection>(pfJetsInputTag_);

    pfCandidatesInputTag_ = iConfig.getParameter<edm::InputTag>   ("pfCandidatesInputTag");
    pfCandidatesToken_ = consumes<reco::PFCandidateCollection>(pfCandidatesInputTag_);

    pfMetInputTag_ = iConfig.getParameter<edm::InputTag>("pfMetInputTag");
    pfMetToken_ = consumes<edm::View<reco::PFMET> >(pfMetInputTag_);

    caloTowersInputTag_ = iConfig.getParameter<edm::InputTag>("caloTowersInputTag");
    caloTowersToken_ = consumes<CaloTowerCollection>(caloTowersInputTag_);

}


BabyMaker::~BabyMaker() {}

void  BabyMaker::beginJob() {
}

void BabyMaker::endJob() {
}


// ------------ method called to produce the data  ------------
void BabyMaker::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
  
    std::auto_ptr<unsigned int> nvertices (new unsigned int);
    std::auto_ptr<unsigned int> ntracks (new unsigned int);
    std::auto_ptr<unsigned int> ntracks_pt1 (new unsigned int);
    std::auto_ptr<unsigned int> ntracks_pt5 (new unsigned int);
    std::auto_ptr<unsigned int> ntracks_pt10 (new unsigned int);
    std::auto_ptr<std::vector<float> > track_pt (new std::vector<float>);
    std::auto_ptr<std::vector<float> > track_eta (new std::vector<float>);
    std::auto_ptr<std::vector<float> > track_phi (new std::vector<float>);
    std::auto_ptr<std::vector<float> > track_pt10_pt (new std::vector<float>);
    std::auto_ptr<std::vector<float> > track_pt10_eta (new std::vector<float>);
    std::auto_ptr<std::vector<float> > track_pt10_phi (new std::vector<float>);
    std::auto_ptr<unsigned int> npfjets (new unsigned int);
    std::auto_ptr<std::vector<float> > pfjet_pt (new std::vector<float>);
    std::auto_ptr<std::vector<float> > pfjet_eta (new std::vector<float>);
    std::auto_ptr<std::vector<float> > pfjet_phi (new std::vector<float>);
    std::auto_ptr<unsigned int> npfjets_pt20 (new unsigned int);
    std::auto_ptr<std::vector<float> > pfjet_pt20_pt (new std::vector<float>);
    std::auto_ptr<std::vector<float> > pfjet_pt20_eta (new std::vector<float>);
    std::auto_ptr<std::vector<float> > pfjet_pt20_phi (new std::vector<float>);
    std::auto_ptr<unsigned int> n_pf_ch (new unsigned int);
    std::auto_ptr<unsigned int> n_pf_e (new unsigned int);
    std::auto_ptr<unsigned int> n_pf_mu (new unsigned int);
    std::auto_ptr<unsigned int> n_pf_gamma (new unsigned int);
    std::auto_ptr<unsigned int> n_pf_nh (new unsigned int);
    std::auto_ptr<float> pfmet (new float);
    std::auto_ptr<float> pfmet_phi (new float);
    std::auto_ptr<float> pfsumet (new float);
    std::auto_ptr<unsigned int> ntowers (new unsigned int);
    std::auto_ptr<std::vector<float> > calotower_eta (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_phi (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_detid (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_emEnergy (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_hadEnergy (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_outerEnergy (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_emEt (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_hadEt (new std::vector<float>);
    std::auto_ptr<std::vector<float> > calotower_outerEt (new std::vector<float>);


    // get the primary vertices
    edm::Handle<reco::VertexCollection> vertexHandle;
    iEvent.getByToken(primaryVertexToken_, vertexHandle);
    const reco::VertexCollection *vertexCollection = vertexHandle.product();

    edm::Handle<reco::TrackCollection> trackHandle;
    iEvent.getByToken(tracksToken_, trackHandle);
    const reco::TrackCollection *trackCollection = trackHandle.product();

    edm::Handle<reco::PFJetCollection> pfJetsHandle;
    iEvent.getByToken(pfJetsToken_, pfJetsHandle);
 
    edm::Handle<reco::PFCandidateCollection> pfCandidatesHandle;
    iEvent.getByToken(pfCandidatesToken_, pfCandidatesHandle);

    edm::Handle<edm::View<reco::PFMET> > metHandle;
    iEvent.getByToken(pfMetToken_, metHandle);

    edm::Handle<CaloTowerCollection> calotowerHandle;
    iEvent.getByToken(caloTowersToken_,calotowerHandle);


    *nvertices = vertexCollection->size();
    *ntracks = trackCollection->size();

    int counter_ntracks_pt1 = 0;
    int counter_ntracks_pt5 = 0;
    int counter_ntracks_pt10 = 0;
    for(reco::TrackCollection::const_iterator i = trackHandle->begin(); i != trackHandle->end(); ++i) {
      track_pt->push_back(i->pt());
      track_eta->push_back(i->eta());
      track_phi->push_back(i->phi());

      if(i->pt() < 1.0) continue;
      counter_ntracks_pt1++;

      if(i->pt() < 5.0) continue;
      counter_ntracks_pt5++;

      if(i->pt() < 10.0) continue;
      counter_ntracks_pt10++;
      track_pt10_pt->push_back(i->pt());
      track_pt10_eta->push_back(i->eta());
      track_pt10_phi->push_back(i->phi());
    }
    *ntracks_pt1 = counter_ntracks_pt1;
    *ntracks_pt5 = counter_ntracks_pt5;
    *ntracks_pt10 = counter_ntracks_pt10;

    int counter_npfjets = 0;
    int counter_npfjets_pt20 = 0;
    for(reco::PFJetCollection::const_iterator pfjet_it = pfJetsHandle->begin(); pfjet_it != pfJetsHandle->end(); pfjet_it++) {
      counter_npfjets++;
      pfjet_pt->push_back(pfjet_it->pt());
      pfjet_eta->push_back(pfjet_it->eta());
      pfjet_phi->push_back(pfjet_it->phi());

      if(pfjet_it->pt() < 20.0) continue;

      counter_npfjets_pt20++;
      pfjet_pt20_pt->push_back(pfjet_it->pt());
      pfjet_pt20_eta->push_back(pfjet_it->eta());
      pfjet_pt20_phi->push_back(pfjet_it->phi());
    }
    *npfjets = counter_npfjets;
    *npfjets_pt20 = counter_npfjets_pt20;

    int counter_n_pf_ch = 0;
    int counter_n_pf_e = 0;
    int counter_n_pf_mu = 0;
    int counter_n_pf_gamma = 0;
    int counter_n_pf_nh = 0;

    for(reco::PFCandidateCollection::const_iterator cand_it = pfCandidatesHandle->begin(); cand_it != pfCandidatesHandle->end(); cand_it++){
      //std::cout << cand_it->particleId() << std::endl;
      if(cand_it->particleId() == 1) counter_n_pf_ch++;
      if(cand_it->particleId() == 2) counter_n_pf_e++;
      if(cand_it->particleId() == 3) counter_n_pf_mu++;
      if(cand_it->particleId() == 4) counter_n_pf_gamma++;
      if(cand_it->particleId() == 5) counter_n_pf_nh++;
    }
    *n_pf_ch = counter_n_pf_ch;
    *n_pf_e = counter_n_pf_e;
    *n_pf_mu = counter_n_pf_mu;
    *n_pf_gamma = counter_n_pf_gamma;
    *n_pf_nh = counter_n_pf_nh;

    *pfmet    = ( metHandle->front() ).et();
    *pfmet_phi = ( metHandle->front() ).phi();
    *pfsumet  = ( metHandle->front() ).sumEt();


    *ntowers = 0;
    for (CaloTowerCollection::const_iterator j = calotowerHandle->begin();j !=calotowerHandle->end(); j++) {
      (*ntowers) += 1;

      calotower_eta->push_back(j->eta());
      calotower_phi->push_back(j->phi());
      calotower_detid->push_back(j->id().rawId());

      calotower_emEnergy->push_back(j->emEnergy());
      calotower_hadEnergy->push_back(j->hadEnergy());
      calotower_outerEnergy->push_back(j->outerEnergy());

      calotower_emEt->push_back(j->emEt());
      calotower_hadEt->push_back(j->hadEt());
      calotower_outerEt->push_back(j->outerEt());
    }


    iEvent.put(nvertices, "nvertices" );
    iEvent.put(ntracks, "ntracks" );
    iEvent.put(ntracks_pt1, "ntrackspt1" );
    iEvent.put(ntracks_pt5, "ntrackspt5" );
    iEvent.put(ntracks_pt10, "ntrackspt10" );
    iEvent.put(track_pt, "trackpt" );
    iEvent.put(track_eta, "tracketa" );
    iEvent.put(track_phi, "trackphi" );
    iEvent.put(track_pt10_pt, "trackpt10pt" );
    iEvent.put(track_pt10_eta, "trackpt10eta" );
    iEvent.put(track_pt10_phi, "trackpt10phi" );
    iEvent.put(npfjets, "npfjets" );
    iEvent.put(pfjet_pt, "pfjetpt" );
    iEvent.put(pfjet_eta, "pfjeteta" );
    iEvent.put(pfjet_phi, "pfjetphi" );
    iEvent.put(npfjets_pt20, "npfjetspt20" );
    iEvent.put(pfjet_pt20_pt, "pfjetpt20pt" );
    iEvent.put(pfjet_pt20_eta, "pfjetpt20eta" );
    iEvent.put(pfjet_pt20_phi, "pfjetpt20phi" );
    iEvent.put(n_pf_ch, "npfch" );
    iEvent.put(n_pf_e, "npfe" );
    iEvent.put(n_pf_mu, "npfmu" );
    iEvent.put(n_pf_gamma, "npfgamma" );
    iEvent.put(n_pf_nh, "npfnh" );
    iEvent.put(pfmet, "pfmet" );
    iEvent.put(pfmet_phi, "pfmetphi" );
    iEvent.put(pfsumet, "pfsumet" );
    iEvent.put(calotower_eta, "calotowereta" );
    iEvent.put(calotower_phi, "calotowerphi" );
    iEvent.put(calotower_detid, "calotowerdetid" );
    iEvent.put(calotower_emEnergy, "calotoweremEnergy" );
    iEvent.put(calotower_hadEnergy, "calotowerhadEnergy" );
    iEvent.put(calotower_outerEnergy, "calotowerouterEnergy" );
    iEvent.put(calotower_emEt, "calotoweremEt" );
    iEvent.put(calotower_hadEt, "calotowerhadEt" );
    iEvent.put(calotower_outerEt, "calotowerouterEt" );
    iEvent.put(ntowers, "ntowers" );
}

//define this as a plug-in
DEFINE_FWK_MODULE(BabyMaker);
