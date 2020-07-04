#ifndef VOXELGAME_SHADER_H
#define VOXELGAME_SHADER_H

#include <glad/glad.h>
#include <string>

#include "../math/vector.h"
#include "../math/matrix.h"

struct Path
{
    std::string path;

    std::string load_text_file() const;
};

class Shader
{
private:
    GLuint program_id;

    bool deleted;

    GLuint create_shader(GLuint shader_type, const std::string& shader_src);
public:
    Shader(const std::string& vs_src, const std::string& fs_src);

    Shader(const Shader& other) = delete;
    Shader& operator=(const Shader& other) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

    ~Shader();

    inline static void bind(const Shader& shader) { glUseProgram(shader.program_id); }
    inline static void unbind(const Shader& shader) { glUseProgram(0); }

    GLuint get_uniform(const std::string& name) const;

    inline void set_uniform_1f(const std::string& name, float value) const { glUniform1f(get_uniform(name), value); }
    inline void set_uniform_2f(const std::string& name, const vec2f& value) const { glUniform2f(get_uniform(name), value.x, value.y); }
    inline void set_uniform_3f(const std::string& name, const vec3f& value) const { glUniform3f(get_uniform(name), value.x, value.y, value.z); }
    inline void set_uniform_4f(const std::string& name, const vec4f& value) const { glUniform4f(get_uniform(name), value.x, value.y, value.z, value.w); }
    inline void set_uniform_mat4f(const std::string& name, const mat4f& mat) const { glUniformMatrix4fv(get_uniform(name), 1, true, mat.data); }
};


#endif //VOXELGAME_SHADER_H
