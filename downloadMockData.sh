#! /usr/bin/env sh 
# This script downloads the mock ANITA dataset used at the Hackathon
# This dataset consists of minbias ANITA-3 triggers with some neutrinos added in some places
# Your mission is to find the neutrinos! 

run=2017
url_uchicago=http://users.rcc.uchicago.edu/~cozzyd/hackathon_inputs/
url_ucl=http://www.hep.ucl.ac.uk/~lindac/inputsForHackathon/
url=$url_uchicago

mkdir -p data/run$run
curl $url/SimulatedAnitaEventFile.root > data/run$run/SimulatedAnitaEventFile$run.root
curl $url/SimulatedAnitaHeadFile.root > data/run$run/SimulatedAnitaHeadtFile$run.root
curl $url/SimulatedAnitaTruthFile.root > data/run$run/SimulatedAnitaTruthFile$run.root
curl $url/SimulatedAnitaGpsFile.root > data/run$run/SimulatedAnitaGpsFile$run.root







