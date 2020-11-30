#include <GL/glut.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>


//inline int round (const float a)  { return int (a + 0.5); }
void setPixel(GLint x,  GLint y){

    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}
void lineBres (int x0, int y0, int xEnd, int yEnd){
      int dx = xEnd - x0,  dy = yEnd - y0;
      int fu=0;
      if(dx<0){
            dx=x0-xEnd;
            fu=(fu+1)%2;
         }
        if(dy<0){
            dy=y0-yEnd;
            fu=(fu+1)%2;
         }
      if(dy<=dx){//斜率绝对值小于等于1时
        int twoDy=2*dy,twoDyMinusDx=2*(dy-dx);
        int p=twoDy-dx;
        int x,y;

        if (x0 > xEnd){//让起始点变为x小的一端
            x=xEnd;
            y=yEnd;
            xEnd=x0;
        }
        else{
            x=x0,y=y0;
        }

        setPixel(x,y);//填充点
        while(x<xEnd){
            //计算下一个点
            x++;
            if(p<0){//p<0，y保持不变
                p+=twoDy;
            }
            else{//p>=0，y移动一个单位
                if(fu){
                    y--;
                }
                else{
                    y++;

                }
                p+=twoDyMinusDx;
            }
            setPixel(x,y);//填充点
        }
      }
      if(dy>dx){//斜率绝对值大于1时
        int twoDx=2*dx,twoDxMinusDy=2*(dx-dy);
        int p=twoDx-dy;
        int x,y;

        if (y0 > yEnd){
            x=xEnd;
            y=yEnd;
            yEnd=y0;
        }
        else{
            x=x0,y=y0;
        }
        setPixel(x,y);
        while(y<yEnd){
            y++;
            if(p<0){
                p+=twoDx;
            }
            else{
                if(fu){
                    x--;
                }
                else{
                    x++;
                }
                p+=twoDxMinusDy;
            }
            setPixel(x,y);
        }
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
    int x0=400, y0=200, x1=100, y1=80;
    lineBres(x0, y0, x1, y1);
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
