#ifndef VDI_H
#define VDI_H

#include <cstdint>
#include <fstream>
#include <string>

struct VDIHeader {
    char text[64];
    uint32_t signature;
    uint32_t version;
    uint32_t headerSize;
    uint32_t imageType;
    uint64_t dataOffset;
};

class VDI {
public:
    std::ifstream disk;
    uint64_t dataOffset;

    VDI(const std::string& file);
};

#endif
