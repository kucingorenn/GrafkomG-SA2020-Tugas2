#include <iostream>
#include <GL/freeglut.h>

float xpos = 0;
float ypos = 0;
float deltax = 5;
float deltay = 10;
bool toRight = true;
bool toUp = true;
int time = 30;
bool pause = false;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glVertex2f(-9 + xpos, 12 + ypos);
	glVertex2f(-9 + xpos, -12 + ypos);
	glVertex2f(9 + xpos, -12 + ypos);
	glVertex2f(9 + xpos, 12 + ypos);

	glEnd();
	glutSwapBuffers();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

void myKeyboard(unsigned char key, int x, int y) {

	if (key == 'p' && !pause) {
		time = 1;
		pause = true;
	}
	else if (key == 'p' && pause) {
		time = 30;
		pause = false;
	}


	std::cout << "key " << key << " pressed" << std::endl;
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / time, timer, 0);

	if (xpos < 488 && toRight) {
		xpos += deltax;
	}
	else {
		toRight = false;
	}

	if (ypos < 488 && toUp) {
		ypos += deltay;
	}
	else {
		toUp = false;
	}

	if (ypos > -488 && !toUp) {
		ypos -= deltay;
	}
	else {
		toUp = true;
	}

	if (xpos > -488 && !toRight) {
		xpos -= deltax;
	}
	else {
		toRight = true;
	}


}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	myinit();
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;
}