#include "window.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <array>

namespace window
{
    namespace
    {
        GLFWwindow *window;

        std::array<bool, 512> last_keys;
        std::array<bool, 512> keys;

        int width, height;
        std::string title;

        void key_callback(GLFWwindow *w, int key, int scancode, int action, int mods)
        {
            if (key < 0 || key >= keys.size())
                return;

            if (action == GLFW_PRESS)
                keys[key] = true;
            else if (action == GLFW_RELEASE)
                keys[key] = false;
        }

        void resize_callback(GLFWwindow *w, int new_width, int new_height)
        {
            glViewport(0, 0, new_width, new_height);

            width = new_width;
            height = new_height;
        }
    }

    void init(int w, int h, const std::string& t)
    {
        title = t;
        width = w;
        height = h;

        if (!glfwInit())
            std::cerr << "Unable to initialize GLFW" << std::endl;

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_SAMPLES, 4);

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (!window)
            std::cout << "Failed to create GLFW window" << std::endl;

        const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwSetWindowPos(window, (vidmode->width - width) / 2, (vidmode->height - height) / 2);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwShowWindow(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
        glViewport(0, 0, width, height);

        glfwSetFramebufferSizeCallback(window, resize_callback);
        auto &tmp = keys;
        glfwSetKeyCallback(window, key_callback);
    }

    void quit()
    {
        glfwSetWindowShouldClose(window, true);
    }

    void dispose()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool is_running()
    {
        return !glfwWindowShouldClose(window);
    }

    void poll_events()
    {
        glfwPollEvents();
    }

    void update()
    {
        glfwSwapBuffers(window);
        last_keys = keys;
    }

    bool is_key_tapped(int key)
    {
        return keys[key] && !last_keys[key];
    }

    bool is_key_pressed(int key)
    {
        return keys[key];
    }

    bool is_key_released(int key)
    {
        return !keys[key];
    }

    int get_width()
    {
        return width;
    }

    int get_height()
    {
        return height;
    }
}
