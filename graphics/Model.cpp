#include "Model.h"

Model::Model(const std::vector<float> &vertices, const std::vector<unsigned int> &indices): deleted{false}, num_indices{static_cast<int>(indices.size())}
{
    init(&vertices[0], vertices.size(), &indices[0], indices.size());
}

Model::Model(int num_vertices, int num_indices): deleted{false}, num_indices(num_indices)
{
    init(nullptr, num_vertices, nullptr, num_indices);
}

void Model::init(const float *vertices, int num_vertices, const unsigned int *indices, int num_indices)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*num_vertices, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*num_indices, indices, GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    //glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9*4, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9*4, (void*)(3*4));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9*4, (void*)(6*4));
    glEnableVertexAttribArray(2);
}

Model::Model(Model &&other) noexcept: deleted{false}, vao{other.vao}, vbo{other.vbo}, ebo{other.ebo}, num_indices{other.num_indices}
{
    other.deleted = true;
}

Model &Model::operator=(Model &&other) noexcept
{
    other.deleted = true;
    this->vao = other.vao;
    this->vbo = other.vbo;
    this->ebo = other.ebo;
    this->num_indices = other.num_indices;
    return *this;
}

Model::~Model()
{
    if (!deleted)
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    }
}
