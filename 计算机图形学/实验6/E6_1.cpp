#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<stdio.h>
#define PI 3.14
#define DEG_TO_RAD 0.017453  //�Ƕ�תΪ���ȵĲ������� 2*PI/360
float s=1.0;
int xs;int ys;
float anglex = 0.0;//X ����ת
float angley = 0.0;//Y ����ת
float anglez = 0.0;//Z ����ת
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_MODELVIEW);
    glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, 10.0);
    glClear (GL_COLOR_BUFFER_BIT);
}


void display(){
    glClear (GL_COLOR_BUFFER_BIT); //���
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(1.0f,0.0f,0.0f);//��ɫ
    glLoadIdentity();  //���ص�λ����
	glRotatef(anglex,1.0,0.0,0.0);
	glRotatef(angley,0.0,1.0,0.0);
	glRotatef(anglez,0.0,0.0,1.0);
	glutWireTeapot(0.5*s);

    glFlush();
}


void myMouse(int button, int state, int x, int y){//���ֿ�������
    if(button== 3 ){
        s += 0.05;
    }
    if(button== 4 && s>0.1){
        s-=0.05;
    }
    if(button==GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN){
            xs=x,ys=y;//��¼�����
        }
    }
    glutPostRedisplay(); //���µ��û��ƺ���
}
void myMotion(int x,int y){
    int dx=xs-x,dy=ys-y;//��¼�϶�����
    anglex  += 360 * dx / 600.0;//������Ļ����껬���ľ�����������ת�ĽǶ�
	angley += 360 * dy / 600.0;
	anglez += 360 * dy / 600.0;
    xs=x;ys=y;
    glutPostRedisplay(); //���µ��û��ƺ���
}
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("���α任�����ۺ�ʾ��");

    init ( );
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutDisplayFunc(display);
    glutMainLoop ( );
    return 0;
}
