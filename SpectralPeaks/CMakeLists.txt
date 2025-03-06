cmake_minimum_required(VERSION 3.15)
project(SpectralPeaks VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/JUCE/extras/Build/CMake")

add_subdirectory(JUCE)

juce_add_plugin(SpectralPeaks
    PRODUCT_NAME "SpectralPeaks"
    FORMATS AU VST3 Standalone
)

target_sources(SpectralPeaks PRIVATE
    Source/SpectralPeaksAudioProcessor.cpp
    Source/SpectralPeaksAudioProcessorEditor.cpp
    Source/PluginProcessor.cpp
)

target_link_libraries(SpectralPeaks PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_plugin_client
    juce::juce_audio_processors
    juce::juce_core
    juce::juce_data_structures
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
    )
juce_generate_juce_header(SpectralPeaks) 


add_custom_target(install_plugins
    COMMAND mkdir -p ~/Library/Audio/Plug-Ins/VST3
    COMMAND mkdir -p ~/Library/Audio/Plug-Ins/Components
    COMMAND cp -R ${CMAKE_BINARY_DIR}/SpectralPeaks_artefacts/VST3/SpectralPeaks.vst3 ~/Library/Audio/Plug-Ins/VST3/
    COMMAND cp -R ${CMAKE_BINARY_DIR}/SpectralPeaks_artefacts/AU/SpectralPeaks.component ~/Library/Audio/Plug-Ins/Components/
    COMMENT "Installing plugins to user directories"
)