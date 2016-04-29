#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

GLfloat rotateDirection = 1.0;

void rotate(void);
void onMouseClicked(int button, int state, int x, int y);
void display(void);

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClicked);

	glutIdleFunc(rotate);
	glutMainLoop();
}

void rotate(void) {
	glRotatef(0.02, 0.0, 0.0, rotateDirection);

	glutPostRedisplay();

	return;
}

void onMouseClicked(int button, int state, int x, int y) {
	if(state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
		rotateDirection *= -1;
	}

	return;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();

	glFlush();
	return;
}
