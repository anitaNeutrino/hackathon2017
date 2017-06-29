# Simulating neutrinos using IceMC
---

## Introduction

IceMC is the ANITA simulation tool. It has the capability to simulate
neutrinos at different constant energies or following a specific
theoretical spectrum.

The neutrinos are simulated in the ice, and their probability of
getting to the payload is calculated. If the neutrino would have
trigger ANITA, then the event is saved.

Each event is also weighted considering the probability of such event
really happening.

## How to run icemc

If you installed icemc by itself using `make`, the executables will
just be in the main directory.
If you installed icemc using the `anitaBuildTool` the executables will
be in the `anitaBuildTool/build/components/icemc/`.

In our case, if you are inside the hackathon2017 you may want to
move to the icemc main directory and create a symbolic link to the executable:
```
   cd 	/my/path/to/anitaBuildTool/components/icemc/
   ln -s /my/path/to/anitaBuildTool/build/components/icemc/icemc
   ```


From the command line do
``` ./icemc -i {inputFile} -o {outputDirectory} -r {runNumber} -n {numberOfNeutrinos}  -e {energyExponent}
```
If parameters are not specified

   * inputs from inputs.conf are used
   * the output directory is output
   * the run number is 0
   * number of neutrinos to generate as is input file
   * trigger threshold for full band as defined in anita.hh for that flight

## ANITA formatted data output ##

To produce Anita-like output files, you must have the [libRootFftwWrapper](https://github.com/nichol77/libRootFftwWrapper) and [eventReaderRoot](https://github.com/anitaNeutrino/eventReaderRoot) libraries installed before compiling icemc.

After that you will need to find and uncomment the site specific flag `ANITA3_EVENTREADER=1` in the Makefile.
The next time you compile and run icemc, the ANITA-like outputs will be produced automatically.
The outputs also include the TruthAnitaEvent tree with the Monte Carlo truth information about the simulated events.

## ANITA-3 notes ##

 * If you want to generate anita-3 simulations with the impulse response and noise you should turn on the flags in the input file as by default they are off

* If you want to generate a pure thermal noise sample you should to turn on these flags:
     * Set signal to 0 to measure noise hits
     * skip cuts on neutrinos that won’t reach the payload (this is just to have it running quicker as we 0’ed the signal anyway)
     * Min bias flag (so that everything gets saved)

