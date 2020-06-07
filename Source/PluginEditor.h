/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BiquadEqAudioProcessorEditor  : public AudioProcessorEditor,
public Slider::Listener
{
public:
    BiquadEqAudioProcessorEditor (BiquadEqAudioProcessor&);
    ~BiquadEqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    void filterTypeMenuChanged();
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BiquadEqAudioProcessor& processor;
    
    ComboBox filterTypeMenu;
    
    Slider frequencySlider;
    Label frequencyLabel;
    Slider QSlider;
    Label QLabel;
    Slider dBGainSlider;
    Label dBGainLabel;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BiquadEqAudioProcessorEditor)
};
