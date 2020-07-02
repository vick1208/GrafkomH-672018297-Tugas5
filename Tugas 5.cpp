#include <windows.h>
#include <GL/freeglut.h>

void init(void);
void disp(void);
void kb(unsigned char, int, int);
void kb2(int, int, int);
void size(int, int);

int is_depth;
void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(8.0f);
	glLineWidth(5.0f);
}
void disp() {
	if (is_depth) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	//depan 
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-10.0f, -10.0f, 10.0f);
	glVertex3f(-10.0f,10.0f,10.0f);
	glVertex3f(10.0f, 10.0f, 10.0f);
	glVertex3f(10.0f, -10.0f, 10.0f);
	glEnd();
	//jendela
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-2, 6, 10.2f);
	glVertex3f(3, 6, 10.2f);
	glVertex3f(3, 1, 10.2f);
	glVertex3f(-2, 1, 10.2f);
	glVertex3f(-4, -4, 10.2f);
	glVertex3f(-2, -4, 10.2f);
	glVertex3f(-2, -6, 10.2f);
	glVertex3f(-4, -6, 10.2f);
	glVertex3f(-6, 2, 10.2f);
	glVertex3f(-7, 2, 10.2f);
	glVertex3f(-7, 1, 10.2f);
	glVertex3f(-6, 1, 10.2f);
	glEnd();
	//pintu
	glBegin(GL_QUADS);
	glColor3f(153.0f/255.0f,76.0f/255.0f , 0.0);
	glVertex3f(9, -10, 10.2f);
	glVertex3f(9, -3, 10.2f);
	glVertex3f(6, -3, 10.2f);
	glVertex3f(6, -10, 10.2f);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-10.0f, -10.0f, -10.0f);
	glVertex3f(-10.0f, 10.0f, -10.0f);
	glVertex3f(10, 10, -10);
	glVertex3f(10, -10, -10);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(10.0f, 10.0f, 10.0f);
	glVertex3f(10.0f, -10.0f, 10.0f);
	glVertex3f(10, -10, -10);
	glVertex3f(10, 10, -10);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-10.0f, 10.0f, 10.0f);
	glVertex3f(-10.0f, -10.0f, 10.0f);
	glVertex3f(-10, -10, -10);
	glVertex3f(-10, 10, -10);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-10.0f, 10.0f , 10.0f);
	glVertex3f(10.0f, -10.0f + 20.0f, 10.0f);
	glVertex3f(10, -10.0f + 20.0f, -10);
	glVertex3f(-10, 10.0f , -10);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-10.0f, -10.0f, 10.0f);
	glVertex3f(10, -10, 10);
	glVertex3f(10, -10, -10);
	glVertex3f(-10, -10, -10);
	glEnd();
	glutSwapBuffers();
}
void kb(unsigned char k, int x, int y) {
	switch (k)
	{
	case '7':
		glTranslatef(0.0f, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0f, -3.0f, 0.0f);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case '6':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case '3':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
		break;
	case 27:
		exit(0);
		break;
	}
	disp();
}
void kb2(int k2,int x2,int y2) {
	if (k2 == GLUT_KEY_LEFT)
	{
		glTranslatef(-3.0, 0.0, 0.0);
	}
	else if (k2 == GLUT_KEY_UP) 
	{
		glTranslatef(0.0, 0.0, 3.0);
	}
		
	else if (k2==GLUT_KEY_RIGHT)
	{
		glTranslatef(3.0, 0.0, 0.0);
	}
	if (k2 == GLUT_KEY_DOWN) 
	{
		glTranslatef(0.0, 0.0, -3.0);
	}
	disp();
}
void size(int w, int h) {
	if (h == 0)
		h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, w / h, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(300, 80);
	glutCreateWindow("Vicky Alexander Susanto-672018297");
	init();
	glutDisplayFunc(disp);
	glutKeyboardFunc(kb);
	glutSpecialFunc(kb2);
	glutReshapeFunc(size);
	glutMainLoop();
	return 0;
}