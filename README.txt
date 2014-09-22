Setup:
source setup.sh

Generate MinBias file for old mixing:
source makeOldMinBias.sh

Generate MinBias file for new mixing:
source makeNewMinBias.sh

Run jobs to make 25k GEN-SIM-RECO neutrino gun events with old mixing:
source makeOldMixing.sh

Run jobs to make 25k GEN-SIM-RECO neutrino gun events with new mixing:
source makeNewMixing.sh

Make baby ntuple with variables to make plots
source makeBabyNtuples.sh
 
Make plots from baby ntuples
source makePlots.sh
