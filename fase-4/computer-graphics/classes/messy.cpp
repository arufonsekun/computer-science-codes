/**
 * Basic usege of OpenGL and GLFW.
 */

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

struct point{
	float x, y, z;
};

int SENSE = 1;
int SENSE1 = -1;
float SPEED = 0.001f;

point a = { -0.5f, 0.5f, 0.0f };
point b = { 0.5f, 0.5f, 0.0f };

float SIDE_SIZE = 0.4f;

point tl = { -0.5f, 0.5f, 0.0f };
point tr = { tl.x + SIDE_SIZE, tl.y, 0.0f };
point bl = { tl.x, tl.y - SIDE_SIZE, 0.0f };
point br = { tr.x, tr.y - SIDE_SIZE, 0.0f };

point tl1 = { 0.5f, 0.5f, 0.0f };
point tr1 = { tl1.x + SIDE_SIZE, tl1.y, 0.0f };
point bl1 = { tl1.x, tl1.y - SIDE_SIZE, 0.0f };
point br1 = { tr1.x, tr1.y - SIDE_SIZE, 0.0f };

point t1 = { 0.0f, 0.0f, 0.0f }

int main() {
	GLFWwindow* window;
	int width, height;

	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}

	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glBegin(GL_TRIANGLES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-0.6f, -0.4f, 0.f);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.6f, -0.4f, 0.f);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(0.f, 0.6f, 0.f);
		glEnd();

		/* linha que se move
		glBegin(GL_LINES);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(a.x, a.y, a.z);
			glVertex3f(b.x, b.y, b.z);

			a.x = a.x + (SPEED * SENSE);
			b.x = b.x + (SPEED * SENSE);

			if (b.x >= 0.7f)
			{
				SENSE = -1;
				b.x = 0.68f;
			}

			if (a.x <= -0.7f)
			{
				SENSE = 1;
				a.x = -0.68f;
			}

		glEnd();*/

		//quadrado

		glBegin(GL_LINES);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(tl.x, tl.y, tl.z);
			glVertex3f(tr.x, tr.y, tr.z);

			glVertex3f(bl.x, bl.y, bl.z);
			glVertex3f(br.x, br.y, br.z);

			glVertex3f(tl.x, tl.y, tl.z);
			glVertex3f(bl.x, bl.y, bl.z);

			glVertex3f(tr.x, tr.y, br.z);
			glVertex3f(br.x, br.y, br.z);

			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(tl1.x, tl1.y, tl1.z);
			glVertex3f(tr1.x, tr1.y, tr1.z);

			glVertex3f(bl1.x, bl1.y, bl1.z);
			glVertex3f(br1.x, br1.y, br1.z);

			glVertex3f(tl1.x, tl1.y, tl1.z);
			glVertex3f(bl1.x, bl1.y, bl1.z);

			glVertex3f(tr1.x, tr1.y, br1.z);
			glVertex3f(br1.x, br1.y, br1.z);

			tl.x = tl.x + SPEED * SENSE;
			tr.x = tr.x + SPEED * SENSE;
			bl.x = bl.x + SPEED * SENSE;
			br.x = br.x + SPEED * SENSE;


			if (tr.x >= 0.7f)
			{
				SENSE = -1;
				tr.x = 0.7f;
			}

			if (tl.x <= -0.6f)
			{
				SENSE = 1;
				tl.x = -0.6f;
			}

			tl1.x = tl1.x + SPEED * SENSE1;
			tr1.x = tr1.x + SPEED * SENSE1;
			bl1.x = bl1.x + SPEED * SENSE1;
			br1.x = br1.x + SPEED * SENSE1;


			if (tr1.x <= -0.7f)
			{
				SENSE = 1;
				tr1.x = -0.7f;
			}

			if (tl1.x >= 0.7f)
			{
				SENSE = -1;
				tl1.x = 0.7f;
			}

		glEnd();

		// Desenhando triangulos

		glBegin(GL_TRIANGLES)
			glColor3f(1.0f, 1.0f, 1.0f);

		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
