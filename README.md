# Debate Buddy

AI-powered third voice in your conversations. Records audio context, captures questions on button press, responds via AI.

**Platform:** Raspberry Pi (ARM64) | **Status:** 🚧 WIP - Phase 1: C++ Monolith

## Dependencies

# Build tools
sudo apt install -y build-essential cmake git

# ALSA library (audio)
sudo apt install -y libasound2-devCMake auto-fetches: spdlog (v1.12.0), nlohmann_json (v3.11.3)

## Build & Run

git clone --recursive git@github.com:andreymisyurov/debate-buddy.git
cd debate-buddy/cpp-monolith
make
./debate-buddy

## Structure
cpp-monolith/
├── src/
│   └── main.cpp
├── include/
│   └── interfaces/
├── cpp-logger/         # Logging submodule
├── data/
│   └── recordings/     # Audio recordings
└── CMakeLists.txt

MIT - Andrei Misiurov