#ifndef VOXELGAME_MODEL_H
#define VOXELGAME_MODEL_H

#include <glad/glad.h>

#include <vector>

struct Model
{
    GLuint vao, vbo, ebo;
    int num_indices;

    Model(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
    Model(int num_vertices, int num_indices);

    Model(const Model& other) = delete;
    Model& operator=(const Model& other) = delete;

    Model(Model&& other) noexcept;
    Model& operator=(Model&& other) noexcept;

    ~Model();

    inline static void bind(const Model& model) { glBindVertexArray(model.vao); }
    inline static void unbind(const Model& model) { glBindVertexArray(0); }

    inline void render() { glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, 0); }

private:
    bool deleted;

    void init(const float* vertices, int num_vertices, const unsigned int* indices, int num_indices);
};


#endif //VOXELGAME_MODEL_H
