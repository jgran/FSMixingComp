#!/bin/bash

pushd .

cd oldMixing/CMSSW_7_2_0_pre5/src
cmsenv

cd oldMixing1
nohup nice -5 cmsRun oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_1.py > run1.log 2>&1 &
cd ..

cd oldMixing2
nohup nice -5 cmsRun oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_2.py > run2.log 2>&1 &
cd ..

cd oldMixing3
nohup nice -5 cmsRun oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_3.py > run3.log 2>&1 &
cd ..

cd oldMixing4
nohup nice -5 cmsRun oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_4.py > run4.log 2>&1 &
cd ..

cd oldMixing5
nohup nice -5 cmsRun oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_5.py > run5.log 2>&1 &

popd

echo 5 jobs running in background
