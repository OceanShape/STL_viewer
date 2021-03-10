#include "readBINARY.h"

int readBinarySTL(std::string stlFileName, std::vector<triangle>& facet,
    double& x_min, double& x_max, double& y_min, double& y_max, double& z_min, double& z_max, double& offset)
{
    std::ifstream binaryInputFile;

    std::string stlFilePath = "./stl/";

    // open the STL file by using the full path and the name
    // specify that the file is opened in "read-only" mode
    // specify that the file is opened in binary format
    binaryInputFile.open((stlFilePath + stlFileName).c_str(), std::ifstream::in | std::ifstream::binary);


    if(binaryInputFile.fail())
    {
        std::cout << "ERROR: "<<stlFileName<<" load failed" << std::endl;
        exit(1);
    }

    // position the pointer to byte number 80
    binaryInputFile.seekg(80);

    // read the number of facets (triangles) in the STL geometry
    int numberOfTriangles;
    binaryInputFile.read((char*) &numberOfTriangles, sizeof(int));

    // declare an object "tri" of type triangle (see main.h for the definition of the triangle class)
    triangle tri;

    // storage space for the "unused bytes" 
    char unused_bytes[2];

    // initialize parameters that will be used to store the minimum and maximum extents of the geometry
    // described by the STL file
    x_min = 1e+30, x_max = -1e+30;
    y_min = 1e+30, y_max = -1e+30;
    z_min = 1e+30, z_max = -1e+30;

    // temporary floating point variable
    float temp_float_var;

    for (int count = 0; count < numberOfTriangles; ++count)
    {
        // read the three components of the normal vector
        binaryInputFile.read((char*)&temp_float_var,4); tri.normal.x = (double) temp_float_var;
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
        binaryInputFile.read(unused_bytes,2);


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

        // add data for this triangle to the "facet" vector
        facet.push_back(tri);
    }

    // explicitly close the connection to the input STL file
    binaryInputFile.close();

#if 0
    std::cout << "X range : " << x_min << " to " << x_max << " (delta = " << x_max - x_min << ")" << std::endl;
    std::cout << "Y range : " << y_min << " to " << y_max << " (delta = " << y_max - y_min << ")" << std::endl;
    std::cout << "Z range : " << z_min << " to " << z_max << " (delta = " << z_max - z_min << ")" << std::endl;

    std::cout << std::endl;
#endif

    return 0;
}
