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

/**
 * to sem criatividade outra hora eu documeto
*/

class Square {
    private:
        Edge edges[4];
        float side;
    public:
        Square (Vertex v, float side) {
            edges[0] = Edge(v, side, 0.0f);
            v.x+=side;
            edges[1] = Edge(v, side, PI*0.5f);
            v.y+=side;
            edges[2] = Edge(v, side, PI);
            v.x -= side;
            edges[3] = Edge(v, side, PI*1.5f);
        }
        void draw () {
            for (Edge e : edges) e.draw();
        }
        void move(Vector vector) {
            edges[0].move(vector);
            edges[1].move(vector);
            edges[2].move(vector);
            edges[3].move(vector);
        }
        /*
        * Bottom left vertex
        * */
        float getX() {
            return edges[0].getX();
        }
};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {

    GLFWwindow* window;

    Vector v = Vector(0.002f, 0.0f, 0.0f);

    // vertical red line
    Vertex v_a; // v from Vertex
    v_a.x = -0.5f; v_a.y = -0.7f; v_a.z = 0.0f;
    //Edge e = Edge(v_a, 0.8f, PI * 2.0f);
    Square s = Square(v_a, 0.6f);

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

        s.move(v);
        s.draw();

        // double buffering
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}