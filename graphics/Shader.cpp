#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <sstream>

std::string Path::load_text_file() const
{
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

GLuint Shader::create_shader(GLuint shader_type, const std::string &shader_src)
{
    auto shader = glCreateShader(shader_type);

    const char * src = shader_src.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, info_log);
        if (shader_type == GL_VERTEX_SHADER)
            std::cout << "Vertex ";
        else if (shader_type == GL_FRAGMENT_SHADER)
            std::cout << "Fragment ";
        std::cout << "Shader compilation failed!" << std::endl << info_log << std::endl;
    }

    return shader;
}

Shader::Shader(const std::string &vs_src, const std::string &fs_src): deleted{false}
{
    program_id = glCreateProgram();

    GLuint vert_id = create_shader(GL_VERTEX_SHADER, vs_src);
    GLuint frag_id = create_shader(GL_FRAGMENT_SHADER, fs_src);

    glAttachShader(program_id, vert_id);
    glAttachShader(program_id, frag_id);
    glLinkProgram(program_id);

    int success;
    char info_log[512];
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program_id, 512, nullptr, info_log);
        std::cout << "Program linking failed!" << std::endl << info_log << std::endl;
    }

    glDeleteShader(vert_id);
    glDeleteShader(frag_id);
}

Shader::Shader(Shader &&other) noexcept: deleted{false}, program_id{other.program_id}
{
    other.deleted = true;
}

Shader &Shader::operator=(Shader &&other) noexcept
{
    other.deleted = true;
    this->program_id = other.program_id;
    return *this;
}

Shader::~Shader()
{
    if (!deleted)
        glDeleteProgram(program_id);
}

GLuint Shader::get_uniform(const std::string &name) const
{
    return glGetUniformLocation(program_id, name.c_str());
}
