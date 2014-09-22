#!/bin/bash

BASEDIR=`pwd`

cd analyze
make
root -b -q doAll.C
root -b -q MakePlots.C
echo --Plots in $BASEDIR/analyze/plots/
