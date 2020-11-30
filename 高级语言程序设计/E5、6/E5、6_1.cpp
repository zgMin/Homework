/*
	1.日期转换成天数；
	2.指定年份和第几天求出日期；
*/ 
#include<stdio.h>
int MONTH[12]={31,28,31,30,31,30,31,31,30,31,30,31};  //存储每月天数 
void dateToDays(int year,int month,int day);  //函数声明 ：日期转化为总天数 
void daysToDate(int year,int days);  //总天数转化为日期 
int main()
{
	int ctr,year,month,day,days;
	printf("输入  1.日期转换成天数  2.指定年份和第几天求出日期\n请输入：");
	scanf("%d",&ctr);
	if(ctr==1)
	{
		printf("输入日期，年月日用空格隔开：");
		scanf("%d %d %d",&year,&month,&day);
		dateToDays(year,month,day);  //函数调用 
	}
	else if(ctr==2)
	{
		printf("请输入两个数，年数和该年的第某天数：");
		scanf("%d %d",&year,&days);
		daysToDate(year,days);
	}
	else
	{
		printf("输入有误！");
	}
	return 0;
} 

void dateToDays(int year,int month,int day)//函数定义 
{
	int i,days=day;		 
	if((year%4==0&&year%100!=0)||year%400==0)//判断闰年 
	{
		 days++; 		//闰年2月加一天,数组下标从0开始
	}
	for(i=0;i<month-1;i++)
	{
		days+=MONTH[i];		//通过循环和数组计算总天数 
	} 
	printf("%d年%d月%d日是该年的第%d天",year,month,day,days);
}

void daysToDate(int year,int days)
{
	int i,month2=1,day2,t=days;
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		 MONTH[1]++; 		 
	}
	for(i=0;days-MONTH[i]>0;i++)  //每次循环将总天数减去一月差值小于0后终止循环 
	{
		days-=MONTH[i];
		month2++;		//总天数每减一月则month2加1 
	}
	day2=days;			//将最后剩余天数赋给day2 
	printf("%d年第%d天的日期是%d年%d月%d日",year,t,year,month2,day2);
}
