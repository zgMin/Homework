#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b) ? a : b)
#define min(a,b) ((a)<(b) ? a : b)
#define MAXNUM 32767 
typedef struct{
	float Max,Min,Sum,Average;
}Score;			//定义结构体，用于函数返回多个值 
Score score_max_min_average(int n,float score[])
//计算n个学生的分数数组score[]的最高分，最低分和平均分 
{ 
	Score a;
	a.Min=MAXNUM;
	int i;
	for(i=0;i<n;i++){
		a.Sum+=score[i];//求和 
		a.Max=max(a.Max,score[i]);//求最高分 
		a.Min=min(a.Min,score[i]);//求最低分 
	}
	a.Average=a.Sum/n;//求平均分
	return a; 
}
int main(){
	int n;//总人数 
	scanf("%d",&n);
	float score[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%f",&score[i]); 
	Score a=score_max_min_average(n,score);
	printf("最低分%.2f 最高分%.2f 平均分%.2f",a.Min,a.Max,a.Average);
	return 0;
} 
