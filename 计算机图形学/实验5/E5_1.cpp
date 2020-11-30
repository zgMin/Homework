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
    glRotatef(90,0.0,0.0,1.0); //顺时针旋转90角度
    glTranslatef(2.0,0.0,0.0);
    glColor3f(1.0f,0.0f,0.0f);//红色
    drawDiamond();


    glLoadIdentity();        //将当前矩阵设为单位矩阵
    glRotatef(30,0.0,0.0,1.0);
    glTranslatef(-2.0,0.0,0.0);
    glColor3f(0.0f,1.0f,0.0f);//绿色
    drawDiamond();

    glLoadIdentity();        //将当前矩阵设为单位矩阵
    glRotatef(-30,0.0,0.0,1.0);
    glTranslatef(2.0,0.0,0.0);
    glColor3f(0.0f,0.0f,1.0f);//蓝色
    drawDiamond();
    glFlush();
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("几何变换函数综合示例");

    init ( );
    glutDisplayFunc(display);
    glutMainLoop ( );
    return 0;
}
