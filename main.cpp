#include "ext2.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./ext2 <image.img>\n";
        return 1;
    }

    Ext2 fs(argv[1]);
    fs.printSuperblock();
    fs.listRoot();

    return 0;
}

