#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<stdio.h>

float width=300.0; //��
float length=200.0;  //��
int xx[2], yy[2]; //��
int cnt=0;
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 600.0, 0.0, 600.0);
    glClear (GL_COLOR_BUFFER_BIT);
}

void display (void)
{
    //glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
   if(cnt==2){
        glBegin (GL_LINES);
            glVertex2f (xx[0], yy[0]);
            glVertex2f (xx[1], yy[1]);
        glEnd ( );
        cnt=0;
    }else{
        glBegin(GL_POINT);
        glEnd();
    }
    glFlush();
}
void myMouse(int button, int state, int x, int y)
{
   //����������
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        xx[cnt]=x,yy[cnt]=600-y;
        cnt++;

	}
	//��������Ҽ�
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){

        glClearColor (1.0, 1.0, 1.0, 0.0);
        glClear (GL_COLOR_BUFFER_BIT);
        cnt=0;
       // glFlush ( );
	}
  glutPostRedisplay(); //���µ��û��ƺ���
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("����");

    init ( );
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutMainLoop ( );
    return 0;
}
