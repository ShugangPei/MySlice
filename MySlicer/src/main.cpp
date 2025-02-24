#include <iostream>
#include "STLReader.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <stl_file> <output_txt>" << std::endl;
        return 1;
    }

    STLReader reader;
    if (!reader.loadSTL(argv[1])) {
        return 1;
    }

    reader.saveToTXT(argv[2]);

    std::cout << "Vertices and faces have been saved to " << argv[2] << std::endl;

    return 0;
}
