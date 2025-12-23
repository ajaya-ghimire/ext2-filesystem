#include "vdi.h"
#include "ext2.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./ext2vdi disk.vdi\n";
        return 1;
    }

    VDI vdi(argv[1]);
    Ext2 fs(vdi.disk, vdi.dataOffset);
    fs.printSuperblock();

    return 0;
}
