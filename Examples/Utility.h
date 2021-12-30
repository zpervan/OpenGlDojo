#ifndef OPENGLDOJO_UTILITY_H
#define OPENGLDOJO_UTILITY_H

#include "ThirdParty/GLFW/glfw3.h"

const char *g_vertex_shader_source = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *g_fragment_shader_source = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

/// @brief Whenever the window size is changed, this function is executed.
/// @param window Currently active window
/// @param width New width of the window
/// @param height New height of the window
/// @attention Make sure the viewport matches the new window dimensions; note that width and height will be
/// significantly larger than specified on retina displays.
void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

#endif  // OPENGLDOJO_UTILITY_H
