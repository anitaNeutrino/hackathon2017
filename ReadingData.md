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

To start using it, you'll need some data. We have prepared a mock dataset. You can download it by running the downloadMockData.sh script. 

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


## A little fun


In our case, if you are inside the hackathon2017 directory and you ran the `downloadMockData.sh` script, you can do: 

```
    export ANITA_ROOT_DATA=`pwd`/data 
```


Now let's play with `AnitaDataset` in a terminal: 


```
root [0] AnitaDataset d(2017)
Using head file: /home/cozzyd/Documents/slides/ANITA_Collaboration_Meeting/hackathon2017/data/run2017/SimulatedAnitaHeadFile2017.root
Could not find hk file for run 2017, no HK will be available!
Could not find TurfRate file for run 2017, no Turf will be available!
Could not find SurfHK file for run 2017, no SURF will be available!
(AnitaDataset &) @0x7f58efdee000
root [1] d.getEntry(10)
(int) 10
root [2] d.header()
(RawAnitaHeader *) 0x55d9bf02ef30
root [3] d.useful()
(UsefulAnitaEvent *) 0x55d9c07fb240
root [4] d.gps()
(Adu5Pat *) 0x55d9c07a8fb0
root [5] d.gps()->heading
(Float_t) 254.157f
root [6] d.header()->triggerTime
(UInt_t) 1420691595
```


##ANITA versions

Currently, it is possible to use both ANITA-3 and ANITA-4 data with the same softare. In general you can set or get using `AnitaVersion::set()` and `AnitaVersion::get().`  When you use `AnitaDataset` it should detect the appropriate version based on the timestamp (even for MC data!). 

```
root [7] AnitaVersion::get()
(int) 3

```

## Example macro 

See `loopOverEvents.C` for a minimally working example. 







  
     
