#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include <stdio.h>

#define WHITE 0
#define RED 1
#define BLUE 2
#define GREEN 3

GLfloat fg_red = 1.0;
GLfloat fg_blue = 1.0;
GLfloat fg_green = 1.0;

void reshape(GLsizei w, GLsizei h);
void display(void);
void createMenu();
void menuSelections(int selection);

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutCreateWindow("simple");
	createMenu();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}

void reshape(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w <= h) {
		gluOrtho2D(-2.0,
		            2.0,
								-2.0 * (GLfloat) h / (GLfloat) w,
								2.0 * (GLfloat) h / (GLfloat) w);
	} else {
		gluOrtho2D(-2.0 * (GLfloat) w / (GLfloat) h,
		           2.0 * (GLfloat) w / (GLfloat) h,
							 -2.0,
							 2.0);
	}

	glViewport(0, 0, w, h);

	return;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(fg_red, fg_green, fg_blue);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	glFlush();
	return;
}

void createMenu() {
	glutCreateMenu(menuSelections);
	glutAddMenuEntry("White", WHITE);
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Green", GREEN);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menuSelections(int selection) {
	if(selection == WHITE) {
		fg_red = 1.0;
		fg_blue = 1.0;
		fg_green = 1.0;
	} else if(selection == RED) {
		fg_red = 1.0;
		fg_blue = 0.0;
		fg_green = 0.0;
	} else if(selection == BLUE) {
		fg_red = 0.0;
		fg_blue = 1.0;
		fg_green = 0.0;
	} else if(selection == GREEN) {
		fg_red = 0.0;
		fg_blue = 0.0;
		fg_green = 1.0;
	}

	glutPostRedisplay();

	return;
}
