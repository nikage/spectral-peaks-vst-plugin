#include "SpectralPeaksAudioProcessor.h"
#include "SpectralPeaksAudioProcessorEditor.h"

SpectralPeaksAudioProcessor::SpectralPeaksAudioProcessor() {
    fftData.resize(2048, 0.0f);
}

void SpectralPeaksAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // Prepare your processor for playback
}

void SpectralPeaksAudioProcessor::releaseResources() {
    // Release any resources that are no longer needed
}

void SpectralPeaksAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    const float* channelData = buffer.getReadPointer(0);
    for (int i = 0; i < buffer.getNumSamples(); ++i) {
        fifo.push_back(channelData[i]);
        if (fifo.size() == fft->getSize()) {
            std::copy(fifo.begin(), fifo.end(), fftData.begin());
            fft->performRealOnlyForwardTransform(fftData.data());
            fifo.clear();
        }
    }
}

juce::AudioProcessorEditor* SpectralPeaksAudioProcessor::createEditor() {
    return new SpectralPeaksAudioProcessorEditor(*this);
}
