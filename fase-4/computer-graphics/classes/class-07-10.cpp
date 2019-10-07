#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;

const unsigned int FRAMES_PER_SECOND = 40;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

void renderCoordinateAxis()
{
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

class Solid {
    public:
        float height, width, depth;
    
};

class Rectangle : public Solid {
    public:
        Rectangle(float h, float w, float d) {
            height = h;
            width = w;
            depth = d;
        }
        void draw() {
            glBegin(GL_LINES);
                glVertex3f(-width, -height, -depth);
                glVertex3f(width, -height, -depth);
                glVertex3f(width, -height, -depth);
                glVertex3f(width,height, -depth);
                glVertex3f(width,height, -depth);
                glVertex3f(-width,height, -depth);
                glVertex3f(-width,height, -depth);
                glVertex3f(-width, -height, -depth);
            glEnd();
            glBegin(GL_LINES);
                glVertex3f(-width, -height, depth);
                glVertex3f(width, -height, depth);
                glVertex3f(width, -height, depth);
                glVertex3f(width, height, depth);
                glVertex3f(width, height, depth);
                glVertex3f(-width, height, depth);
                glVertex3f(-width, height, depth);
                glVertex3f(-width, -height, depth);
            glEnd();
            glBegin(GL_LINES);
                glVertex3f(-width, -height, -depth);
                glVertex3f(-width, -height, depth);
                glVertex3f(width, -height, -depth);
                glVertex3f(width, -height, depth);
                glVertex3f(width, height, -depth);
                glVertex3f(width, height, depth);
                glVertex3f(-width, height, -depth);
                glVertex3f(-width, height, depth);
            glEnd();

        }
};

class Cube {
    private:
        float size, depth;
    public:
        Cube(float s, float d)
        {
            size = s;
            depth = d;
        }
        void draw()
        {
        glColor3f(1, 0, 0);
        glBegin(GL_LINES);
            glVertex3f(-size, -size, -depth);
            glVertex3f(size, -size, -depth);
            glVertex3f(size, -size, -depth);
            glVertex3f(size,size, -depth);
            glVertex3f(size,size, -depth);
            glVertex3f(-size,size, -depth);
            glVertex3f(-size,size, -depth);
            glVertex3f(-size, -size, -depth);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(-size, -size, depth);
            glVertex3f(size, -size, depth);
            glVertex3f(size, -size, depth);
            glVertex3f(size, size, depth);
            glVertex3f(size, size, depth);
            glVertex3f(-size, size, depth);
            glVertex3f(-size, size, depth);
            glVertex3f(-size, -size, depth);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(-size, -size, -depth);
            glVertex3f(-size, -size, depth);
            glVertex3f(size, -size, -depth);
            glVertex3f(size, -size, depth);
            glVertex3f(size,size, -depth);
            glVertex3f(size,size, depth);
            glVertex3f(-size,size, -depth);
            glVertex3f(-size,size, depth);
        glEnd();
    }
    
};

Rectangle c1 = Rectangle(2.0f, 1.0f, 1.0f);

void display()
{
    glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -10.0f);


	// Inform OpenGL we want to make changes to the modelview matrix

	renderCoordinateAxis();
    
    glRotatef(5.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(1, 0, 0);
    c1.draw();
    //glRotatef(5.0f, 1.0f, 0.0f, 0.0f);
    
    //c1.printAttr();

	// Render the X and Y axis to guide ourselves.
    
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) {
		exit(0);
	}
}

void update(int value)
{
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);

	glutMainLoop();
	return 0;
}

