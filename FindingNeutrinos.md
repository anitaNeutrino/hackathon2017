# Finding Neutrinos

The mock data you downloaded are mostly simulated `icemc` thermal noise, but there are a few neutrinos in there! 

There are example macros for running both the `UCorrelator` and `ACCLAIM` that analyze the datasets and produce summary output files. 

Run them to produce some output trees (note that the `UCorrelator` example by default only does the first 100 events, either pass arguments or modify to do everything). 

Then open the output trees (e.g. `root ucorrelator_2017.root` , and use the summary variables to find the neutrinos! 


## Example plots: 

The canonical ANITA neutrino cut is based on the waveform hilbert envelope peak
and interferometric map value. Here's how you can plot it.  Here `tree` is the
name of the output tree in the file (defined in the macro, by default either
`haxx` for the `UCorrelator` macro or `sumTree` for `ACCLAIM` macro). )  

```
 tree->Draw("deconvolved[1][0].peakHilbert:peak[1][0].value"); 
```

## Help me, I've never used `ROOT` `TTree`'s before

A general introduction to `ROOT` `TTree`'s is beyond the scope of this hackathon, but here are potentially useful links:

https://root.cern.ch/root/htmldoc/guides/users-guide/ROOTUsersGuide.html#simple-analysis-using-ttreedraw

https://www.nevis.columbia.edu/~seligman/root-class/



