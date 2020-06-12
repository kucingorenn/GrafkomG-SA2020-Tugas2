#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

double rad = 0;
double brad = 0;

void drawCircle(double r, int vertex, int jarakmuter,float speedrad) {
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double y = r * sin(2 * M_PI * i / ngon);
		glVertex2d(sin(rad * speedrad) * jarakmuter + x + 250, cos(rad * speedrad) * jarakmuter + y + 250);
		
	}
	glEnd();
}

void drawCircleLines(double r, int vertex) {
	double ngon = (double)vertex;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double y = r * sin(2 * M_PI * i / ngon);
		glVertex2d(x + 250, y + 250);
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
		glVertex2d(x + 250, y + 250);
	}
	glEnd();
	glColor3ub(200, 200, 200); //track orbit
	drawCircleLines(50, 100);

	glColor3ub(200, 200, 200);
	drawCircleLines(100, 100);

	glColor3ub(200, 200, 200);
	drawCircleLines(150, 100);

	glColor3ub(200, 200, 200);
	drawCircleLines(200, 100);

	glColor3ub(213, 210, 209); //merc
	drawCircle(5, 100, 50, 5);

	glColor3ub(200, 200, 13); //venus
	drawCircle(6, 100, 100, 3);

	glColor3ub(52, 66, 119); //earth
	drawCircle(7, 100, 150, 2);

	glColor3ub(200, 200, 13);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		double x = 2 * cos(2 * M_PI * i / 100);
		double y = 2 * sin(2 * M_PI * i / 100);
		glVertex2d(sin(rad * 3) * 20 + x + 250, cos(rad * 3) * 20 + y + 100);

	}
	glEnd();

	glColor3ub(161, 37, 27); //mars
	drawCircle(5, 100, 200, 1);

	glutSwapBuffers();
}

void Timer(int) {
	rad += 0.01f;
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, Timer, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
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
