#ifndef BabyMaker_H
#define BabyMaker_H

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
//#include "DataFormats/CaloTowers/interface/CaloTowerFwd.h"
//#include "DataFormats/CaloTowers/interface/CaloTower.h"

//#include "Geometry/Records/interface/CaloGeometryRecord.h"
//#include "Geometry/CaloTopology/interface/CaloTopology.h"
//#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"

class BabyMaker : public edm::EDProducer {
public:
    explicit BabyMaker (const edm::ParameterSet&);
    ~BabyMaker();

private:
    virtual void beginJob() ;
    virtual void produce(edm::Event&, const edm::EventSetup&);
    virtual void endJob() ;

    // ----------member data ---------------------------
    edm::InputTag primaryVertexInputTag_;
    edm::EDGetTokenT<reco::VertexCollection> primaryVertexToken_;
    edm::InputTag tracksInputTag_;
    edm::EDGetTokenT<reco::TrackCollection> tracksToken_;
    edm::InputTag pfJetsInputTag_;
    edm::EDGetTokenT<reco::PFJetCollection> pfJetsToken_;
    edm::InputTag pfCandidatesInputTag_;
    edm::EDGetTokenT<reco::PFCandidateCollection> pfCandidatesToken_;
    edm::InputTag pfMetInputTag_;
    edm::EDGetTokenT<edm::View<reco::PFMET> > pfMetToken_;
    edm::InputTag caloTowersInputTag_;
    edm::EDGetTokenT<CaloTowerCollection> caloTowersToken_;
    
};
#endif
