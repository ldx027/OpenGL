#include <glad/glad.h>
#include <GLFW/glfw3.h>

void frameBufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "openGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(1.0f, 0.9f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void frameBufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}