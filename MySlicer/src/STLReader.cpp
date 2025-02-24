#include "STLReader.h"
#include <fstream>
#include <iostream>

bool STLReader::loadSTL(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    char header[80];
    file.read(header, 80);

    uint32_t numFaces;
    file.read(reinterpret_cast<char*>(&numFaces), sizeof(uint32_t));

    faces.reserve(numFaces);
    vertices.reserve(numFaces * 3);

    for (uint32_t i = 0; i < numFaces; ++i) {
        float normal[3];
        float vertex1[3], vertex2[3], vertex3[3];
        uint16_t attributeByteCount;

        file.read(reinterpret_cast<char*>(&normal), sizeof(normal));
        file.read(reinterpret_cast<char*>(&vertex1), sizeof(vertex1));
        file.read(reinterpret_cast<char*>(&vertex2), sizeof(vertex2));
        file.read(reinterpret_cast<char*>(&vertex3), sizeof(vertex3));
        file.read(reinterpret_cast<char*>(&attributeByteCount), sizeof(attributeByteCount));

        Point3D v1(vertex1[0], vertex1[1], vertex1[2]);
        Point3D v2(vertex2[0], vertex2[1], vertex2[2]);
        Point3D v3(vertex3[0], vertex3[1], vertex3[2]);

        vertices.push_back(v1);
        vertices.push_back(v2);
        vertices.push_back(v3);

        faces.push_back({v1, v2, v3});
    }

    return true;
}

void STLReader::saveToTXT(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    file << "Vertices:\n";
    for (const auto& vertex : vertices) {
        file << "  (" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")\n";
    }

    file << "Faces:\n";
    for (const auto& face : faces) {
        file << "  ["
             << "(" << face.vertex1.x << ", " << face.vertex1.y << ", " << face.vertex1.z << "), "
             << "(" << face.vertex2.x << ", " << face.vertex2.y << ", " << face.vertex2.z << "), "
             << "(" << face.vertex3.x << ", " << face.vertex3.y << ", " << face.vertex3.z << ")]\n";
    }
}

const std::vector<Point3D>& STLReader::getVertices() const {
    return vertices;
}

const std::vector<STLReader::Face>& STLReader::getFaces() const {
    return faces;
}
