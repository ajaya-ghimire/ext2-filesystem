#include "ext2.h"
#include <iostream>

Ext2::Ext2(const std::string& image) {
    disk.open(image, std::ios::binary);
    if (!disk) {
        std::cerr << "Failed to open image\n";
        exit(1);
    }
    readSuperblock();
}

void Ext2::readSuperblock() {
    disk.seekg(1024); // superblock offset
    disk.read(reinterpret_cast<char*>(&sb), sizeof(Superblock));
    blockSize = 1024 << sb.log_block_size;
}

void Ext2::printSuperblock() {
    std::cout << "Inodes: " << sb.inodes_count << "\n";
    std::cout << "Blocks: " << sb.blocks_count << "\n";
    std::cout << "Block size: " << blockSize << " bytes\n";
}

void Ext2::listRoot() {
    std::cout << "[Root directory listing simulated]\n";
    std::cout << ".\n..\nfile1\nfile2\n";
}
