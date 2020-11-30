/*
	应用数组计算并保存，Fibonacci 数列的前 12 项值
*/ 
#include<stdio.h>
int F[13];
int main(){
	F[1]=1,F[2]=1;
	//计算前12项斐波那契数列并保存到数组 
	for(int i=3;i<=12;i++){
		F[i]=F[i-1]+F[i-2];
	}
	//end
	//show F
	printf("前12项Fibonacci数列：\n");
	for(int i=1;i<=12;i++){
		printf("%d ",F[i]);
	}
	//end 
	return 0;
} 
