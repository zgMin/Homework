#include <GL/glut.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
typedef  float Color[3];

bool rgbColorEqual(Color c1,Color c2)
{
	//������룬������ͨ�������ʱ�������棬���򷵻ؼ٣�
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
{//��ʼ��������Ҳ���Բ�Ҫ
    glClearColor(1.0,1.0,1.0,0.0);         //���������ɫ,��͸����0
    glMatrixMode (GL_PROJECTION);       //ָ��ͶӰ����
    gluOrtho2D (0.0, 400, 0.0, 300);   //ָ����ʾ������
}
void myDisplay(void)
{// ͼ�λ��ƻص�������ͨ����ͼ�λ��ƴ���д�������������
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
    glutCreateWindow("OpenGL����ͼԪ����");
    init();
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
