#!/bin/bash

cd oldMinBias/CMSSW_7_2_0_pre5/src
cmsenv
echo --Making 25000 MinBias events for old mixing, job running in background
nohup cmsRun MinBias_for_GEN_mixing.py > oldMinBias.log 2>&1 &
PWD=`pwd`
echo --log file: $PWD/oldMinBias.log
cd ../../..
