#!/bin/bash

pushd .

cd babyNtuple/CMSSW_7_2_0_pre5/src
cmsenv

nohup cmsRun python/newMixing.py > newMixing.log 2>&1 &
nohup cmsRun python/oldMixing.py > oldMixing.log 2>&1 &

popd

echo 2 jobs running in background
