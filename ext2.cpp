#ifndef EXT2_H
#define EXT2_H

#include <cstdint>
#include <string>
#include <fstream>

struct Superblock {
    uint32_t inodes_count;
    uint32_t blocks_count;
    uint32_t log_block_size;
};

class Ext2 {
private:
    std::ifstream disk;
    Superblock sb;
    uint32_t blockSize;

public:
    Ext2(const std::string& image);
    void readSuperblock();
    void printSuperblock();
    void listRoot();
};

#endif

