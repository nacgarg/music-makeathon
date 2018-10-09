# Music Makeathon 2018

An audiovisual project primarily consisting of realtime audio-controlled sound and video resampling. Our goal was to use technology to instill aspects of live perfomance in [acousmatic music](https://en.wikipedia.org/wiki/Acousmatic_music).

Check back later for a link to our demo performance.

## Overview

This project was created as part of and won first place at the music makeathon organized by Project Music at U-M.
It uses the JUCE C++ library for audio processing and Max/MSP for video processing.

## Audio Processing

On initial startup, the plugin scans all input files and slices them into chunks of a fixed size. The FFT of every chunk is computed and stored in memory.

At runtime, FFT of the input is computed and compared against the FFTs of all the precomputed chunks to determine the most similar-sounding chunk from an input file. The most similar-sounding chunk is then passed into the output. 

## Video Processing

Through the usage of note detection, (fzero~ object), this patch measures the fundamental freq and the amplitude of the input and scales it between 1-17. This value is then used to reference the corresponding video in our video library. These videos are then added together (layered) to create a visual that is constantly evolving. It should be noted that any videos can be used in this patch, simply drag and drop them into the playlist objects and rescale the inputs accordingly. 
