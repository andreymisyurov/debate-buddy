#include <Logger.h>

#include <iostream>
#include <memory>

#include "audio/AudioCapture.h"

int main() {
    LOG_INFO("Debate Buddy v0.1.0");
    try {
        auto audioCapture = std::make_unique<AudioCapture>();

        std::string filename = "data/recordings/test.wav";
        int duration = 5;

        if (audioCapture->recordToFile(filename, duration) == false) {
            return 1;
        }
    } catch (const std::exception& e) {
        LOG_ERROR("Exception: {}", e.what());
        return 1;
    }
    return 0;
}
