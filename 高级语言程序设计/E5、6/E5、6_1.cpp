/*
	1.����ת����������
	2.ָ����ݺ͵ڼ���������ڣ�
*/ 
#include<stdio.h>
int MONTH[12]={31,28,31,30,31,30,31,31,30,31,30,31};  //�洢ÿ������ 
void dateToDays(int year,int month,int day);  //�������� ������ת��Ϊ������ 
void daysToDate(int year,int days);  //������ת��Ϊ���� 
int main()
{
	int ctr,year,month,day,days;
	printf("����  1.����ת��������  2.ָ����ݺ͵ڼ����������\n�����룺");
	scanf("%d",&ctr);
	if(ctr==1)
	{
		printf("�������ڣ��������ÿո������");
		scanf("%d %d %d",&year,&month,&day);
		dateToDays(year,month,day);  //�������� 
	}
	else if(ctr==2)
	{
		printf("�������������������͸���ĵ�ĳ������");
		scanf("%d %d",&year,&days);
		daysToDate(year,days);
	}
	else
	{
		printf("��������");
	}
	return 0;
} 

void dateToDays(int year,int month,int day)//�������� 
{
	int i,days=day;		 
	if((year%4==0&&year%100!=0)||year%400==0)//�ж����� 
	{
		 days++; 		//����2�¼�һ��,�����±��0��ʼ
	}
	for(i=0;i<month-1;i++)
	{
		days+=MONTH[i];		//ͨ��ѭ����������������� 
	} 
	printf("%d��%d��%d���Ǹ���ĵ�%d��",year,month,day,days);
}

void daysToDate(int year,int days)
{
	int i,month2=1,day2,t=days;
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		 MONTH[1]++; 		 
	}
	for(i=0;days-MONTH[i]>0;i++)  //ÿ��ѭ������������ȥһ�²�ֵС��0����ֹѭ�� 
	{
		days-=MONTH[i];
		month2++;		//������ÿ��һ����month2��1 
	}
	day2=days;			//�����ʣ����������day2 
	printf("%d���%d���������%d��%d��%d��",year,t,year,month2,day2);
}
