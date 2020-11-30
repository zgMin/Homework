#include <GL/glut.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
long start,finish;


//inline int round (const float a)  { return int (a + 0.5); }
void setPixel(GLint x,  GLint y){

    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}
void lineDDA (int x0, int y0, int xEnd, int yEnd){
      int dx = xEnd - x0,  dy = yEnd - y0,  steps,  k;
      float xIncrement, yIncrement, x = x0, y = y0;

      if (fabs (dx) > fabs (dy))
         steps = fabs (dx);
      else
         steps = fabs (dy);
      xIncrement = float (dx) / float (steps);
      yIncrement = float (dy) / float (steps);

      setPixel(round (x), round (y));
      for (k = 0; k < steps; k++) {
         x += xIncrement;
         y += yIncrement;
         setPixel (round (x), round (y));
      }
 }


void init(void)
{//初始化函数，也可以不要
    glClearColor(1.0,1.0,1.0,0.0);         //背景画板白色,不透明度0
    glMatrixMode (GL_PROJECTION);       //指定投影矩阵
    gluOrtho2D (0.0, 300, 0.0, 300);   //指定显示的区域
}
void myDisplay(void)
{// 图形绘制回调函数，通常把图形绘制代码写到这个函数里面
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    int x0=5, y0=5, x1=170, y1=250;
    lineDDA(x0, y0, x1, y1);
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL基本图元绘制");
    init();
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
