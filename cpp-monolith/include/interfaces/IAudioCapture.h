#ifndef DEBATE_BUDDY_IAUDIOCAPTURE_H_
#define DEBATE_BUDDY_IAUDIOCAPTURE_H_
#include <string>

class IAudioCapture {
public:
    virtual ~IAudioCapture() = default;
    
    virtual bool recordToFile(const std::string& filename, 
                             int durationSeconds) = 0;
};

#endif  // DEBATE_BUDDY_IAUDIOCAPTURE_H_