#include "SpectralPeaksAudioProcessorEditor.h"
#include "SpectralPeaksAudioProcessor.h"

void SpectralPeaksAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
    auto width = getWidth();
    auto height = getHeight();
    auto& fftData = processor.fftData;
    auto fftSize = processor.fft->getSize();
    for (int i = 0; i < fftSize / 2; ++i) {
        float magnitude = fftData[i];
        auto dB = juce::Decibels::gainToDecibels(magnitude);
        float brightness = juce::jmap(dB, -100.f, 0.f, 0.f, 1.f);
        juce::Colour col = juce::Colour::fromHSV((float)i / (fftSize / 2), 1.f, brightness, 1.f);
        g.setColour(col);
        g.drawLine(i, getHeight(), i, getHeight() * (1.0f - brightness));
    }
}

void SpectralPeaksAudioProcessorEditor::timerCallback() {
    repaint();
}
