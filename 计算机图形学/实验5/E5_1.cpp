#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<stdio.h>

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (-5.0, 5.0, -5.0, 5.0);
     glClear (GL_COLOR_BUFFER_BIT);
      glMatrixMode (GL_MODELVIEW);
}

void drawDiamond(void) //����������ԭ�������
{

	glBegin (GL_POLYGON); //����ָ����Ҫ����ʱ�뷽��
        glVertex2f(0.0f,-1.0f);//�µ�
        glVertex2f(2.0f,0.0f);//�ҵ�
        glVertex2f(0.0f, 1.0f);//�ϵ�
        glVertex2f(-2.0f,0.0f);//���
	glEnd ( );
}
void display(){
    glClear (GL_COLOR_BUFFER_BIT); //���

	glLoadIdentity();        //����ǰ������Ϊ��λ����
    glRotatef(90,0.0,0.0,1.0); //˳ʱ����ת90�Ƕ�
    glTranslatef(2.0,0.0,0.0);
    glColor3f(1.0f,0.0f,0.0f);//��ɫ
    drawDiamond();


    glLoadIdentity();        //����ǰ������Ϊ��λ����
    glRotatef(30,0.0,0.0,1.0);
    glTranslatef(-2.0,0.0,0.0);
    glColor3f(0.0f,1.0f,0.0f);//��ɫ
    drawDiamond();

    glLoadIdentity();        //����ǰ������Ϊ��λ����
    glRotatef(-30,0.0,0.0,1.0);
    glTranslatef(2.0,0.0,0.0);
    glColor3f(0.0f,0.0f,1.0f);//��ɫ
    drawDiamond();
    glFlush();
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("���α任�����ۺ�ʾ��");

    init ( );
    glutDisplayFunc(display);
    glutMainLoop ( );
    return 0;
}
