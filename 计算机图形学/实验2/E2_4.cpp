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
      //利用椭圆的对称性画4个点R
      setPixel (xCenter + dx, yCenter + dy);
      setPixel (xCenter - dx, yCenter + dy);
      setPixel (xCenter + dx, yCenter - dy);
      setPixel (xCenter - dx, yCenter - dy);
   }

void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry)
{
     //画椭圆函数主体，由你们完成
     int Rx_2=Rx*Rx;
     int Ry_2=Ry*Ry;
     int twoRx_2=2*Rx_2;
     int twoRy_2=2*Ry_2;
     int p;//决策参数
     int x=0,y=Ry;//填充点
     int px=0,py=twoRx_2*y;
     ellipsePlotPoints(xCenter,yCenter,x,y);
     p=round(Ry_2-(Rx_2*Ry)+0.25*Rx_2);
     while(px<=py){//斜率绝对值小于等于1，绘制上半部分
        //计算下一个点
        x++;
        px+=twoRy_2;
        if(p<0){//p<0,y保持不动
            p+=Ry_2+px;
        }else{//p>=0,y下移一个单位
            y--;
            py-=twoRx_2;
            p+=Ry_2+px-py;
        }
        ellipsePlotPoints(xCenter,yCenter,x,y);//填充点
     }
     //剩下的斜率绝对值大于1，绘制下半部分
     p=round(Ry_2*pow(x+0.5,2)+Rx_2*pow(y-1,2)-Ry_2*Rx_2);
     while(y>0){
        //计算下一个点
        y--;
        py-=twoRx_2;
        if(p>0){//p<0,x保持不动
            p+=Ry_2-py;
        }else{//p>=0,x右移一个单位
            x++;
            px+=twoRy_2;
            p+=Ry_2-py+px;
        }
        ellipsePlotPoints(xCenter,yCenter,x,y);//填充点
     }
}


void init(void)
{   //初始化函数，也可以不要
    glClearColor(1.0,1.0,1.0,0.0);         //背景画板白色,不透明度0
    glMatrixMode (GL_PROJECTION);       //指定投影矩阵
    gluOrtho2D (0.0, 400, 0.0, 300);   //指定显示的区域
}
void myDisplay(void)
{   // 图形绘制回调函数，通常把图形绘制代码写到这个函数里面
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
    glutCreateWindow("OpenGL基本图元绘制");
    init();
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
