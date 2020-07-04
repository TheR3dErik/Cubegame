#include "Chunk.h"

#include <cmath>
#include "../math/vector.h"

Chunk::Chunk(int offset_x, int offset_z)
{
    constexpr float vertices[] {
            0.0f,  0.0f,  0.0f,
            1.0f,  0.0f,  0.0f,
            1.0f,  1.0f,  0.0f,
            0.0f,  1.0f,  0.0f,
            0.0f,  0.0f,  1.0f,
            1.0f,  0.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            0.0f,  1.0f,  1.0f,
    };

    constexpr float normals[] {
            0.0f, 0.0f, -1.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f
    };

    chunk.reserve(CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE);

    constexpr int AIR = 0x00000000;
    constexpr int DIRT = 0x00000001;
    constexpr int GRASS = 0x00000002;
    constexpr int STONE = 0x00000003;

    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int z = 0; z < CHUNK_SIZE; z++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                int block = AIR;
                double height = CHUNK_SIZE/2 + cos((x+offset_x) * 0.10) * CHUNK_SIZE/8 + sin((z+offset_z) * 0.16) * CHUNK_SIZE/8;
                //double height = 0.25*(offset_x + x);
                //double height = 1.0 + (offset_x / 2.0);
                //double height = 1.0;
                //double height = 5.0;
                if (y < height - 4)
                    block = STONE;
                else if (y < height - 1)
                    block = DIRT;
                else if (y < height)
                    block = GRASS;

                chunk[x + z * CHUNK_SIZE + y * CHUNK_SIZE * CHUNK_SIZE] = block;
                chunk.emplace_back(block);
            }
        }
    }

    int num_indices = 0;
    int num_vertices = 0;
    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            for (int z = 0; z < CHUNK_SIZE; z++)
            {
                if (chunk[x + z * CHUNK_SIZE + y * CHUNK_SIZE * CHUNK_SIZE] == AIR || chunk[x + z * CHUNK_SIZE + y * CHUNK_SIZE * CHUNK_SIZE] == STONE)
                    continue;

                num_vertices += 72;

                // adds back face if necessary
                if ((z == 0) || chunk[x + (z-1)*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                    num_indices += 6;

                // adds front face if necessary
                if ((z == CHUNK_SIZE-1) || chunk[x + (z+1)*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                    num_indices += 6;

                // adds left face if necessary
                if ((x == 0) || chunk[x-1 + z*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                    num_indices += 6;

                // adds right face if necessary
                if ((x == CHUNK_SIZE-1) || chunk[x+1 + z*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                    num_indices += 6;

                // adds bottom face if necessary
                if ((y == 0) || chunk[x + z*CHUNK_SIZE + (y-1)*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                    num_indices += 6;

                // adds top face if necessary
                if ((y == CHUNK_SIZE-1) || chunk[x + z*CHUNK_SIZE + (y+1)*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                    num_indices += 6;
            }
        }
    }

    std::vector<float> vertices_improved;
    std::vector<unsigned int> indices_improved;
    vertices_improved.reserve(num_vertices);
    indices_improved.reserve(num_indices);
    int numBlocks = 0;
    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            for (int z = 0; z < CHUNK_SIZE; z++)
            {
                int block = chunk[x + z * CHUNK_SIZE + y * CHUNK_SIZE * CHUNK_SIZE];
                if (block == AIR || block == STONE)
                    continue;

                vec3f color = {1.0f, 0.0f, 1.0f};
                if (block == GRASS)
                    color = {20.0f / 255.0f, 219.0f / 255.0f, 40.0f / 255.0f};
                if (block == DIRT)
                    color = {107.0f/255.0f, 69.0f/255.0f, 43.0f/255.0f};
                else if (block == STONE)//stone
                    color = {0.5f, 0.5f, 0.5f};

                for (int i = 0; i < 8; i++)
                {
                    vertices_improved.push_back(vertices[i*3 + 0] + x);
                    vertices_improved.push_back(vertices[i*3 + 1] + y);
                    vertices_improved.push_back(vertices[i*3 + 2] + z);

                    vertices_improved.push_back(color.x);
                    vertices_improved.push_back(color.y);
                    vertices_improved.push_back(color.z);

                    vertices_improved.push_back(normals[i*3 + 0]);
                    vertices_improved.push_back(normals[i*3 + 1]);
                    vertices_improved.push_back(normals[i*3 + 2]);
                }

                // adds back face if necessary
                if ((z == 0) || chunk[x + (z-1)*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                {
                    indices_improved.push_back(numBlocks*8 + 0);
                    indices_improved.push_back(numBlocks*8 + 2);
                    indices_improved.push_back(numBlocks*8 + 1);

                    indices_improved.push_back(numBlocks*8 + 0);
                    indices_improved.push_back(numBlocks*8 + 3);
                    indices_improved.push_back(numBlocks*8 + 2);
                }

                // adds front face if necessary
                if ((z == CHUNK_SIZE-1) || chunk[x + (z+1)*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                {
                    indices_improved.push_back(numBlocks*8 + 5);
                    indices_improved.push_back(numBlocks*8 + 6);
                    indices_improved.push_back(numBlocks*8 + 7);

                    indices_improved.push_back(numBlocks*8 + 5);
                    indices_improved.push_back(numBlocks*8 + 7);
                    indices_improved.push_back(numBlocks*8 + 4);
                }

                // adds left face if necessary
                if ((x == 0) || chunk[x-1 + z*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                {
                    indices_improved.push_back(numBlocks*8 + 3);
                    indices_improved.push_back(numBlocks*8 + 0);
                    indices_improved.push_back(numBlocks*8 + 4);

                    indices_improved.push_back(numBlocks*8 + 3);
                    indices_improved.push_back(numBlocks*8 + 4);
                    indices_improved.push_back(numBlocks*8 + 7);
                }

                // adds right face if necessary
                if ((x == CHUNK_SIZE-1) || chunk[x+1 + z*CHUNK_SIZE + y*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                {
                    indices_improved.push_back(numBlocks*8 + 1);
                    indices_improved.push_back(numBlocks*8 + 6);
                    indices_improved.push_back(numBlocks*8 + 5);

                    indices_improved.push_back(numBlocks*8 + 1);
                    indices_improved.push_back(numBlocks*8 + 2);
                    indices_improved.push_back(numBlocks*8 + 6);
                }

                // adds bottom face if necessary
                if ((y == 0) || chunk[x + z*CHUNK_SIZE + (y-1)*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                {
                    indices_improved.push_back(numBlocks*8 + 4);
                    indices_improved.push_back(numBlocks*8 + 0);
                    indices_improved.push_back(numBlocks*8 + 1);

                    indices_improved.push_back(numBlocks*8 + 4);
                    indices_improved.push_back(numBlocks*8 + 1);
                    indices_improved.push_back(numBlocks*8 + 5);
                }

                // adds top face if necessary
                if ((y == CHUNK_SIZE-1) || chunk[x + z*CHUNK_SIZE + (y+1)*CHUNK_SIZE*CHUNK_SIZE] == AIR)
                {
                    indices_improved.push_back(numBlocks*8 + 6);
                    indices_improved.push_back(numBlocks*8 + 3);
                    indices_improved.push_back(numBlocks*8 + 7);

                    indices_improved.push_back(numBlocks*8 + 6);
                    indices_improved.push_back(numBlocks*8 + 2);
                    indices_improved.push_back(numBlocks*8 + 3);
                }
                numBlocks++;
            }
        }
    }
    model = std::make_shared<Model>(vertices_improved, indices_improved);
}
