/*
	采用结构体数组的方法保存学生成绩，完成练习 1。
*/
#include<stdio.h>
struct Student{
	int number;
	char name[20];
	int yu,shu,ying;
	float aver;
}stu[5];
int main(){
	printf("请分别输入五个学生的信息\n");
	for(int i=0;i<5;i++){
		scanf("%d%s%d%d%d",&stu[i].number,stu[i].name,&stu[i].yu,&stu[i].shu,&stu[i].ying);
		stu[i].aver=(stu[i].yu+stu[i].shu+stu[i].ying)/3.0;
	}
	printf("学号\t姓名\t语文\t数学\t英语\t平均分\n");
	for(int i=0;i<5;i++){
		printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",stu[i].number,stu[i].name,stu[i].yu,stu[i].shu,stu[i].ying,stu[i].aver);
	}
	return 0;
} 
