#pragma once
#include <JuceHeader.h>
#include "SpectralPeaksAudioProcessor.h"

class SpectralPeaksAudioProcessorEditor : public juce::AudioProcessorEditor, private juce::Timer {
public:
    SpectralPeaksAudioProcessorEditor(SpectralPeaksAudioProcessor& p) : AudioProcessorEditor(&p), processor(p) {
        setSize(600, 200);
        startTimerHz(30);
    }
    void paint(juce::Graphics&) override;
    void timerCallback() override;
    SpectralPeaksAudioProcessor& processor;
};
