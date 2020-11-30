#include <GL/glut.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>

 struct scrPt {
     GLint x, y;
   };



void setPixel (GLint x, GLint y)
   {
      glBegin (GL_POINTS);
         glVertex2i (x, y);
      glEnd ( );
   }



void circlePlotPoints (scrPt circCtr, scrPt circPt)
   {
      //����Բ�ĶԳ��Ի�8����
      setPixel (circCtr.x + circPt.x, circCtr.y + circPt.y);
      setPixel (circCtr.x - circPt.x, circCtr.y + circPt.y);
      setPixel (circCtr.x + circPt.x, circCtr.y - circPt.y);
      setPixel (circCtr.x - circPt.x, circCtr.y - circPt.y);
      setPixel (circCtr.x + circPt.y, circCtr.y + circPt.x);
      setPixel (circCtr.x - circPt.y, circCtr.y + circPt.x);
      setPixel (circCtr.x + circPt.y, circCtr.y - circPt.x);
      setPixel (circCtr.x - circPt.y, circCtr.y - circPt.x);
   }
void circleMidpoint (scrPt circCtr, GLint radius)
{
     //��Բ�������壬���������
     scrPt circPt;
     GLint p=1-radius;//���߱���
     circPt.x=0,circPt.y=radius;
     circlePlotPoints(circCtr,circPt);//����
     while(circPt.x<circPt.y){//��һ�����ϰ벿�֣��������Գ�
        //������һ����
        circPt.x++;
        if(p<0)//p<0��y���ֲ���
            p+=2*circPt.x+1;
        else{//p>=0,y����һ����λ
            circPt.y--;
            p+=2*(circPt.x-circPt.y)+1;
        }
        circlePlotPoints(circCtr,circPt);//����
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
    scrPt circCtr;
    circCtr.x=100,circCtr.y=100;
    GLint radius=50;
    circleMidpoint (circCtr,radius);
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
