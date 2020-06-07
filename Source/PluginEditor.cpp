/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BiquadEqAudioProcessorEditor::BiquadEqAudioProcessorEditor (BiquadEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (700, 200);
    addAndMakeVisible (filterTypeMenu);
 
    // add items to the combo-box
    filterTypeMenu.addItem ("Lowpass", static_cast<int>(FilterType::LowPass));
    filterTypeMenu.addItem ("Highpass", static_cast<int>(FilterType::HighPass));
    filterTypeMenu.addItem ("Bandpass", static_cast<int>(FilterType::BandPass));
    filterTypeMenu.addItem ("Notch", static_cast<int>(FilterType::Notch));
    filterTypeMenu.addItem ("Allpass", static_cast<int>(FilterType::AllPass));
    filterTypeMenu.addItem ("Peaking", static_cast<int>(FilterType::Peaking));
    filterTypeMenu.addItem ("Lowshelf", static_cast<int>(FilterType::LowShelf));
    filterTypeMenu.addItem ("Highshelf", static_cast<int>(FilterType::HighShelf));
    filterTypeMenu.onChange = [this] { filterTypeMenuChanged(); };
    filterTypeMenu.setSelectedId (static_cast<int>(processor.initFilterType));
    
    addAndMakeVisible (frequencySlider);
    frequencySlider.setSliderStyle(Slider::RotaryVerticalDrag);
    frequencySlider.setValue(processor.initf0);
    frequencySlider.setRange (50, 20000);
    frequencySlider.setTextValueSuffix (" Hz");
    frequencySlider.setTextBoxStyle(Slider::TextBoxAbove, true, 100, 30);
    frequencySlider.addListener (this);
    
    addAndMakeVisible (frequencyLabel);
    frequencyLabel.setText ("Frequency", dontSendNotification);
    frequencyLabel.setJustificationType(Justification::centred);
    frequencyLabel.attachToComponent (&frequencySlider, false);
    
    addAndMakeVisible (QSlider);
    QSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    QSlider.setValue(processor.initQ);
    QSlider.setRange (0.1, 2.0);
    QSlider.setTextBoxStyle(Slider::TextBoxAbove, true, 100, 30);
    QSlider.addListener (this);
    
    addAndMakeVisible (QLabel);
    QLabel.setText ("Q", dontSendNotification);
    QLabel.setJustificationType(Justification::centred);
    QLabel.attachToComponent (&QSlider, false);
    
    addAndMakeVisible (dBGainSlider);
    dBGainSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    dBGainSlider.setValue(processor.initdBGain);
    dBGainSlider.setRange (-25.0, 25.0);
    dBGainSlider.setTextValueSuffix (" dB");
    dBGainSlider.setTextBoxStyle(Slider::TextBoxAbove, true, 100, 30);
    dBGainSlider.addListener (this);
    
    addAndMakeVisible (dBGainLabel);
    dBGainLabel.setText ("Gain", dontSendNotification);
    dBGainLabel.setJustificationType(Justification::centred);
    dBGainLabel.attachToComponent (&dBGainSlider, false);
}

BiquadEqAudioProcessorEditor::~BiquadEqAudioProcessorEditor()

{
}

//==============================================================================
void BiquadEqAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void BiquadEqAudioProcessorEditor::resized()
{
    filterTypeMenu.setBounds (10, 100, getWidth() * 0.2, 20);
    frequencySlider.setBounds (getWidth() * 0.3, 70, getWidth() * 0.15, 100);
    QSlider.setBounds (getWidth() * 0.5, 70, getWidth() * 0.15, 100);
    dBGainSlider.setBounds (getWidth() * 0.7, 70, getWidth() * 0.15, 100);
}

void BiquadEqAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &frequencySlider)
    {
        double newf0 = slider->getValue();
        for (int channel = 0; channel < processor.kChannels; channel++)
        {
            Parameters params = processor.filters[channel].getParams();
            params.f0 = newf0;
            processor.filters[channel].setParams(params);
        }
    }
    else if (slider == &QSlider)
    {
        double newQ = slider->getValue();
        for (int channel = 0; channel < processor.kChannels; channel++)
        {
            Parameters params = processor.filters[channel].getParams();
            params.Q = newQ;
            processor.filters[channel].setParams(params);
        }
    } else if (slider == &dBGainSlider)
    {
        double newdBGain = slider->getValue();
        for (int channel = 0; channel < processor.kChannels; channel++)
        {
            Parameters params = processor.filters[channel].getParams();
            params.dBGain = newdBGain;
            processor.filters[channel].setParams(params);
        }
    }
}

void BiquadEqAudioProcessorEditor::filterTypeMenuChanged()
{
    Parameters params = processor.filters[0].getParams();
    FilterType newFilterType = static_cast<FilterType>(filterTypeMenu.getSelectedId());
    if (params.filterType != newFilterType)
    {
        params.filterType = newFilterType;
        for (int channel = 0; channel < processor.kChannels; channel++)
            processor.filters[channel].setParams(params);
    }
}
