/**
 * Demonstrate the different configurations of face culling and
 * the use of depth sorting (z-buffer).
 *
 * Author: Mihalis Tsoukalos
 * Contributions: Fernando Bevilacqua
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Global variables to control the rotation of the
// stripped cube according to user input.
GLfloat rX = -25.0;
GLfloat rY = 25.0;
GLfloat degrees = 15.0f; 
const int WIDTH = 800;
const int HEIGHT = 800;

bool f = true, b = false;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void renderScene()
{
    glColor3f(0, 0, 0);
	glutSolidCube(4.0f);

	glTranslatef(5.5f, 0.0f, -5.0f);
	glColor3f(0, 0, 1);
	glutSolidCube(4.0f);

	glColor3f(0, 1, 0);
	glTranslatef(0.0f, -2.0f, -30.0f);
	glScalef(100.0f, 0.2f, 200.0f);
	glutSolidCube(1.0f);
}

void display()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set the background color

	// Reset transformations
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glTranslatef(0, 0, -10.0f);

	// Rotate everything by a few degrees around the Y axis.
	glRotatef(degrees, 0.0f, 1.0f, 0.0f);


	// Rotate according to user input (rX and rY)
	renderScene();
    renderCoordinateAxis();

	//glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		exit(0);
	} else if (key == 'a') {
		glDepthFunc(GL_ALWAYS);
	} else if (key == 'g') {
		glDepthFunc(GL_GREATER);
	} else if (key == 'l') {
		glDepthFunc(GL_LESS);
	}
		 
	// Request display update
	glutPostRedisplay();
}

void keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) degrees += 15.0f;
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

void mousemove(int x, int y) {
    degrees += 5.0f;

    std::cout << x << "  " <<  y << std::endl;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);

	// Create window
	glutCreateWindow("Deth testing");

    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mousemove);

	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);
    initView();
	// Callback functions
	glutDisplayFunc(display);

	// Pass control to GLUT for events
	glutMainLoop();

	return 0;
}