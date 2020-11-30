/*
	64格麦子，第一个个数为1，之后每个是前一格的2倍
	求共多少麦子
	1立方米约1.4*10^8粒麦子 
*/
#include<stdio.h>
int main(){
	int a;
	double s=0,k=1;
	for(a=1;a<=64;a++){
		s=s+k;
		k=2*k;
	}//其实总共就是2^64-1粒 
	printf("国王需要给达依尔%f立方米小麦\n",s/1.4e8);
    return 0;
}
