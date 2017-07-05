/* simple example of how to loop over events with AnitaDataset 
 *
 * To run this, Set ANITA_ROOT_DATA to the data downloaded by the script in this directory. 
 *
 * Otherwise you'll get an ugly crash
 *
 **/ 
 


void loopOverEvents(int run=2017) 
{



  //Initialize the dataset
  AnitaDataset d(run); 

  //loop over AnitaDataset
  for (int i = 0; i < d.N(); i++) 
  {
    //get the ith entry
    d.getEntry(i); 

    std::cout << "---------------------------------------------------------" << std::endl; 
    std::cout << "I am the event with index " <<i << std::endl; 
    std::cout << "My timestamp is " <<  d.header()->triggerTime << std::endl; 
  }
} 

