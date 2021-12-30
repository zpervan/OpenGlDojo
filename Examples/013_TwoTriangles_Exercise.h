/**
 * Exercise - Try to draw 2 triangles next to each other using glDrawArrays by adding more vertices to your data
 **/

#ifndef OPENGLDOJO_013_TWOTRIANGLES_EXERCISE_H
#define OPENGLDOJO_013_TWOTRIANGLES_EXERCISE_H

#include "ThirdParty/GLFW/glfw3.h"
#include "ThirdParty/glad/glad.h"
#include "Utility.h"

#include <array>

int _013_TwoTriangles()
{
    // Initialize and configure GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFW window creation - Skipping window creation check (for lulz).
    GLFWwindow* window{glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL)};

    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return EXIT_FAILURE;
    }

    // ------------ Exercise 1 ------------

    // vertex shader
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &g_vertex_shader_source, nullptr);
    glCompileShader(vertex_shader);

    // check for shader compile errors
    int success{0};
    char info_log[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << std::endl;
    }

    // fragment shader
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &g_fragment_shader_source, nullptr);
    glCompileShader(fragment_shader);

    // check for shader compile errors
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log << std::endl;
    }

    // link shaders
    unsigned int shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    // check for linking errors
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shader_program, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << std::endl;
    }
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // Vertex data of two triangles
    std::array<float, 27> vertices{
        -0.5f, -0.5f, 0.0f, // left first triangle
        0.5f, -0.5f, 0.0f,  // right first triangle
        0.0f,  0.5f, 0.0f,  // top first triangle
        0.2f, 0.0f, 0.0f,   // left second triangle
        0.4f, 0.4f, 0.0f,   // top second triangle
        0.6f, 0.0f, 0.0f    // right second triangle
//        -0.2f, 0.0f, 0.0f,   // left third triangle
//        -0.4f, -0.4f, 0.0f,   // top third triangle
//        -0.6f, 0.0f, 0.0f   // right third triangle
    };

    unsigned int vbo{0}; // Vertex Buffer Object
    unsigned int vao{0}; // Vertex Array Object

    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    // Number of vertices in an array subtracted with 3 - position vectors
    const std::size_t vertices_array_size{vertices.size() / 3};

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        // Rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shader_program);
        glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, vertices_array_size);

        // Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shader_program);

    glfwTerminate();
    return EXIT_SUCCESS;
}

#endif