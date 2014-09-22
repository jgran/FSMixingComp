#!/bin/bash

pushd .

cd newMixing/CMSSW_7_2_0_pre5/src
cmsenv

cd newMixing1
nohup nice -5 cmsRun newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_1.py > run1.log 2>&1 &
cd ..

cd newMixing2
nohup nice -5 cmsRun newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_2.py > run2.log 2>&1 &
cd ..

cd newMixing3
nohup nice -5 cmsRun newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_3.py > run3.log 2>&1 &
cd ..

cd newMixing4
nohup nice -5 cmsRun newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_4.py > run4.log 2>&1 &
cd ..

cd newMixing5
nohup nice -5 cmsRun newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_5.py > run5.log 2>&1 &

popd

echo 5 jobs running in background
