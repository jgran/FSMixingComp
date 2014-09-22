# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: SingleElectronFlatPt5To100_cfi -s GEN,SIM,RECO --fast --pileup 2012_Summer_inTimeOnly --conditions auto:startup_GRun --beamspot Realistic8TeVCollision --eventcontent=FEVTDEBUGHLT --datatier GEN-SIM-DIGI-RECO -n 10
import FWCore.ParameterSet.Config as cms

process = cms.Process('RECO')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('FastSimulation.Configuration.EventContent_cff')
process.load('FastSimulation.PileUpProducer.PileUpSimulator_2012_Summer_inTimeOnly_cff')
process.load('FastSimulation.Configuration.Geometries_START_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedParameters_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('FastSimulation.Configuration.FamosSequences_cff')
process.load('FastSimulation.Configuration.FamosSequences_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(5000) # XXX 5k evts
)

# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.19 $'),
    annotation = cms.untracked.string('SingleNeutrinoFlatPt2To20_cfi nevts:1000'),
    name = cms.untracked.string('Applications')
)

# Output definition

process.FEVTDEBUGHLToutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(1048576),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    fileName = cms.untracked.string('oldMixing_NeutrinoGun_GEN_SIM_RECO_PU_5.root'), # XXX jobnum
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN-SIM-DIGI-RECO')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

offs = 50 # XXX 10*{jobnum}
process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    generator = cms.PSet(
        initialSeed = cms.untracked.uint32(offs+0),
        engineName = cms.untracked.string('HepJamesRandom')
    ),
    mixGenPU = cms.PSet( initialSeed = cms.untracked.uint32(                         offs+1 ) ),
    mix = cms.PSet( initialSeed = cms.untracked.uint32(                              offs+2 ) ),
    famosSimHits = cms.PSet( initialSeed = cms.untracked.uint32(                     offs+3 ) ),
    MuonSimHits = cms.PSet( initialSeed = cms.untracked.uint32(                      offs+4 ) ),
    siTrackerGaussianSmearingRecHits = cms.PSet( initialSeed = cms.untracked.uint32( offs+5 ) ),
    simMuonCSCDigis = cms.PSet( initialSeed = cms.untracked.uint32(                  offs+6 ) ),
    simMuonDTDigis = cms.PSet( initialSeed = cms.untracked.uint32(                   offs+7 ) ),
    simMuonRPCDigis = cms.PSet( initialSeed = cms.untracked.uint32(                  offs+8 ) ),
    
    famosPileUp = cms.PSet( initialSeed = cms.untracked.uint32(                     offs+9 ) ),
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
process.famosSimHits.SimulateCalorimetry = True
process.famosSimHits.SimulateTracking = True
process.Realistic8TeVCollisionVtxSmearingParameters.type = cms.string("BetaFunc")
process.famosSimHits.VertexGenerator = process.Realistic8TeVCollisionVtxSmearingParameters
process.famosPileUp.VertexGenerator = process.Realistic8TeVCollisionVtxSmearingParameters
process.famosPileUp.PileUpSimulator.fileNames = cms.untracked.vstring('file:FILELOCATION')
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:startup_GRun', '')

process.generator = cms.EDProducer("FlatRandomPtGunProducer",
    PGunParameters = cms.PSet(
        MinPhi = cms.double(-3.14159265359),
        MinPt = cms.double(2),
        PartID = cms.vint32(12),
        MaxEta = cms.double(3),
        MaxPhi = cms.double(3.14159265359),
        MinEta = cms.double(-3),
        MaxPt = cms.double(20)
    ),
    Verbosity = cms.untracked.int32(0),
    psethack = cms.string('single neutrino 2<Pt<20 -3<Eta<3'),
    AddAntiParticle = cms.bool(False)
)


# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen_genonly)
process.simulation_step = cms.Path(process.simulationWithFamos)
process.reconstruction_step = cms.Path(process.reconstructionWithFamos)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.FEVTDEBUGHLToutput_step = cms.EndPath(process.FEVTDEBUGHLToutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.reconstruction_step,process.endjob_step,process.FEVTDEBUGHLToutput_step)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.generator * getattr(process,path)._seq 


