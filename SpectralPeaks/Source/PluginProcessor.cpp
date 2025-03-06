#include "SpectralPeaksAudioProcessor.h"

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpectralPeaksAudioProcessor();
} 