#include "createVertexArray.h"

void createVertexArray(std::vector<triangle> & facet, float* vertices)
{
    const int NUM_FACETS = facet.size();
    int count = 0;
    for(int facet_index = 0; facet_index < NUM_FACETS; facet_index++)
    {
        // vertex 0
        {
            // x-y-z coordinates of the point
            vertices[count +  0] = facet[facet_index].vertex[0].x;
            vertices[count +  1] = facet[facet_index].vertex[0].y;
            vertices[count +  2] = facet[facet_index].vertex[0].z;
            // x-y-z coordinates of the normal
            vertices[count +  3] = facet[facet_index].normal.x;
            vertices[count +  4] = facet[facet_index].normal.y;
            vertices[count +  5] = facet[facet_index].normal.z;
            // (R,G,B,A) color values 
            vertices[count + 6] = 1.0f;
            vertices[count + 7] = 1.0f;
            vertices[count + 8] = 1.0f;
            vertices[count + 9] = 1.0f;
        }

        // vertex 1
        {
            // x-y-z coordinates of the point
            vertices[count + 10] = facet[facet_index].vertex[1].x;
            vertices[count + 11] = facet[facet_index].vertex[1].y;
            vertices[count + 12] = facet[facet_index].vertex[1].z;
            // x-y-z coordinates of the normal
            vertices[count + 13] = facet[facet_index].normal.x;
            vertices[count + 14] = facet[facet_index].normal.y;
            vertices[count + 15] = facet[facet_index].normal.z;
            // (R,G,B,A) color values 
            vertices[count + 16] = 1.0f;
            vertices[count + 17] = 1.0f;
            vertices[count + 18] = 1.0f;
            vertices[count + 19] = 1.0f;
        }

        // vertex 2
        {
            // x-y-z coordinates of the point
            vertices[count + 20] = facet[facet_index].vertex[2].x;
            vertices[count + 21] = facet[facet_index].vertex[2].y;
            vertices[count + 22] = facet[facet_index].vertex[2].z;
            // x-y-z coordinates of the normal
            vertices[count + 23] = facet[facet_index].normal.x;
            vertices[count + 24] = facet[facet_index].normal.y;
            vertices[count + 25] = facet[facet_index].normal.z;
            // (R,G,B,A) color values 
            vertices[count + 26] = 1.0f;
            vertices[count + 27] = 1.0f;
            vertices[count + 28] = 1.0f;
            vertices[count + 29] = 1.0f;
        }

        count += 30;
    }
}
