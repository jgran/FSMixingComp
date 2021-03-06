#!/bin/bash

BASEDIR=`pwd`

mkdir newMixing
mkdir oldMixing
mkdir newMinBias
mkdir oldMinBias
mkdir babyNtuple

export SCRAM_ARCH=slc6_amd64_gcc481

cd newMixing
cmsrel CMSSW_7_2_0_pre5
cd CMSSW_7_2_0_pre5/src
cmsenv
git cms-addpkg FastSimulation/Configuration
scram b -j20
sed -i "s/MixingMode = 'GenMixing'/#MixingMode = 'GenMixing'/" FastSimulation/Configuration/python/CommonInputs_cff.py
sed -i "s/#MixingMode = 'DigiRecoMixing'/MixingMode = 'DigiRecoMixing'/" FastSimulation/Configuration/python/CommonInputs_cff.py
sed -i "s,root://eoscms//eos/cms/store/user/federica/FastSim/MinBias_620/MinBias_8TeV_cfi_GEN_SIM_RECO.root,file:$BASEDIR/newMinBias/CMSSW_7_2_0_pre5/src/newMinBias.root,g" FastSimulation/Configuration/python/mixHitsAndTracksWithPU_cfi.py
mkdir newMixing1
cp $BASEDIR/config/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_1.py newMixing1/
sed -i "s,FILELOCATION,$BASEDIR/newMinBias/CMSSW_7_2_0_pre5/src/newMinBias.root,g" newMixing1/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_1.py
mkdir newMixing2
cp $BASEDIR/config/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_2.py newMixing2/
sed -i "s,FILELOCATION,$BASEDIR/newMinBias/CMSSW_7_2_0_pre5/src/newMinBias.root,g" newMixing2/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_2.py
mkdir newMixing3
cp $BASEDIR/config/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_3.py newMixing3/
sed -i "s,FILELOCATION,$BASEDIR/newMinBias/CMSSW_7_2_0_pre5/src/newMinBias.root,g" newMixing3/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_3.py
mkdir newMixing4
cp $BASEDIR/config/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_4.py newMixing4/
sed -i "s,FILELOCATION,$BASEDIR/newMinBias/CMSSW_7_2_0_pre5/src/newMinBias.root,g" newMixing4/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_4.py
mkdir newMixing5
cp $BASEDIR/config/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_5.py newMixing5/
sed -i "s,FILELOCATION,$BASEDIR/newMinBias/CMSSW_7_2_0_pre5/src/newMinBias.root,g" newMixing5/newMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_5.py
cd $BASEDIR

cd oldMixing
cmsrel CMSSW_7_2_0_pre5
cd CMSSW_7_2_0_pre5/src
mkdir oldMixing1
cp $BASEDIR/config/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_1.py oldMixing1/
sed -i "s,FILELOCATION,$BASEDIR/oldMinBias/CMSSW_7_2_0_pre5/src/oldMinBias.root,g" oldMixing1/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_1.py
mkdir oldMixing2
cp $BASEDIR/config/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_2.py oldMixing2/
sed -i "s,FILELOCATION,$BASEDIR/oldMinBias/CMSSW_7_2_0_pre5/src/oldMinBias.root,g" oldMixing2/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_2.py
mkdir oldMixing3
cp $BASEDIR/config/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_3.py oldMixing3/
sed -i "s,FILELOCATION,$BASEDIR/oldMinBias/CMSSW_7_2_0_pre5/src/oldMinBias.root,g" oldMixing3/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_3.py
mkdir oldMixing4
cp $BASEDIR/config/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_4.py oldMixing4/
sed -i "s,FILELOCATION,$BASEDIR/oldMinBias/CMSSW_7_2_0_pre5/src/oldMinBias.root,g" oldMixing4/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_4.py
mkdir oldMixing5
cp $BASEDIR/config/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_5.py oldMixing5/
sed -i "s,FILELOCATION,$BASEDIR/oldMinBias/CMSSW_7_2_0_pre5/src/oldMinBias.root,g" oldMixing5/oldMixing_NeutrinoGun_cfi_GEN_SIM_RECO_PU_5.py
cd $BASEDIR

cd newMinBias
cmsrel CMSSW_7_2_0_pre5
cd CMSSW_7_2_0_pre5/src
cd $BASEDIR

cd oldMinBias
cmsrel CMSSW_7_0_0
cd CMSSW_7_0_0/src
cp $BASEDIR/config/MinBias_for_GEN_mixing.py .
cd $BASEDIR

cd babyNtuple
cmsrel CMSSW_7_2_0_pre5
cd CMSSW_7_2_0_pre5/src
cp -r $BASEDIR/Study .
scram b -j20
cd Study/BabyMaker/python
sed -i "s,FILELOCATION1,$BASEDIR/oldMixing/CMSSW_7_2_0_pre5/src/oldMixing1/oldMixing_NeutrinoGun_GEN_SIM_RECO_PU_1.root,g" oldMixing.py
sed -i "s,FILELOCATION2,$BASEDIR/oldMixing/CMSSW_7_2_0_pre5/src/oldMixing2/oldMixing_NeutrinoGun_GEN_SIM_RECO_PU_2.root,g" oldMixing.py
sed -i "s,FILELOCATION3,$BASEDIR/oldMixing/CMSSW_7_2_0_pre5/src/oldMixing3/oldMixing_NeutrinoGun_GEN_SIM_RECO_PU_3.root,g" oldMixing.py
sed -i "s,FILELOCATION4,$BASEDIR/oldMixing/CMSSW_7_2_0_pre5/src/oldMixing4/oldMixing_NeutrinoGun_GEN_SIM_RECO_PU_4.root,g" oldMixing.py
sed -i "s,FILELOCATION5,$BASEDIR/oldMixing/CMSSW_7_2_0_pre5/src/oldMixing5/oldMixing_NeutrinoGun_GEN_SIM_RECO_PU_5.root,g" oldMixing.py
sed -i "s,FILELOCATION1,$BASEDIR/newMixing/CMSSW_7_2_0_pre5/src/newMixing1/newMixing_NeutrinoGun_GEN_SIM_RECO_PU_1.root,g" newMixing.py
sed -i "s,FILELOCATION2,$BASEDIR/newMixing/CMSSW_7_2_0_pre5/src/newMixing2/newMixing_NeutrinoGun_GEN_SIM_RECO_PU_2.root,g" newMixing.py
sed -i "s,FILELOCATION3,$BASEDIR/newMixing/CMSSW_7_2_0_pre5/src/newMixing3/newMixing_NeutrinoGun_GEN_SIM_RECO_PU_3.root,g" newMixing.py
sed -i "s,FILELOCATION4,$BASEDIR/newMixing/CMSSW_7_2_0_pre5/src/newMixing4/newMixing_NeutrinoGun_GEN_SIM_RECO_PU_4.root,g" newMixing.py
sed -i "s,FILELOCATION5,$BASEDIR/newMixing/CMSSW_7_2_0_pre5/src/newMixing5/newMixing_NeutrinoGun_GEN_SIM_RECO_PU_5.root,g" newMixing.py
cd $BASEDIR

cd analyze
sed -i "s,NEWMIXINGFILES,$BASEDIR/babyNtuple/CMSSW_7_2_0_pre5/src/Study/BabyMaker/newMixing.root,g" doAll.C
sed -i "s,OLDMIXINGFILES,$BASEDIR/babyNtuple/CMSSW_7_2_0_pre5/src/Study/BabyMaker/oldMixing.root,g" doAll.C
cd $BASEDIR
