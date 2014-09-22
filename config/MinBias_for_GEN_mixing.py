import FWCore.ParameterSet.Config as cms
process = cms.Process("PileUp")

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(25000)
)

process.RandomNumberGeneratorService = cms.Service(
    "RandomNumberGeneratorService",
    prodPU = cms.PSet(
        initialSeed = cms.untracked.uint32(123),
        engineName = cms.untracked.string('TRandom3')
        ),
    generator = cms.PSet(
        initialSeed = cms.untracked.uint32(42),
        engineName = cms.untracked.string('HepJamesRandom')
        ),
    )

randomEngineStateProducer = cms.EDProducer("RandomEngineStateProducer")

process.load("Configuration.Generator.MinBias_13TeV_cfi")

process.prodPU = cms.EDProducer("producePileUpEvents",
    PUParticleFilter = cms.PSet(
        # Protons with energy larger than EProton (GeV) are all kept
        EProton = cms.double(5000.0),
        # Particles with |eta| > etaMax (momentum direction at primary vertex) 
        # are not simulated - 7.0 includes CASTOR (which goes to 6.6) 
        etaMax = cms.double(7.0),
        # Charged particles with pT < pTMin (GeV/c) are not simulated
        pTMin = cms.double(0.0),
        # Particles with energy smaller than EMin (GeV) are not simulated
        EMin = cms.double(0.0)
    ),
    PUEventFile = cms.untracked.string('MinBias13TeV_0.root'),
    SavePileUpEvents = cms.bool(True),
    BunchPileUpEventSize = cms.uint32(1000)
)

outputType = 'ntuple'

process.source = cms.Source("EmptySource")
process.p = cms.Path(process.generator*process.prodPU)
