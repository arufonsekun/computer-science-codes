/**
 * OpenGl instalation, and all related
 * code requirements come from
 * github.com/Dovyski/opengl-demos
*/

#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

using namespace std;

#define WIDTH 1024
#define HEIGHT 640

#define PI 3.14159265f

GLfloat x = 0.3f, y = 0.3f, z = 0.3f;

/**
 * Vertex is the most basic component in this context.
 * It defines a cartesian coordinate on 3D space.
 */
struct Vertex {
    float x, y, z = 0.0f;
};

/**
 * distance" function purpose is to compute
 * the euclidian distance between two cartesian coordinates
 * in this case represented by Vertex type.
*/
float distance(Vertex a, Vertex b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

float distance(Vertex a) {
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

float distance(float x, float y, float z = 0.0f) {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

/**
 * Vector type is used mainly for move things around.
 * The vector constituents are a vertex and a module.
 * Module property is computed based on euclidian distance.
 */
class Vector {
    private:
        Vertex a;
        float module;
    public:
        Vector(float x, float y, float z=0.0f) {
            a.x = x; a.y = y; a.z = z;
            module = distance(x, y, z);
        }
        float getX(){ return a.x; }
        float getY(){ return a.y; }
        float getZ(){ return a.z; }
        float mod(){ return module; }
};

/*
 * Edge type represents an OpenGl line.
 * This type has three distict constructors.
 * The empty Edge() constructor was needed
 * for array edge instantiation, required by Square type.
 * Edge(Vertex v, float module, float degree)
 * creates a new edge based on a Vertex,
 * a distance represented by the module parameter,
 * the degree argument defines the line slope.
 * Edge(Vertex v1, Vertex v2) creates a line
 * limited by two Vertices.
 */

class Edge {
    private:
        Vertex a, b;
    public:
        Edge()
        {

        }
        Edge(Vertex v, float module, float degree) {
            a = v;
            b.x = a.x + (cos(degree) * module);
            b.y = a.y + (sin(degree) * module);
            b.z = 0.0f;
        }
        Edge(Vertex v1, Vertex v2) {
            a = v1;
            b = v2;
        }
        void draw() {
            glBegin(GL_LINES);
                glVertex3f(a.x, a.y, a.z);
                glVertex3f(b.x, b.y, b.z);
            glEnd();
        }
        void move(Vector v) {
            a.x += v.getX(); a.y += v.getY(); a.z += v.getZ();
            b.x += v.getX(); b.y += v.getY(); b.z += v.getZ();
        }
        float getX() {
            return a.x;
        }
};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


int main() {

    GLFWwindow* window;
    Vertex a, b, c, d, e, f;

    // Edge cube[12];

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

        glColor3f(0.4f, 0.3f, 0.5f);
        glBegin(GL_TRIANGLES);
            glVertex3f(x, y, z);
            glVertex3f(x, -y, z);
            glVertex3f(-x, y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(-x, -y, -z);
            glVertex3f(-x, y, -z);
            glVertex3f(x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(-x, -y, -z);
            glVertex3f(-x, y, -z);
            glVertex3f(x, -y, -z);
        glEnd();

        /*glColor3f(0.5f, 0.3f, 0.2f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, -y, z);
            glVertex3f(x, -y, z);
            glVertex3f(-x, y, z);
        glEnd();

        // FRONT
        // Using 4 trianges!
        glColor3f(0.1f, 0.5f, 0.3f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, y, -z);
            glVertex3f(0, 0, -z);
            glVertex3f(-x, -y, -z);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, -y, -z);
            glVertex3f(0, 0, -z);
            glVertex3f(x, -y, -z);
        glEnd();

        glColor3f(0.1f, 0.3f, 0.3f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, y, -z);
            glVertex3f(x, y, -z);
            glVertex3f(0, 0, -z);
        glEnd();

        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_TRIANGLES);
            glVertex3f(0, 0, -z);
            glVertex3f(x, y, -z);
            glVertex3f(x, -y, -z);
        glEnd();

        // LEFT
        glColor3f(0.3f, 0.5f, 0.6f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, -y, -z);
            glVertex3f(-x, -y, z);
            glVertex3f(-x, y, -z);
        glEnd();

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, y, z);
            glVertex3f(-x, -y, z);
            glVertex3f(-x, y, -z);
        glEnd();

        // RIGHT
        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_TRIANGLES);
            glVertex3f(x, y, z);
            glVertex3f(x, y, -z);
            glVertex3f(x, -y, z);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLES);
            glVertex3f(x, -y, -z);
            glVertex3f(x, y, -z);
            glVertex3f(x, -y, z);
        glEnd();

        // TOP
        glColor3f(0.6f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLES);
            glVertex3f(x, y, z);
            glVertex3f(x, y, -z);
            glVertex3f(-x, y, -z);
        glEnd();

        glColor3f(0.6f, 0.1f, 0.2f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, y, z);
            glVertex3f(x, y, z);
            glVertex3f(-x, y, -z);
        glEnd();

        // BOTTOM
        glColor3f(0.4f, 0.0f, 0.4f);
        glBegin(GL_TRIANGLES);
            glVertex3f(-x, -y, -z);
            glVertex3f(-x, -y, z);
            glVertex3f(x, -y, z);
        glEnd();

        glColor3f(0.3f, 0.0f, 0.3f);
        glBegin(GL_TRIANGLES);
            glVertex3f(x, -y, -z);
            glVertex3f(-x, -y, -z);
            glVertex3f(x, -y, z);
        glEnd();*/

        glFlush();

        

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}