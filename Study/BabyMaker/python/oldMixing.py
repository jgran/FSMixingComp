import FWCore.ParameterSet.Config as cms

process = cms.Process('FSVAL')

process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Study.BabyMaker.puSummaryInfoMaker_cfi')
process.load('Study.BabyMaker.babyMaker_cfi')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
                                      'file:FILELOCATION1',
                                      'file:FILELOCATION2',
                                      'file:FILELOCATION3',
                                      'file:FILELOCATION4',
                                      'file:FILELOCATION5'
    )
)   

process.out = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring(
        'drop *',
        'keep *_*Maker*_*_FSVAL*'
    ),  
    fileName = cms.untracked.string('oldMixing.root')
)

process.outpath = cms.EndPath(process.out)
process.p = cms.Path(process.babyMaker * process.puSummaryInfoMaker)
