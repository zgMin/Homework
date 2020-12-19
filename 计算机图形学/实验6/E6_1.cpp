#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<stdio.h>
#define PI 3.14
#define DEG_TO_RAD 0.017453  //角度转为弧度的参数，即 2*PI/360
float s=1.0;
int xs;int ys;
float anglex = 0.0;//X 轴旋转
float angley = 0.0;//Y 轴旋转
float anglez = 0.0;//Z 轴旋转
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_MODELVIEW);
    glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, 10.0);
    glClear (GL_COLOR_BUFFER_BIT);
}


void display(){
    glClear (GL_COLOR_BUFFER_BIT); //清空
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(1.0f,0.0f,0.0f);//红色
    glLoadIdentity();  //加载单位矩阵
	glRotatef(anglex,1.0,0.0,0.0);
	glRotatef(angley,0.0,1.0,0.0);
	glRotatef(anglez,0.0,0.0,1.0);
	glutWireTeapot(0.5*s);

    glFlush();
}


void myMouse(int button, int state, int x, int y){//滑轮控制缩放
    if(button== 3 ){
        s += 0.05;
    }
    if(button== 4 && s>0.1){
        s-=0.05;
    }
    if(button==GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN){
            xs=x,ys=y;//记录点击点
        }
    }
    glutPostRedisplay(); //重新调用绘制函数
}
void myMotion(int x,int y){
    int dx=xs-x,dy=ys-y;//记录拖动长度
    anglex  += 360 * dx / 600.0;//根据屏幕上鼠标滑动的距离来设置旋转的角度
	angley += 360 * dy / 600.0;
	anglez += 360 * dy / 600.0;
    xs=x;ys=y;
    glutPostRedisplay(); //重新调用绘制函数
}
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("几何变换函数综合示例");

    init ( );
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutDisplayFunc(display);
    glutMainLoop ( );
    return 0;
}
