#include "audio/AudioCapture.h"

AudioCapture::AudioCapture() {
    // LOG_INFO("AudioCapture constructor");
}

AudioCapture::~AudioCapture() {
    // LOG_INFO("AudioCapture destructor");
}

bool AudioCapture::recordToFile(const std::string& filename,
                                int durationSeconds) {
    LOG_INFO("Recording {} seconds to {}", durationSeconds, filename);

    // Открыть ALSA
    snd_pcm_t* handle;
    if (snd_pcm_open(&handle, "default", SND_PCM_STREAM_CAPTURE, 0) < 0) {
        LOG_ERROR("Cannot open device");
        return false;
    }

    // Настроить: 16kHz, моно, 16-bit
    snd_pcm_set_params(handle, SND_PCM_FORMAT_S16_LE,
                       SND_PCM_ACCESS_RW_INTERLEAVED, 1, 16000, 1, 100000);

    // Читать данные
    std::vector<int16_t> buffer(16000 * durationSeconds);
    snd_pcm_readi(handle, buffer.data(), buffer.size());

    snd_pcm_close(handle);

    // Записать в файл
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<char*>(buffer.data()),
               buffer.size() * sizeof(int16_t));

    LOG_INFO("Done");
    return true;
}