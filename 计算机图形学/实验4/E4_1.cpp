#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#define DEG_TO_RAD 0.017453  //�Ƕ�תΪ���ȵĲ������� 2*PI/360

float width=300.0; //��
float length=200.0;  //��
float xx=300.0, yy=200.0; //��

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 600.0, 0.0, 600.0);
}

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
        glVertex2f (xx, yy);
        glVertex2f (xx+length, yy);
        glVertex2f (xx+length, yy+width);
        glVertex2f (xx, yy+width);
    glEnd ( );
    glFlush ( );
}

void myKeyboard(unsigned char key,  int x, int y)
{
	if(key == 'a' || key == 'A')
		xx -= 10.0;
	if(key == 's' || key == 'S')
		yy -= 10.0;
    if(key == 'w' || key == 'W')
		yy+=10.0;
    if(key == 'd' || key == 'D')
		xx+=10.0;
    if(key == 'c' || key == 'C')
		exit(0);
	glutPostRedisplay(); //���µ��û��ƺ���
}
void mySpecialKeyboard(int key,  int x, int y)
{

    if(key == GLUT_KEY_UP)   yy+=10.0;//��
    if(key == GLUT_KEY_DOWN)   yy-=10.0;//��
    if(key == GLUT_KEY_LEFT)   xx-=10.0;//��
    if(key == GLUT_KEY_RIGHT)   xx+=10.0;//��
    glutPostRedisplay(); //���µ��û��ƺ���
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("�ƶ�����");

    init ( );
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(mySpecialKeyboard);
    glutMainLoop ( );
    return 0;
}
