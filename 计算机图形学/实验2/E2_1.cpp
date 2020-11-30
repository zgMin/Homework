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
{//��ʼ��������Ҳ���Բ�Ҫ
    glClearColor(1.0,1.0,1.0,0.0);         //���������ɫ,��͸����0
    glMatrixMode (GL_PROJECTION);       //ָ��ͶӰ����
    gluOrtho2D (0.0, 300, 0.0, 300);   //ָ����ʾ������
}
void myDisplay(void)
{// ͼ�λ��ƻص�������ͨ����ͼ�λ��ƴ���д�������������
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
    glutCreateWindow("OpenGL����ͼԪ����");
    init();
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
