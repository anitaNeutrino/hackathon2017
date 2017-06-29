# Event Display
---

`MagicDisplay` is our event display. Let's play with it. First make sure you have our mock dataset (see ReadingData.md for more details) 


```
root doMagicDisplay.C 
```

`MagicDisplay` should have popped up. Some hints:

- Press `?` for helpful shortcuts
- You can run both `UCorrelator` and `ACCLAIM` analyses on single events 
- The analyses may seem slow (as might filtering). This is because the way our
  Fourier Transform library (`fftw3`) works is that the first time it
  encounters a Fourier Transform, it has to figure out the fastest way to
  compute it. After you've gone through a few, it will get faster. You can cache its "wisdom" at any point by pressing `#`. Don't share wisdom between machines, as it is machine specific! 






