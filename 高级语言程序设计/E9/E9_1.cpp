/*
	�����ѧ����ÿ��ѧ���� 3 �ſεĳɼ���
	�Ӽ�������������ݣ�������ѧ�ţ����������ſγ̵ĳɼ���
	�����ƽ���ɼ�
	����ԭ�е����ݺͼ������ƽ����������ڴ����ļ�"stud.txt"�С�
*/
#include<stdio.h>
struct Student{
	int number;
	char name[20];
	int yu,shu,ying;
	float aver;
}stu[5];
int main(){
	FILE *f = fopen("stud.txt", "w");
	printf("��ֱ��������ѧ������Ϣ\n");
	for(int i=0;i<5;i++){
		scanf("%d%s%d%d%d",&stu[i].number,stu[i].name,&stu[i].yu,&stu[i].shu,&stu[i].ying);
		stu[i].aver=(stu[i].yu+stu[i].shu+stu[i].ying)/3.0;
	}
	for(int i=0;i<5;i++){
		fprintf(f,"%d %s %d %d %d %.2f\n",stu[i].number,stu[i].name,stu[i].yu,stu[i].shu,stu[i].ying,stu[i].aver);
	}
	fclose(f); 
	return 0;
} 
