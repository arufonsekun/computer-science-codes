#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 640
#define HEIGHT 480

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        
}

int main() {

    GLFWwindow* window;

    // initializes the library
    if (!glfwInit()) return -1;

    // Create a window and OpenGL Context
    window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Loop", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        
        glClear(GL_COLOR_BUFFER_BIT);

        // double buffering
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;


}