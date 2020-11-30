//输入三个数字，输出最大者和最小者 
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int max,min;
	if(a<b){
		max=b,min=a;
		if(b<c){
			max=c;
		}else if(a>c){
			min=c;
		}
	}else{
		max=a,min=b;
		if(a<c){
			max=c;
		}else if(b>c){
			min=c;
		}
	}
	printf("最大者：%d    最小者：%d\n",max,min);
	return 0;
} 
