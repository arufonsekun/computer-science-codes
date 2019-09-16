#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

#define WIDTH 640
#define HEIGHT 480

#define COS_60 0.5f
#define SEN_60 0.866

struct point {
    float x, y, z = 0.0f;
};

point a, b, c;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void draw_triangle() {
    glBegin(GL_TRIANGLES);

    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
    glVertex3f(c.x, c.y, c.z);

    glEnd();
}

//define point 'a' and then pass a distance to this func to create an equilateral triangle
void built_equi_triangle(float dist) {
    b.x = (COS_60 * dist) + a.x;
    b.y = (SEN_60 * dist) + a.y;
    c.x = a.x + dist;
    c.y = a.y;
}

int main() {

    GLFWwindow* window;

    a.x = 0.1f; a.y = 0.1f;
    built_equi_triangle(0.8);

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

        draw_triangle();

        // double buffering
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;


}