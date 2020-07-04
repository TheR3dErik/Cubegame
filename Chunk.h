#ifndef VOXELGAME_CHUNK_H
#define VOXELGAME_CHUNK_H

#include <memory>

#include "graphics/Model.h"

class Chunk
{
public:
    static constexpr int CHUNK_SIZE = 64;

    std::vector<int> chunk;
    std::shared_ptr<Model> model;

    Chunk(int offset_x, int offset_z);
};


#endif //VOXELGAME_CHUNK_H
