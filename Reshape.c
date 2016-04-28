#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include <stdio.h>

void reshape(GLsizei w, GLsizei h);
void display(void);

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutCreateWindow("simple");

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

	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	glFlush();
	return;
}
