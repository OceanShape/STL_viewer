#pragma once

struct Vec3D
{
    double x;
    double y;
    double z;
};

class triangle
{
public:
    Vec3D normal;
    Vec3D vertex[3];
};