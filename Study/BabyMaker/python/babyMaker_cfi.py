import FWCore.ParameterSet.Config as cms

babyMaker = cms.EDProducer("BabyMaker",
                            primaryVertexInputTag = cms.InputTag("offlinePrimaryVertices"),
                            tracksInputTag = cms.InputTag("generalTracks"),
                            pfJetsInputTag = cms.InputTag("ak4PFJetsCHS"),
                            pfCandidatesInputTag = cms.InputTag("particleFlow"),
                            pfMetInputTag = cms.InputTag("pfMet"),
                            caloTowersInputTag = cms.InputTag("towerMaker")

                            #photonInputTag_   = cms.InputTag("hltEgammaCandidates"),
                            #candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
                            #isoTag = cms.InputTag( "hltEgammaHoverE" ),
                            #HOverEInputTag_   = cms.InputTag("hltEgammaHoverE")
)


