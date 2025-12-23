#ifndef EXT2_H
#define EXT2_H

#include <cstdint>
#include <fstream>

struct Superblock {
    uint32_t inodes;
    uint32_t blocks;
    uint32_t rsvd;
    uint32_t freeBlocks;
    uint32_t freeInodes;
    uint32_t firstDataBlock;
    uint32_t logBlockSize;
};

class Ext2 {
private:
    std::ifstream& disk;
    uint64_t offset;
    Superblock sb;
    uint32_t blockSize;

public:
    Ext2(std::ifstream& d, uint64_t off);
    void readSuperblock();
    void printSuperblock();
};

#endif
