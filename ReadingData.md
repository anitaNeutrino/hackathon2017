# Reading data programmatically
---

## Introduction
The recommended entry point for reading ANITA events for most use cases is the `AnitaDataset` class.

The constructor looks like: 
```
  AnitaDataset (int run, bool decimated=false, WaveCalType::WaveCalType_t cal=WaveCalType::kDefault, DataDirectory dir=ANITA_ROOT_DATA, BlindingStrategy strat=AnitaDataset::kDefault)
```

The arguments are as followed: 
1. ANITA data is semi-arbitrarily divided into runs. The run number is the first argument.
2. Some blinding strategies (e.g. ANITA-3) have an associated 10 percent dataset. If you pass `true` for the second argument, that will be used. 
3. The calibration converts the raw digitizer data into usable time vs. voltage data. In most cases you want to use `WaveCalType::kDefault`
4. The place to look for data. By default it's `ANITA_ROOT_DATA` but there are some other options (for example for MC). 
5. The blinding strategy. Probably some day argument 2 should be folded into argument 5. For now don't worry about this too much. 

To start using it, you'll need some data. We have prepared a mock dataset. 
It uses the `ANITA_ROOT_DATA` environmental variable to figure out where to look for things. Your data should look like


    /path/to/somedir/ 
      runN/
          A bunch of ROOT files
      runN+1
          ... 
      etc.
     
For a `bash` shell (which most people are likely using), you can do

```
    export ANITA_ROOT_DATA=/path/to/somedir
```




  
     
