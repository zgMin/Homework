#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<stdio.h>
#define PI 3.14
#define DEG_TO_RAD 0.017453  //�Ƕ�תΪ���ȵĲ������� 2*PI/360
float theta[4];
float ud[4],lr[4];
float s[4]={1.0,1.0,1.0,1.0};
int ctr=0;//0���壬1��ɫ��2��ɫ��3��ɫ
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
	glScalef(s[0],s[0],s[0]);
	glScalef(s[1],s[1],s[1]);
    glTranslatef(lr[0],ud[0],0.0);
    glTranslatef(lr[1],ud[1],0.0);
    glRotatef(90.0+theta[0]+theta[1],0.0,0.0,1.0); //˳ʱ����ת90�Ƕ�
    glTranslatef(2.0,0.0,0.0);
    glColor3f(1.0f,0.0f,0.0f);//��ɫ
    drawDiamond();




    glLoadIdentity();        //����ǰ������Ϊ��λ����
    glScalef(s[0],s[0],s[0]);
    glScalef(s[2],s[2],s[2]);
    glTranslatef(lr[0],ud[0],0.0);
    glTranslatef(lr[2],ud[2],0.0);
    glRotatef(30.0+theta[0]+theta[2],0.0,0.0,1.0);
    glTranslatef(-2.0,0.0,0.0);
    glColor3f(0.0f,1.0f,0.0f);//��ɫ
    drawDiamond();



    glLoadIdentity();        //����ǰ������Ϊ��λ����
    glScalef(s[0],s[0],s[0]);
    glScalef(s[3],s[3],s[3]);
    glTranslatef(lr[0],ud[0],0.0);
    glTranslatef(lr[3],ud[3],0.0);
    glRotatef(-30.0+theta[0]+theta[3],0.0,0.0,1.0);
    glTranslatef(2.0,0.0,0.0);
    glColor3f(0.0f,0.0f,1.0f);//��ɫ
    drawDiamond();


    glFlush();
}

void myKeyboard(unsigned char key,  int x, int y)//ad������ת
{
	if(key>='0'&& key<='3') ctr=key-'0';
	if(key == 'a' || key == 'A')
		theta[ctr] += 5.0;
	if(key == 'd' || key == 'D')
		theta[ctr] -= 5.0;
    if(key == 'c' || key == 'C')
		exit(0);
	if (theta[ctr]>360) theta[ctr] -=360;
	if (theta[ctr]<0) theta[ctr] +=360;
	glutPostRedisplay(); //���µ��û��ƺ���
}
void mySpecialKeyboard(int key,  int x, int y)//��������ƶ�
{

    if(key == GLUT_KEY_UP)   ud[ctr]+=0.1;//��
    if(key == GLUT_KEY_DOWN)   ud[ctr]-=0.1;//��
    if(key == GLUT_KEY_LEFT)   lr[ctr]-=0.1;//��
    if(key == GLUT_KEY_RIGHT)   lr[ctr]+=0.1;//��
    glutPostRedisplay(); //���µ��û��ƺ���
}
void myMouse(int button, int state, int x, int y){//���ֿ�������
    if(button== 3 ){
        s[ctr] += 0.05;
    }
    if(button== 4 && s[ctr]>0.1){
        s[ctr]-=0.05;
    }
    glutPostRedisplay(); //���µ��û��ƺ���
}
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("���α任�����ۺ�ʾ��");

    init ( );
    glutKeyboardFunc( myKeyboard);
    glutSpecialFunc(mySpecialKeyboard);
    glutMouseFunc(myMouse);
    glutDisplayFunc(display);
    glutMainLoop ( );
    return 0;
}
