#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

double rad = 0;
//glVertex2d(sin(rad) * 100 + x, cos(rad) * 100 + y);

void drawCircle(double r, int vertex) {
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double y = r * sin(2 * M_PI * i / ngon);
		glVertex2d(sin(rad) * 100 + x + 250, cos(rad) * 100 + y+250);
	}
	glEnd();
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(253, 184, 19);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		double x = 20 * cos(2 * M_PI * i / 100);
		double y = 20 * sin(2 * M_PI * i / 100);
		glVertex2d(x+250, y+250);
	}
	glEnd();

	glColor3ub(213, 210, 209);
	drawCircle(10, 80);
	glutSwapBuffers();
}

void Timer(int) {
	rad += 0.1f;

	glutPostRedisplay();
	glutTimerFunc(1000 / 60, Timer, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	gluOrtho2D(0, 500, 0, 500);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutTimerFunc(1000 / 60, Timer, 1);
	glutDisplayFunc(Display);
	glutMainLoop();

	return(0);
}
