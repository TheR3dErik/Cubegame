#include <iostream>

#include "graphics/window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <array>
#include <chrono>

#include "math/vector.h"
#include "math/matrix.h"

#include "graphics/Shader.h"
#include "graphics/Model.h"
#include "graphics/PerspectiveCamera.h"
#include "Chunk.h"

void process_input();

PerspectiveCamera camera{{0,0,0},1,1,1,1};
bool wireframe_mode = false;

constexpr int GRID_SIZE = 8;

int main()
{
    window::init(720, 480, "Now in C++!");

    glEnable(GL_DEPTH_TEST);
    // Enables wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glProvokingVertex(GL_FIRST_VERTEX_CONVENTION); // allows flat shading with normals

    // culls back faces (which are clockwise)
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    // sets background to sky blue
    glClearColor(87.0f/255.0f, 216.0f/255.0f, 1.0f, 1.0f);

    Shader shader{Path{"main.vert"}.load_text_file(), Path{"main.frag"}.load_text_file()};
    Shader::bind(shader);

    auto chunk_start = std::chrono::steady_clock::now();

    std::vector<Chunk> chunks;
    chunks.reserve(GRID_SIZE*GRID_SIZE);

    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int z = 0; z < GRID_SIZE; z++)
        {
            chunks.emplace_back(Chunk{x*Chunk::CHUNK_SIZE, z*Chunk::CHUNK_SIZE});
        }
    }

    auto chunk_end = std::chrono::steady_clock::now();
    std::cout << "Generating chunks took a total of " << std::chrono::duration_cast<std::chrono::milliseconds>(chunk_end-chunk_start).count() * 0.001 << " seconds." << std::endl;

    camera = PerspectiveCamera{{0,0,10},window::get_width()*1.0f/window::get_height(),60.0f, 1.0f, 1000.0f};
    mat4f temp{};

    shader.set_uniform_mat4f("model", mat4f{}.identity());
    camera.view_matrix(temp);
    shader.set_uniform_mat4f("view", temp);
    camera.projection_matrix(temp);
    shader.set_uniform_mat4f("projection", temp);

    auto last_time = std::chrono::steady_clock::now();
    double total_fps = 0.0;
    int fps_refresh_cycle = 60;
    int fps_counter = 0;

    Chunk chunk1 {0,0};
    Chunk chunk2 {GRID_SIZE,0};
    Chunk chunk3 {0,GRID_SIZE};
    Chunk chunk4 {GRID_SIZE,GRID_SIZE};

    while (window::is_running())
    {
        window::poll_events();

        auto now = std::chrono::steady_clock::now();
        total_fps += 1.0 / (0.000000001 * std::chrono::duration_cast<std::chrono::nanoseconds>(now - last_time).count());
        last_time = now;

        fps_counter++;
        if (fps_counter == fps_refresh_cycle)
        {
            fps_counter = 0;
            std::cout << "FPS: " << (total_fps / fps_refresh_cycle) << std::endl;
            total_fps = 0.0;
        }

        process_input();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.view_matrix(temp);
        shader.set_uniform_mat4f("view", temp);

        for (int x = 0; x < GRID_SIZE; x++)
        {
            for (int z = 0; z < GRID_SIZE; z++)
            {
                temp.translate({x*1.0f*Chunk::CHUNK_SIZE, 0.0f, z*1.0f*Chunk::CHUNK_SIZE});
                shader.set_uniform_mat4f("model", temp);
                Model::bind(*chunks[x*GRID_SIZE + z].model);
                chunks[x*GRID_SIZE + z].model->render();
            }
        }

        window::update();
    }

    window::dispose();
    return 0;
}

void process_input()
{
    if (window::is_key_tapped(GLFW_KEY_ESCAPE))
        window::quit();

    float angular_speed = 2.5f;
    if (window::is_key_pressed(GLFW_KEY_UP))
        camera.pitch += angular_speed;
    if (window::is_key_pressed(GLFW_KEY_DOWN))
        camera.pitch -= angular_speed;
    if (window::is_key_pressed(GLFW_KEY_LEFT))
        camera.yaw += angular_speed;
    if (window::is_key_pressed(GLFW_KEY_RIGHT))
        camera.yaw -= angular_speed;

    float linear_speed = 0.25f;
    if (window::is_key_pressed(GLFW_KEY_SPACE))
        camera.position.y += linear_speed;
    if (window::is_key_pressed(GLFW_KEY_LEFT_SHIFT))
        camera.position.y -= linear_speed;

    if (window::is_key_pressed(GLFW_KEY_W))
    {
        vec3f forward{};
        camera.direction_vector(forward);
        forward *= linear_speed;
        camera.position += forward;
    }
    if (window::is_key_pressed(GLFW_KEY_S))
    {
        vec3f forward{};
        camera.direction_vector(forward);
        forward *= linear_speed;
        camera.position -= forward;
    }
    if (window::is_key_pressed(GLFW_KEY_D))
    {
        vec3f forward{};
        camera.right_vector(forward);
        forward *= linear_speed;
        camera.position += forward;
    }
    if (window::is_key_pressed(GLFW_KEY_A))
    {
        vec3f forward{};
        camera.left_vector(forward);
        forward *= linear_speed;
        camera.position += forward;
    }

    if (window::is_key_tapped(GLFW_KEY_Z))
    {
        wireframe_mode = !wireframe_mode;
        glPolygonMode(GL_FRONT_AND_BACK, wireframe_mode ? GL_LINE : GL_FILL);
    }
}
