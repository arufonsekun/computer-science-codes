/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

bool rotate = false, scale = false;
float x = 0.0f, y=0.0f, sense = 1.0f, degree = 0.0f, scalee = 2.0f, degree_sense = 1.0f;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
    x += (0.01f * sense);

    if (x >= 1.0f){
        sense = -1.0f;
    }
    if (x <= -1.0){
        sense = 1.0f;
    }
    if (degree >= 360)
        degree_sense = -1.0f;
    else if (degree <= 0){
        degree_sense = 1.0f;
    }

    degree += 4.0f * degree_sense;

	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
    glLoadIdentity();

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a red square
	glColor3f(1, 0, 0);
    glTranslatef(x, y, x);
    
    if (rotate){
	    glRotatef(degree, 0.0f, 0.0f, 1.0f);
    }
    if (scale)
	    glScalef(scalee, scalee, 0);

	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	// Render a blue square
	/*glColor3f(0, 0, 1);
	glTranslatef(0.2f, 0.2f, 0);
	glRotatef(45.0f, 0, 0, 1.0f);
	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);*/

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}

    if (key == '1'){
        rotate = !rotate;
    }
    if (key == '2'){
        scale = !scale;
        scalee += 0.1f;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
    glutIdleFunc(display);
	glutKeyboardFunc(keyboard);


	glutMainLoop();
	return 0;
}