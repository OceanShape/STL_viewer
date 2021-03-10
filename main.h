#pragma once

// OpenGL specific headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glu.h>

// include files
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <iomanip>
#include <locale>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "structs_and_classes.h"

void createVertexArray(std::vector<triangle> & facet, float* vertices);

extern int readBinarySTL(std::string stlFilename, std::vector<triangle>& facet,
    double& x_min, double& x_max, double& y_min, double& y_max, double& z_min, double& z_max, double& offset);