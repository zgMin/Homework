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



void ellipsePlotPoints (int xCenter, int yCenter, int dx, int dy)
   {
      //������Բ�ĶԳ��Ի�4����R
      setPixel (xCenter + dx, yCenter + dy);
      setPixel (xCenter - dx, yCenter + dy);
      setPixel (xCenter + dx, yCenter - dy);
      setPixel (xCenter - dx, yCenter - dy);
   }

void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry)
{
     //����Բ�������壬���������
     int Rx_2=Rx*Rx;
     int Ry_2=Ry*Ry;
     int twoRx_2=2*Rx_2;
     int twoRy_2=2*Ry_2;
     int p;//���߲���
     int x=0,y=Ry;//����
     int px=0,py=twoRx_2*y;
     ellipsePlotPoints(xCenter,yCenter,x,y);
     p=round(Ry_2-(Rx_2*Ry)+0.25*Rx_2);
     while(px<=py){//б�ʾ���ֵС�ڵ���1�������ϰ벿��
        //������һ����
        x++;
        px+=twoRy_2;
        if(p<0){//p<0,y���ֲ���
            p+=Ry_2+px;
        }else{//p>=0,y����һ����λ
            y--;
            py-=twoRx_2;
            p+=Ry_2+px-py;
        }
        ellipsePlotPoints(xCenter,yCenter,x,y);//����
     }
     //ʣ�µ�б�ʾ���ֵ����1�������°벿��
     p=round(Ry_2*pow(x+0.5,2)+Rx_2*pow(y-1,2)-Ry_2*Rx_2);
     while(y>0){
        //������һ����
        y--;
        py-=twoRx_2;
        if(p>0){//p<0,x���ֲ���
            p+=Ry_2-py;
        }else{//p>=0,x����һ����λ
            x++;
            px+=twoRy_2;
            p+=Ry_2-py+px;
        }
        ellipsePlotPoints(xCenter,yCenter,x,y);//����
     }
}


void init(void)
{   //��ʼ��������Ҳ���Բ�Ҫ
    glClearColor(1.0,1.0,1.0,0.0);         //���������ɫ,��͸����0
    glMatrixMode (GL_PROJECTION);       //ָ��ͶӰ����
    gluOrtho2D (0.0, 400, 0.0, 300);   //ָ����ʾ������
}
void myDisplay(void)
{   // ͼ�λ��ƻص�������ͨ����ͼ�λ��ƴ���д�������������
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    int xCenter=200,yCenter=200,Rx=100,Ry=30;
    ellipseMidpoint (xCenter, yCenter, Rx, Ry);
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
