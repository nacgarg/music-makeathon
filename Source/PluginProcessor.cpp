/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include <cstdlib>
#include <iostream>
#include "PluginEditor.h"

//==============================================================================
MusicmakeathonAudioProcessor::MusicmakeathonAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                         .withInput("Input", AudioChannelSet::stereo(), true)
#endif
                         .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
                         ),
      forwardFFT(fftOrder)
#endif
{
}

MusicmakeathonAudioProcessor::~MusicmakeathonAudioProcessor() {}

//==============================================================================
const String MusicmakeathonAudioProcessor::getName() const { return JucePlugin_Name; }

bool MusicmakeathonAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool MusicmakeathonAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool MusicmakeathonAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double MusicmakeathonAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int MusicmakeathonAudioProcessor::getNumPrograms() {
  return 1;  // NB: some hosts don't cope very well if you tell them there are 0 programs,
             // so this should be at least 1, even if you're not really implementing
             // programs.
}

int MusicmakeathonAudioProcessor::getCurrentProgram() { return 0; }

void MusicmakeathonAudioProcessor::setCurrentProgram(int index) {}

const String MusicmakeathonAudioProcessor::getProgramName(int index) { return {}; }

void MusicmakeathonAudioProcessor::changeProgramName(int index, const String& newName) {}

//==============================================================================
void MusicmakeathonAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
  // Use this method as the place to do any pre-playback
  // initialisation that you need..
  File file("/home/nachi/BlastFromTokyo.wav");
  formatManager.registerBasicFormats();
  AudioFormatReader* reader = formatManager.createReaderFor(file);
  auto fileBuffer = new AudioBuffer<float>(2, reader->lengthInSamples);
  reader->read(fileBuffer, 0, static_cast<int>(reader->lengthInSamples),
               static_cast<juce::int64>(0), true, false);
  auto* channelDataLeft = fileBuffer->getWritePointer(0);
  auto* channelDataRight = fileBuffer->getWritePointer(1);
  auto tempBuffer = new AudioBuffer<float>(1, bufferSize);
  auto* tempData = tempBuffer->getWritePointer(0);
  std::cout << "Reading file with " << fileBuffer->getNumSamples() << " samples"
            << std::endl;
  for (int i = 0; i < fileBuffer->getNumSamples(); i++) {
    float mono = (channelDataLeft[i] + channelDataRight[i]) / 2;
    tempData[i % bufferSize] = mono;
    if (i % bufferSize == 0) {
      chunks.push_back(*tempBuffer);
      tempBuffer = new AudioBuffer<float>(1, bufferSize);
    }
  }
  std::cout << chunks.size() << std::endl;
  delete reader;
}

void MusicmakeathonAudioProcessor::releaseResources() {
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MusicmakeathonAudioProcessor::isBusesLayoutSupported(
    const BusesLayout& layouts) const {
#if JucePlugin_IsMidiEffect
  ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
    return false;

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet()) return false;
#endif

  return true;
#endif
}
#endif

void MusicmakeathonAudioProcessor::processBlock(AudioBuffer<float>& buffer,
                                                MidiBuffer& midiMessages) {
  ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();

  // In case we have more outputs than inputs, this code clears any output
  // channels that didn't contain input data, (because these aren't
  // guaranteed to be empty - they may contain garbage).
  // This is here to avoid people getting screaming feedback
  // when they first compile a plugin, but obviously you don't need to keep
  // this code if your algorithm always overwrites all the output channels.
  for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    buffer.clear(i, 0, buffer.getNumSamples());

  // This is the place where you'd normally do the guts of your plugin's
  // audio processing...
  // Make sure to reset the state if your inner loop is processing
  // the samples and the outer loop is handling the channels.
  // Alternatively, you can process the samples with the channels
  // interleaved by keeping the same state.
  int channel = 0;
  auto* channelDataLeft = buffer.getWritePointer(0);
  auto* channelDataRight = buffer.getWritePointer(1);

  for (int i = 0; i < buffer.getNumSamples(); i++) {
    //   inputFifo.push(channelData[i]);
    float mono = (channelDataLeft[i] + channelDataRight[i]) / 2;
    inputFifo->push(mono);
    if (currentlyPlaying) {
      channelDataLeft[i] = sampleBufferFifo->front();
      channelDataRight[i] = sampleBufferFifo->front();
      sampleBufferFifo->pop();
      if (sampleBufferFifo->empty()) {
        // time to load new sample!
        findAndLoadSample(inputFifo, sampleBufferFifo);
      }
    } else {
      findAndLoadSample(inputFifo, sampleBufferFifo);
      currentlyPlaying = true;
    }
  }
}

void MusicmakeathonAudioProcessor::findAndLoadSample(
    std::queue<float> inputFifo[bufferSize], std::queue<float> outputFifo[bufferSize]) {
  // compute FFT of inputFifo
  // for every sound
  // compute FFT and compare to input
  // set outputFifo to sound with least difference

  // for now, just set output to input
  //   while (!inputFifo->empty()) {
  //     outputFifo->push(inputFifo->front());
  //     inputFifo->pop();
  //   }
  auto* data = chunks.at(rand() % chunks.size()).getWritePointer(0);
  for (int i = 0; i < bufferSize; i++) {
    std::cout << data[i] << std::endl;
    outputFifo->push(data[i]);
  }
}

//==============================================================================
bool MusicmakeathonAudioProcessor::hasEditor() const {
  return true;  // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MusicmakeathonAudioProcessor::createEditor() {
  return new MusicmakeathonAudioProcessorEditor(*this);
}

//==============================================================================
void MusicmakeathonAudioProcessor::getStateInformation(MemoryBlock& destData) {
  // You should use this method to store your parameters in the memory block.
  // You could do that either as raw data, or use the XML or ValueTree classes
  // as intermediaries to make it easy to save and load complex data.
}

void MusicmakeathonAudioProcessor::setStateInformation(const void* data,
                                                       int sizeInBytes) {
  // You should use this method to restore your parameters from this memory block,
  // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
  return new MusicmakeathonAudioProcessor();
}
