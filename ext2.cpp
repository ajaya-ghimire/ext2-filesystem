#include "ext2.h"
#include <iostream>

Ext2::Ext2(std::ifstream& d, uint64_t off)
    : disk(d), offset(off) {
    readSuperblock();
}

void Ext2::readSuperblock() {
    disk.seekg(offset + 1024);
    disk.read(reinterpret_cast<char*>(&sb), sizeof(sb));
    blockSize = 1024 << sb.logBlockSize;
}

void Ext2::printSuperblock() {
    std::cout << "Ext2 Superblock\n";
    std::cout << "Inodes: " << sb.inodes << "\n";
    std::cout << "Blocks: " << sb.blocks << "\n";
    std::cout << "Block size: " << blockSize << " bytes\n";
}
