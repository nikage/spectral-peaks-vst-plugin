# SpectralPeaks

A real-time audio spectrum analyzer plugin built with JUCE.

## Overview

SpectralPeaks is an audio plugin that performs Fast Fourier Transform (FFT) analysis on incoming audio signals and displays the spectral content visually. The plugin shows frequency content using a colorful visualization where:

- Horizontal position represents frequency
- Vertical position and color brightness represent amplitude
- Hue represents the position in the frequency spectrum

## Features

- Real-time FFT analysis with 1024-point resolution
- Colorful visualization of spectral content
- Available in multiple plugin formats:
  - Audio Unit (AU)
  - VST3
  - Standalone application

## Requirements

- macOS (tested on macOS 10.15+)
- Compatible DAW for plugin formats (Logic Pro, Ableton Live, etc.)

## Building from Source

### Prerequisites

- CMake (3.15 or higher)
- C++ compiler with C++14 support
- JUCE framework (included as a submodule)

### Build Instructions

1. Clone the repository with submodules:
   ```
   git clone --recursive https://github.com/yourusername/SpectralPeaks.git
   ```

2. Create a build directory:
   ```
   cd SpectralPeaks
   mkdir build
   cd build
   ```

3. Configure and build:
   ```
   cmake ..
   cmake --build .
   ```

4. Install plugins to your system (macOS):
   ```
   cmake --build . --target install_plugins
   ```

## Usage

1. Load the plugin in your DAW of choice
2. Play audio through the track containing the plugin
3. Observe the real-time spectral visualization

## Development

The project is structured as follows:

- `Source/` - Contains all source code
  - `SpectralPeaksAudioProcessor` - Handles audio processing and FFT analysis
  - `SpectralPeaksAudioProcessorEditor` - Manages the UI and visualization

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Built with the [JUCE](https://juce.com/) framework 