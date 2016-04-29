#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

//This program draws a torus

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0,3.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);

	GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_LINE);
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(MyCylinder, 0.5, 0.5, 1.0, 36, 36);

	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-2.0,2.0,-2.0,2.0,4.0,7.0);


	glViewport(0,0,w,h);
	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("torus");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}
