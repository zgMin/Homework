/*
	有五个学生，每个学生有 3 门课的成绩，
	从键盘输入相关数据（包括：学号，姓名和三门课程的成绩）
	计算出平均成绩
	并将原有的数据和计算出的平均分数存放在磁盘文件"stud.txt"中。
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
	printf("请分别输入五个学生的信息\n");
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
