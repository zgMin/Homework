/*
	���ýṹ������ķ�������ѧ���ɼ���
	�����ѧ����ÿ��ѧ���� 3 �ſεĳɼ���
	�Ӽ�������������ݣ�������ѧ�ţ����������ſγ̵ĳɼ���
	�����ƽ���ɼ���
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
	printf("��ֱ��������ѧ������Ϣ\n");  
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
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\tƽ����\n");
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",a.number,a.name,a.yu,a.shu,a.ying,a.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",b.number,b.name,b.yu,b.shu,b.ying,b.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",c.number,c.name,c.yu,c.shu,c.ying,c.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",d.number,d.name,d.yu,d.shu,d.ying,d.aver);
	printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",e.number,e.name,e.yu,e.shu,e.ying,e.aver);
	//end
	return 0;
} 
