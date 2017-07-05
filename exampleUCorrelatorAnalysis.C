/* simple example of how to fill an output tree with UCorrelator. 
 *
 * To run this, Set ANITA_ROOT_DATA to the data downloaded by the script in this directory. 
 *
 * Otherwise you'll get an ugly crash
 *
 **/ 

/* ROOT doesn't know how to smartly pick up namespaces. sad. */ 
#include "FFTtools.h" 
#include "UCFilters.h" 


void exampleUCorrelatorAnalysis(int run=2017, int max = 100) 
{


  /* load the wisdom, if it's there */ 
  FFTtools::loadWisdom("magicwisdom.dat"); 

  //Initialize the dataset
  AnitaDataset d(run); 

  //Initialize a filter strategy with the default UCorrelator filter This
  //automatically adds an ALFA filter for A3 data (like this); Normally, you
  //want an adaptive filter, but it requires either generating the spectral
  //averages on the fly (slow) or precreating / downloading them which is
  //outside the scope of the hackathon
  FilterStrategy strategy; 
  UCorrelator::fillStrategyWithKey(&strategy, "sinsub_10_3"); 

  /*This is the default cfg, you can change stuff if you want */
  UCorrelator::AnalysisConfig cfg;

  /* Use Ben Rotter's impulse response */ 
  cfg.response_option = UCorrelator::AnalysisConfig::ResponseIndividualBRotter; 
  cfg.deconvolution_method = new AnitaResponse::AllPassDeconvolution; 

  //Initialize the analyzer 
  UCorrelator::Analyzer analyzer(&cfg); 

  //Create an output file
  TFile output(max ? TString::Format("ucorrelator_%d_max%d.root",run,max) : TString::Format("ucorrelator_%d.root",run),"RECREATE"); 

  //Create the summary that we will fill and put into a tree
  AnitaEventSummary * sum = new AnitaEventSummary; 

  //create the output tree. We'll name it haxx. It sounds nice! 
  TTree * tree = new TTree("haxx","Hackathon tree!"); 

  //store the summary in the tree
  tree->Branch("sum",&sum); 

  //loop over AnitaDataset (until max if max !=0 ) 
  for (int i = 0; i < (max ? max : d.N()) ; i++) 
  {
    //get the ith entry
    d.getEntry(i); 

    std::cout << "(on event " << i << ")" << std::endl; 

    //Create the FilteredAnitaEvent, which applies the filter and knows about all the waveforms!
    FilteredAnitaEvent ev(d.useful(), &strategy, d.gps(), d.header()); 
    analyzer.analyze(&ev, sum,d.truth()); 

    // Fill the tree!
    output.cd();
    tree->Fill(); 
  }

  //Write the tree! 
  output.cd(); 
  tree->Write(); 

  //Save the wisdom 
  FFTtools::saveWisdom("magicwisdom.dat"); 
} 

