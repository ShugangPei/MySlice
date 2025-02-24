#ifndef STLREADER_H
#define STLREADER_H

#include <vector>
#include <string>
#include "Point3D.h"

class STLReader {
public:
    struct Face {
        Point3D vertex1;
        Point3D vertex2;
        Point3D vertex3;
    };

    bool loadSTL(const std::string& filename);
    void saveToTXT(const std::string& filename) const;
    const std::vector<Point3D>& getVertices() const;
    const std::vector<Face>& getFaces() const;

private:
    std::vector<Point3D> vertices;
    std::vector<Face> faces;
};

#endif // STLREADER_H
