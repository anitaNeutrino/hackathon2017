# Finding Neutrinos

The mock data you downloaded are mostly simulated `icemc` thermal noise, but there are a few neutrinos in there! 

There are example macros for running both the `UCorrelator` and `ACCLAIM` that analyze the datasets and produce summary output files. 

Run them to produce some output trees (note that the `UCorrelator` example by default only does the first 100 events, either pass arguments or modify to do everything). 

Then open the output trees (e.g. `root ucorrelator_2017.root` , and use the summary variables to find the neutrinos! 


## Example plots: 

Here `tree` is the name of the output tree in the file (defined in the macro, by default either `haxx` for the `UCorrelator` macro or `sumTree` for `ACCLAIM` macro). )  


```
 tree->Draw("deconvolved[1][0].peakHilbert:peak[1][0].value"); 
```

