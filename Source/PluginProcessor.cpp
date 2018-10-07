/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <thread>

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

void audioBufferToFloatArray(AudioBuffer<float>& buf, float* outArray) {
  auto ptr = buf.getWritePointer(0);
  float max = 0;
  for (int i = 0; i < buf.getNumSamples(); i++) {
    outArray[i] = ptr[i];
    if (std::abs(outArray[i] > max)) {
      max = outArray[i];
    }
  }
  for (int i = 0; i < buf.getNumSamples(); i++) {
    // outArray[i] /= max;
  }
}

void MusicmakeathonAudioProcessor::loadFiles(Array<File> files) {
  chunks.clear();
  for (int a = 0; a < files.size(); a++) {
    auto file = files[a];
    formatManager.registerBasicFormats();
    AudioFormatReader* reader = formatManager.createReaderFor(file);
    auto fileBuffer = new AudioBuffer<float>(2, reader->lengthInSamples);
    reader->read(fileBuffer, 0, static_cast<int>(reader->lengthInSamples),
                 static_cast<juce::int64>(0), true, false);
    auto* channelDataLeft = fileBuffer->getReadPointer(0);
    auto* channelDataRight = fileBuffer->getReadPointer(1);
    auto tempBuffer = AudioBuffer<float>(1, bufferSize);
    float* tempData = tempBuffer.getWritePointer(0);
    std::cout << "Reading file with " << fileBuffer->getNumSamples() << " samples"
              << std::endl;
    for (int i = 0; i < fileBuffer->getNumSamples(); i++) {
      float mono = (channelDataLeft[i] + channelDataRight[i]) / 2.0;

      tempData[i % bufferSize] = mono;
      if (i % bufferSize == 0) {
        auto copy = AudioBuffer<float>(tempBuffer);
        chunks.push_back(copy);
        filenames.push_back(file.getFileName());
        tempBuffer = AudioBuffer<float>(1, bufferSize);
        tempData = tempBuffer.getWritePointer(0);
      }
    }
    delete reader;
  }
  // array of files, store chunks in vector of Chunk struct which contains original
  // filename

  std::cout << chunks.size() << std::endl;

  for (int i = 0; i < chunks.size(); i++) {
    float* chunkFFT = new float[bufferSize * 2];
    audioBufferToFloatArray(chunks.at(i), chunkFFT);
    forwardFFT.performFrequencyOnlyForwardTransform(chunkFFT);
    precomputedFFTs.push_back(chunkFFT);
  }
}
void MusicmakeathonAudioProcessor::changeSong() {
  suspendProcessing(true);
  FileChooser chooser("Select a Wave file to play...", File::nonexistent, "*.wav");
  if (chooser.browseForMultipleFilesOrDirectories()) {
    auto files = chooser.getResults();
    loadFiles(files);
  }
  suspendProcessing(false);
}
void MusicmakeathonAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
  // Use this method as the place to do any pre-playback
  // initialisation that you need..
  changeSong();
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
  float* channelDataLeft = buffer.getWritePointer(0);
  float* channelDataRight = buffer.getWritePointer(1);
  bool shouldPlay = sampleBufferFifo->size() >= bufferSize;
  for (int i = 0; i < buffer.getNumSamples(); i++) {
    //   inputFifo.push(channelData[i]);
    float gain = 10;
    float mono = (channelDataLeft[i] + channelDataRight[i]) / 2.0 * gain;
    inputFifo->push(mono);
    // std::cout << inputFifo->size() << " samples (" << inputFifo->size() / 44100
    //   << " seconds) behind" << std::endl;
    // std::cout << sampleBufferFifo->size() << " samples ("
    //   << sampleBufferFifo->size() / 44100 << " seconds) in buffer" << std::endl;
    if (!sampleBufferFifo->empty()) {
      channelDataLeft[i] = (mono * 0 + sampleBufferFifo->front() * 1);
      channelDataRight[i] = (mono * 0 + sampleBufferFifo->front() * 1);
      sampleBufferFifo->pop();
    }
  }
  if (inputFifo->size() >= bufferSize && sampleBufferFifo->size() <= bufferSize) {
    //   std::thread t1(f);
    findAndLoadSample(inputFifo, sampleBufferFifo);
    //   (, );
    currentlyPlaying = true;
  }
}

float compareFFTs(float* fft1, float* fft2, int length) {
  float score = 0;
  auto lvl1 = FloatVectorOperations::findMinAndMax(fft1, length);
  auto lvl2 = FloatVectorOperations::findMinAndMax(fft2, length);
  float avgLvl = (lvl1.getEnd() + lvl2.getEnd()) / 2;
  //   std::cout << lvl1.getEnd() << " " << lvl2.getEnd() << std::endl;

  for (int i = 0; i < length; i += 2) {
    score += (fft1[i] - fft2[i]) * (fft1[i] - fft2[i]);
  }
  //   std::cout << score << std::endl;
  return score / length;
}

void MusicmakeathonAudioProcessor::findAndLoadSample(
    std::queue<float> inputFifo[bufferSize], std::queue<float> outputFifo[bufferSize]) {
  float max = 0;
  for (int j = 0; j < bufferSize; j++) {
    fftData[j] = inputFifo->front();  // divide by max here
    inputFifo->pop();
    if (std::abs(fftData[j]) > max) {
      max = std::abs(fftData[j]);
    }
  }
  std::cout << "max: " << max << std::endl;
  // normalize samples before fft
  //   for (int j = 0; j < bufferSize; j++) {
  // fftData[j] /= max;
  //   }

  forwardFFT.performFrequencyOnlyForwardTransform(fftData);

  float maxAmp = 0;
  float maxIndex = 0;
  for (int i = 0; i < bufferSize; i++) {
    if (fftData[i] > maxAmp) {
      maxAmp = fftData[i];
      maxIndex = i;
    }
  }
  std::cout << "max for input: " << maxIndex << std::endl;
  float bestScore = std::numeric_limits<float>::max();
  int bestIndex = 0;
  for (int i = 0; i < precomputedFFTs.size(); i++) {
    float score = compareFFTs(precomputedFFTs.at(i), fftData, bufferSize / 2);
    if (score < bestScore) {
      bestScore = score;
      bestIndex = i;
    }
  }
  maxAmp = 0;
  for (int i = 0; i < bufferSize; i++) {
    if (fftData[i] > maxAmp) {
      maxAmp = precomputedFFTs.at(bestIndex)[i];
      maxIndex = i;
    }
  }
  std::cout << "max for best: " << maxIndex << std::endl;

  //   std::cout << bestIndex << std::endl;
  lastSampleIndex = bestIndex;
  currentFilename = filenames.at(bestIndex);
  std::cout << "playing " << currentFilename << std::endl;
  // compute FFT of inputFifo
  // for every sound
  // compute FFT and compare to input
  // set outputFifo to sound with least difference

  // for now, just set output to input
  //   while (!inputFifo->empty()) {
  //     outputFifo->push(inputFifo->front());
  //     inputFifo->pop();
  //   }

  auto* data = chunks.at(bestIndex).getWritePointer(0);
  int i = 0;
  for (int j = 0; j < bufferSize; j++) {
    // inputFifo->pop();
    outputFifo->push(data[j]);
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
