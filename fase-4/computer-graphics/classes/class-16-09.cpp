#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

#define WIDTH 2048
#define HEIGHT 1024

#define COS_60 0.5f
#define SEN_60 0.866

float x1Scale = 1.0f;
float y1Scale = 1.0f;

float x2Scale = 1.0f;
float y2Scale = 1.0f;

struct point {
    float x, y, z = 0.0f;
};

point a1, b1, c1, d1;
point a2, b2, c2, d2;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS){
        x1Scale *= 2.0f;
        y1Scale *= 2.0f;
        
        x2Scale *= 2.0f;
        y2Scale *= 2.0f;
    }

    else if (key == GLFW_KEY_ENTER && action == GLFW_PRESS){
        x1Scale *= 0.5f;
        y1Scale *= 0.5f;

        x2Scale *= 2.0f;
        y2Scale *= 2.0f;
    }
}

int main() {

    GLFWwindow* window;
    float move1 = 0.01f;

    float move2 = -0.01f;

    float size = 0.3f;

    a1.x = -0.5f; a1.y = 0.5f;
    b1.x = a1.x + size; b1.y = a1.y;
    c1.x = b1.x; c1.y = b1.y - size;
    d1.x = c1.x - 0.2f; d1.y = c1.y;

    a2.x = -0.5f; a2.y = -0.5f;
    b2.x = a2.x + size; b2.y = a2.y;
    c2.x = b2.x; c2.y = b2.y - size;
    d2.x = c2.x - size; d2.y = a2.y;

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
    
        glColor3f(0.4f, 0.3f, 0.5f);


        glLoadIdentity();
        
            /* Tarefa 1 */
            glScalef(x1Scale, y1Scale, 1.0f);
            
            glBegin(GL_LINES);
                glVertex3f(a1.x, a1.y, a1.z);
                glVertex3f(b1.x, b1.y, b1.z);

                glVertex3f(b1.x, b1.y, b1.z);
                glVertex3f(c1.x, c1.y, c1.z);

                glVertex3f(c1.x, c1.y, c1.z);
                glVertex3f(d1.x, d1.y, d1.z);

                glVertex3f(d1.x, d1.y, d1.z);
                glVertex3f(a1.x, a1.y, a1.z);
            glEnd();


            /* Tarefa 2 */
            glScalef(x2Scale, y2Scale, 1.0f);
            glBegin(GL_LINES);
                glVertex3f(a2.x, a2.y, a2.z);
                glVertex3f(b2.x, b2.y, b2.z);

                glVertex3f(b2.x, b2.y, b2.z);
                glVertex3f(c2.x, c2.y, c2.z);

                glVertex3f(c2.x, c2.y, c2.z);
                glVertex3f(d2.x, d2.y, d2.z);

                glVertex3f(d2.x, d2.y, d2.z);
                glVertex3f(a2.x, a2.y, a2.z);
            glEnd();
            

            /*a1.x += move1; b1.x += move1;
            c1.x += move1; d1.x += move1;*/

            a2.x += move2; b2.x += move2;
            c2.x += move2; d2.x += move2;

            if (b1.x > 0.8)
                move1 *= -1;

            else if (b1.x < 0)
                move1 *= -1;

            if (b2.x >= 0.8)
                move2 *= -1;

            else if (b2.x < 0)
                move2 *= -1;            

        // double buffering
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;


}