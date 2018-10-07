/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <queue>
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
 */
class MusicmakeathonAudioProcessor : public AudioProcessor {
 public:
  //==============================================================================
  MusicmakeathonAudioProcessor();
  ~MusicmakeathonAudioProcessor();

  //==============================================================================
  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
  bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

  void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

  //==============================================================================
  AudioProcessorEditor* createEditor() override;
  bool hasEditor() const override;

  //==============================================================================
  const String getName() const override;

  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool isMidiEffect() const override;
  double getTailLengthSeconds() const override;

  //==============================================================================
  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const String getProgramName(int index) override;
  void changeProgramName(int index, const String& newName) override;

  //==============================================================================
  void getStateInformation(MemoryBlock& destData) override;
  void setStateInformation(const void* data, int sizeInBytes) override;

 private:
  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicmakeathonAudioProcessor)
  static const int fftOrder = 16;
  static const int bufferSize = 1 << fftOrder;
  std::queue<float> inputFifo[bufferSize];
  float fftData[2 * bufferSize];
  std::queue<float> sampleBufferFifo[bufferSize];
  dsp::FFT forwardFFT;
  bool nextFFTBlockReady;
  bool currentlyPlaying = false;
  void findAndLoadSample(std::queue<float>[bufferSize], std::queue<float>[bufferSize]);
  AudioFormatManager formatManager;
  std::unique_ptr<AudioFormatReaderSource> readerSource;
  std::vector<AudioBuffer<float>> chunks;
};
