/*
	���ýṹ������ķ�������ѧ���ɼ��������ϰ 1��
*/
#include<stdio.h>
struct Student{
	int number;
	char name[20];
	int yu,shu,ying;
	float aver;
}stu[5];
int main(){
	printf("��ֱ��������ѧ������Ϣ\n");
	for(int i=0;i<5;i++){
		scanf("%d%s%d%d%d",&stu[i].number,stu[i].name,&stu[i].yu,&stu[i].shu,&stu[i].ying);
		stu[i].aver=(stu[i].yu+stu[i].shu+stu[i].ying)/3.0;
	}
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\tƽ����\n");
	for(int i=0;i<5;i++){
		printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",stu[i].number,stu[i].name,stu[i].yu,stu[i].shu,stu[i].ying,stu[i].aver);
	}
	return 0;
} 
