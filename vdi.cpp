#include "vdi.h"
#include <iostream>

VDI::VDI(const std::string& file) {
    disk.open(file, std::ios::binary);
    if (!disk) {
        std::cerr << "Failed to open VDI\n";
        exit(1);
    }

    VDIHeader header;
    disk.read(reinterpret_cast<char*>(&header), sizeof(header));
    dataOffset = header.dataOffset;

    if (header.signature != 0xBEDA107F) {
        std::cerr << "Not a valid VDI file\n";
        exit(1);
    }
}
