/*
	采用结构体变量的方法保存学生成绩，
	有五个学生，每个学生有 3 门课的成绩，
	从键盘输入相关数据（包括：学号，姓名和三门课程的成绩）
	计算出平均成绩。
*/
#include<stdio.h>
struct Student{
	int number;
	char name[20];
	int yu,shu,ying;
	float aver;
};
int main(){
	Student a,b,c,d,e;
	printf("请分别输入五个学生的信息\n");  
	scanf("%d%s%d%d%d",&a.number,a.name,&a.yu,&a.shu,&a.ying);
	a.aver=(a.yu+a.shu+a.ying)/3.0;
	scanf("%d%s%d%d%d",&b.number,b.name,&b.yu,&b.shu,&b.ying);
	b.aver=(b.yu+b.shu+b.ying)/3.0;
	scanf("%d%s%d%d%d",&c.number,c.name,&c.yu,&c.shu,&c.ying);
	c.aver=(c.yu+c.shu+c.ying)/3.0;
	scanf("%d%s%d%d%d",&d.number,d.name,&d.yu,&d.shu,&d.ying);
	d.aver=(d.yu+d.shu+d.ying)/3.0;
	scanf("%d%s%d%d%d",&e.number,e.name,&e.yu,&e.shu,&e.ying);
	e.aver=(e.yu+e.shu+e.ying)/3.0;
	//show
	printf("学号\t姓名\t语文\t数学\t英语\t平均分\n");
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",a.number,a.name,a.yu,a.shu,a.ying,a.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",b.number,b.name,b.yu,b.shu,b.ying,b.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",c.number,c.name,c.yu,c.shu,c.ying,c.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",d.number,d.name,d.yu,d.shu,d.ying,d.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",e.number,e.name,e.yu,e.shu,e.ying,e.aver);
	//end
	return 0;
} 
