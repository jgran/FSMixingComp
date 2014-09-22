#!/bin/bash

cd newMinBias/CMSSW_7_2_0_pre5/src
cmsenv
echo --Making 5000 MinBias events for new mixing, job running in background
echo --Running: cmsDriver.py MinBias_13TeV_cfi -s GEN,SIM,RECO --conditions auto:startup_GRun --eventcontent=FASTPU --fast --fileout newMinBias.root  -n 5000
nohup cmsDriver.py MinBias_13TeV_cfi -s GEN,SIM,RECO --conditions auto:startup_GRun --eventcontent=FASTPU --fast --fileout newMinBias.root  -n 5000 > newMinBias.log 2>&1 &
PWD=`pwd`
echo --log file: $PWD/newMinBias.log
cd ../../..
