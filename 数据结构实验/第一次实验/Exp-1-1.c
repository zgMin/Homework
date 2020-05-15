#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b) ? a : b)
#define min(a,b) ((a)<(b) ? a : b)
#define MAXNUM 32767 
typedef struct{
	float Max,Min,Sum,Average;
}Score;			//����ṹ�壬���ں������ض��ֵ 
Score score_max_min_average(int n,float score[])
//����n��ѧ���ķ�������score[]����߷֣���ͷֺ�ƽ���� 
{ 
	Score a;
	a.Min=MAXNUM;
	int i;
	for(i=0;i<n;i++){
		a.Sum+=score[i];//��� 
		a.Max=max(a.Max,score[i]);//����߷� 
		a.Min=min(a.Min,score[i]);//����ͷ� 
	}
	a.Average=a.Sum/n;//��ƽ����
	return a; 
}
int main(){
	int n;//������ 
	scanf("%d",&n);
	float score[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%f",&score[i]); 
	Score a=score_max_min_average(n,score);
	printf("��ͷ�%.2f ��߷�%.2f ƽ����%.2f",a.Min,a.Max,a.Average);
	return 0;
} 
