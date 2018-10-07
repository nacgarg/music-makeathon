/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <functional>
#include <map>
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
 */
class MusicmakeathonAudioProcessorEditor : public AudioProcessorEditor {
 public:
  MusicmakeathonAudioProcessorEditor(MusicmakeathonAudioProcessor&);
  ~MusicmakeathonAudioProcessorEditor();

  //==============================================================================
  void paint(Graphics&) override;
  void resized() override;
  void buttonChanged(juce::Button*);

 private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  MusicmakeathonAudioProcessor& processor;
  TextButton openButton;
  void openButtonClicked();
  String lastFilename;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicmakeathonAudioProcessorEditor)
};
