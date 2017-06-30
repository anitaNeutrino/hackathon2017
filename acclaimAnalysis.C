
// event reader
#include "AnitaDataset.h"

// analysis framework
#include "FilterStrategy.h"
#include "FilteredAnitaEvent.h"

// acclaim
#include "ProgressBar.h"
#include "AcclaimFilters.h"
#include "OutputConvention.h"
#include "AnalysisReco.h"

void acclaimAnalysis(){

  AnitaDataset d(2017);

  Long64_t n = d.N();
  Acclaim::ProgressBar p(n);

  Acclaim::AnalysisReco reco;

  FilterStrategy* filterStrat = Acclaim::Filters::findDefaultStrategy("Minimum");

  TFile* fOut =  new TFile("acclaimAnalysis.root", "recreate");
  TTree* sumTree = new TTree("sumTree", "This is a ttree of AnitaEventSummaries");

  AnitaEventSummary* sum = NULL;
  sumTree->Branch("sum", &sum);
  
  for(Long64_t entry=0; entry < n; entry++){

    d.getEntry(entry);

    FilteredAnitaEvent f(d.useful(), filterStrat, d.gps(), d.header());

    reco.process(&f, d.gps(), sum);
    sumTree->Fill();
    p++;
  }

  fOut->Write();
  
  return;

}
