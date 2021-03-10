#include "bone.h"

bone::bone(std::string& fileName, std::vector<triangle>& facet, double offset)
    :mFileName(fileName), mFacet(facet), mOffset(offset)
{

    x_min = 1e+30, x_max = -1e+30;
    y_min = 1e+30, y_max = -1e+30;
    z_min = 1e+30, z_max = -1e+30;


    std::ifstream binaryInputFile;
    int numberOfTriangles;
    triangle tri;
    char unused_bytes[2];


    binaryInputFile.open(("./stl/" + fileName).c_str(), std::ifstream::in | std::ifstream::binary);

    binaryInputFile.seekg(80);

    binaryInputFile.read((char*)&numberOfTriangles, sizeof(int));

    /////////////////////
    std::cout << std::endl << "current offset : " << offset << std::endl;

    for (int count = 0; count < numberOfTriangles; ++count)
    {
        float temp_float_var;

        // read the three components of the normal vector
        binaryInputFile.read((char*)&temp_float_var, 4); tri.normal.x = (double)temp_float_var;
        binaryInputFile.read((char*)&temp_float_var, 4); tri.normal.y = (double)temp_float_var;
        binaryInputFile.read((char*)&temp_float_var, 4); tri.normal.z = (double)temp_float_var;

        // read the three coordinates of vertex 1,2,3
        for (int i = 0; i < 3; ++i)
        {
            binaryInputFile.read((char*)&temp_float_var, 4); tri.vertex[i].x = (double)temp_float_var;
            binaryInputFile.read((char*)&temp_float_var, 4); tri.vertex[i].y = (double)temp_float_var;
            binaryInputFile.read((char*)&temp_float_var, 4); tri.vertex[i].z = (double)temp_float_var - offset;
        }

        // read the 2 unused bytes
        binaryInputFile.read(unused_bytes, 2);

        // update geometry extents along X, Y and Z based on vertex 1,2,3 of this triangle
        for (int i = 0; i < 3; ++i)
        {
            if (tri.vertex[i].x < x_min) x_min = tri.vertex[i].x;
            if (tri.vertex[i].x > x_max) x_max = tri.vertex[i].x;
            if (tri.vertex[i].y < y_min) y_min = tri.vertex[i].y;
            if (tri.vertex[i].y > y_max) y_max = tri.vertex[i].y;
            if (tri.vertex[i].z < z_min) z_min = tri.vertex[i].z;
            if (tri.vertex[i].z > z_max) z_max = tri.vertex[i].z;
        }

        facet.push_back(tri);
    }

    binaryInputFile.close();
}

void bone::draw() {

}

void bone::move() {

}

void bone::rotate() {

}