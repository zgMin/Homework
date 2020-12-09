#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<stdio.h>
#define PI 3.14
#define DEG_TO_RAD 0.017453  //角度转为弧度的参数，即 2*PI/360
float theta[4];
float ud[4],lr[4];
float s[4]={1.0,1.0,1.0,1.0};
int ctr=0;//0整体，1红色，2绿色，3蓝色
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (-5.0, 5.0, -5.0, 5.0);
     glClear (GL_COLOR_BUFFER_BIT);
      glMatrixMode (GL_MODELVIEW);
}

void drawDiamond(void) //绘制中心在原点的菱形
{

	glBegin (GL_POLYGON); //顶点指定需要按逆时针方向
        glVertex2f(0.0f,-1.0f);//下点
        glVertex2f(2.0f,0.0f);//右点
        glVertex2f(0.0f, 1.0f);//上点
        glVertex2f(-2.0f,0.0f);//左点
	glEnd ( );
}
void display(){
    glClear (GL_COLOR_BUFFER_BIT); //清空
	glLoadIdentity();        //将当前矩阵设为单位矩阵
	glScalef(s[0],s[0],s[0]);
	glScalef(s[1],s[1],s[1]);
    glTranslatef(lr[0],ud[0],0.0);
    glTranslatef(lr[1],ud[1],0.0);
    glRotatef(90.0+theta[0]+theta[1],0.0,0.0,1.0); //顺时针旋转90角度
    glTranslatef(2.0,0.0,0.0);
    glColor3f(1.0f,0.0f,0.0f);//红色
    drawDiamond();




    glLoadIdentity();        //将当前矩阵设为单位矩阵
    glScalef(s[0],s[0],s[0]);
    glScalef(s[2],s[2],s[2]);
    glTranslatef(lr[0],ud[0],0.0);
    glTranslatef(lr[2],ud[2],0.0);
    glRotatef(30.0+theta[0]+theta[2],0.0,0.0,1.0);
    glTranslatef(-2.0,0.0,0.0);
    glColor3f(0.0f,1.0f,0.0f);//绿色
    drawDiamond();



    glLoadIdentity();        //将当前矩阵设为单位矩阵
    glScalef(s[0],s[0],s[0]);
    glScalef(s[3],s[3],s[3]);
    glTranslatef(lr[0],ud[0],0.0);
    glTranslatef(lr[3],ud[3],0.0);
    glRotatef(-30.0+theta[0]+theta[3],0.0,0.0,1.0);
    glTranslatef(2.0,0.0,0.0);
    glColor3f(0.0f,0.0f,1.0f);//蓝色
    drawDiamond();


    glFlush();
}

void myKeyboard(unsigned char key,  int x, int y)//ad控制旋转
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
	glutPostRedisplay(); //重新调用绘制函数
}
void mySpecialKeyboard(int key,  int x, int y)//方向控制移动
{

    if(key == GLUT_KEY_UP)   ud[ctr]+=0.1;//上
    if(key == GLUT_KEY_DOWN)   ud[ctr]-=0.1;//下
    if(key == GLUT_KEY_LEFT)   lr[ctr]-=0.1;//左
    if(key == GLUT_KEY_RIGHT)   lr[ctr]+=0.1;//右
    glutPostRedisplay(); //重新调用绘制函数
}
void myMouse(int button, int state, int x, int y){//滑轮控制缩放
    if(button== 3 ){
        s[ctr] += 0.05;
    }
    if(button== 4 && s[ctr]>0.1){
        s[ctr]-=0.05;
    }
    glutPostRedisplay(); //重新调用绘制函数
}
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("几何变换函数综合示例");

    init ( );
    glutKeyboardFunc( myKeyboard);
    glutSpecialFunc(mySpecialKeyboard);
    glutMouseFunc(myMouse);
    glutDisplayFunc(display);
    glutMainLoop ( );
    return 0;
}
