#include <GL/glut.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
typedef  float Color[3];

bool rgbColorEqual(Color c1,Color c2)
{
	//补充代码，当三个通道都相等时，返回真，否则返回假；
	if(abs (c1[0] - c2[0] ) < 0.001)
        if(abs (c1[1] -c2[1] ) < 0.001)
            if(abs (c1[2] - c2[2] ) < 0.001)
                return true;
    return false;
 }

void getPixel(GLint x, GLint y, Color c)
{
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,c);
}

void setPixel (GLint x, GLint y,Color fillcolor)
   {
       glColor3f(fillcolor[0],fillcolor[1],fillcolor[2]);
      glBegin (GL_POINTS);
         glVertex2i (x, y);
      glEnd ( );
   }

void floodFill4 (int x, int y, Color fillColor, Color interiorColor)
   {
      Color curColor;
      /* Set current color to fillColor, then perform following oprations. */
      getPixel (x, y, curColor);
      if ( rgbColorEqual(interiorColor, curColor) ) {
         setPixel (x, y,fillColor);    // Set color of pixel to fillColor.
         floodFill4 (x + 1, y , fillColor, interiorColor);
         floodFill4 (x - 1, y , fillColor, interiorColor);
         floodFill4 (x , y + 1, fillColor, interiorColor);
         floodFill4 (x , y - 1, fillColor, interiorColor);
      }
   }



void init(void)
{//初始化函数，也可以不要
    glClearColor(1.0,1.0,1.0,0.0);         //背景画板白色,不透明度0
    glMatrixMode (GL_PROJECTION);       //指定投影矩阵
    gluOrtho2D (0.0, 400, 0.0, 300);   //指定显示的区域
}
void myDisplay(void)
{// 图形绘制回调函数，通常把图形绘制代码写到这个函数里面
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2i(30,30);
        glVertex2i(30, 80);
        glVertex2i(130,80);
        glVertex2i(130, 30);
    glEnd();
    Color fillColor,interiorColor;
    interiorColor[0]=0.0f,interiorColor[1]=0.0f,interiorColor[2]=0.0f;
    fillColor[0]=1.0f,fillColor[1]=0.0f,fillColor[2]=0.0f;
    floodFill4 (40, 40, fillColor, interiorColor );
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 300);
    glutCreateWindow("OpenGL基本图元绘制");
    init();
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
