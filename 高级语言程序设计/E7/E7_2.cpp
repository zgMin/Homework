/*
	Ӧ��������㲢���棬Fibonacci ���е�ǰ 12 ��ֵ
*/ 
#include<stdio.h>
int F[13];
int main(){
	F[1]=1,F[2]=1;
	//����ǰ12��쳲��������в����浽���� 
	for(int i=3;i<=12;i++){
		F[i]=F[i-1]+F[i-2];
	}
	//end
	//show F
	printf("ǰ12��Fibonacci���У�\n");
	for(int i=1;i<=12;i++){
		printf("%d ",F[i]);
	}
	//end 
	return 0;
} 
