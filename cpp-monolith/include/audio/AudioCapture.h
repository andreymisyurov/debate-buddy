#include <Logger.h>
#include <alsa/asoundlib.h>

#include <fstream>
#include <string>
#include <vector>

#include "interfaces/IAudioCapture.h"

class AudioCapture : public IAudioCapture {
   public:
    AudioCapture();
    ~AudioCapture();

    bool recordToFile(const std::string& filename,
                      int durationSeconds) override;
};
