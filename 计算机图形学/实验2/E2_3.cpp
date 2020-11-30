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
      //利用圆的对称性画8个点
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
     //画圆函数主体，由你们完成
     scrPt circPt;
     GLint p=1-radius;//决策变量
     circPt.x=0,circPt.y=radius;
     circlePlotPoints(circCtr,circPt);//填充点
     while(circPt.x<circPt.y){//第一象限上半部分，其他靠对称
        //计算下一个点
        circPt.x++;
        if(p<0)//p<0，y保持不变
            p+=2*circPt.x+1;
        else{//p>=0,y下移一个单位
            circPt.y--;
            p+=2*(circPt.x-circPt.y)+1;
        }
        circlePlotPoints(circCtr,circPt);//填充点
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
    glutCreateWindow("OpenGL基本图元绘制");
    init();
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
