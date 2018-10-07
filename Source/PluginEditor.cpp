/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"

void MusicmakeathonAudioProcessorEditor::openButtonClicked() { processor.changeSong(); }

//==============================================================================
MusicmakeathonAudioProcessorEditor::MusicmakeathonAudioProcessorEditor(
    MusicmakeathonAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p), openButton("Click") {
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(400, 300);
  openButton.setButtonText("Open...");
  openButton.onClick = [this] { openButtonClicked(); };
  addAndMakeVisible(&openButton);
}

MusicmakeathonAudioProcessorEditor::~MusicmakeathonAudioProcessorEditor() {}

//==============================================================================
void MusicmakeathonAudioProcessorEditor::paint(Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a solid
  // colour)
  g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

  g.setColour(Colours::white);
  g.setFont(20.0f);
  g.drawFittedText("Music Makeathon 2018!", 10, 10, 200, 200, Justification::centred, 1);

  g.drawFittedText(processor.currentFilename, 10, 50, 200, 200, Justification::centred,
                   1);
  //   if (processor.currentFilename != lastFilename) {
    repaint();
  // lastFilename = processor.currentFilename;
  //   }
}
void MusicmakeathonAudioProcessorEditor::buttonChanged(Button* button) {
  processor.changeSong();
}

void MusicmakeathonAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  openButton.setBounds(20, 10, 150, 30);
}
