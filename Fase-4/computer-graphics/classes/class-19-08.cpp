#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

using namespace std;

#define WIDTH 640
#define HEIGHT 480

#define COS_60 0.5f
#define SEN_60 0.866

struct vertex {
    float x, y, z = 0.0f;
};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void draw_vertical_red_line(vertex* a, float dist) {
    dist = sqrt(2 * pow(dist, 2));
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    
    glVertex3f(a->x, a->y, a->z);
    glVertex3f(a->x + dist, a->y + dist, a->z);

    glEnd();

}

void draw_parallel_line(vertex* a, float dist) {
    glBegin(GL_LINES);
    
    glVertex3f(a->x, a->y, a->z);
    glVertex3f(a->x, a->y + dist, a->z);
    
    glEnd();

}

void draw_square(vertex* a, float side) {
   
    //glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);

    glVertex3f(a->x, a->y, a->z);
    glVertex3f(a->x + side, a->y, a->z);
    
    a->x += side;
    
    glVertex3f(a->x, a->y, a->z);
    glVertex3f(a->x, a->y + side, a->z);
    a->y += side;

    glVertex3f(a->x, a->y, a->z);
    glVertex3f(a->x - side, a->y, a->z);

    a->x -= side;
    glVertex3f(a->x, a->y, a->z);
    glVertex3f(a->x, a->y - side, a->z);

    glEnd();

} 

int main() {

    GLFWwindow* window;

    // vertical red line
    vertex v_a; // v from Vertex
    v_a.x = 0.0f; v_a.y = 0.0f; v_a.z = 0.0f;

    vertex v_b;
    v_b.x = -0.3f; v_b.y = -0.5; v_b.z = 0.0f;

    // initializes the library
    if (!glfwInit()) return -1;

    // Create a window and OpenGL Context
    window = glfwCreateWindow(WIDTH, HEIGHT, "class 19/08 ", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        
        glClear(GL_COLOR_BUFFER_BIT);

        // call drawing funcions here
        // draw_vertical_red_line(&v_a, 0.5f);

        // draw parallel line
        // draw_parallel_line(&v_a, 0.5f);
        // draw_parallel_line(&v_b, 0.5f);

        //draw blue square
        draw_square(&v_a, 0.5f);

        // double buffering
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;


}