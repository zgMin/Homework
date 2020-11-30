/*
	将输入的十进制数字字符串转换成二进制字符串输出，
	不允许使用库函数。
*/
#include<stdio.h>
int main(){
	char s[100];
	printf("请输入一个十进制数字:\n");
	scanf("%s",s);//read char[]
	int cnt=0;
	long long shu=0;
	int bi[100];
	while(s[cnt]!='\0'){//字符串转换成数值 
		shu*=10;
		shu+=s[cnt]-'0';
		cnt++;
	}
	cnt=0;
	while(shu!=0){//十进制数转换成二进制数
 		bi[cnt++]=shu%2;
 		shu/=2; 
	} 
	printf("二进制为：\n");
	for(int i=cnt-1;i>=0;i--){//倒序输出
		printf("%d",bi[i]); 
	} 
	return 0;
} 
