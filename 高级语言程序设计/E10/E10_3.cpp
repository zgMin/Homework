/*
	用二维数组保存用户输入的字符串
	当用户终止输入时，
	将所有输入中最长的字符串及其长度输出。
*/
#include<stdio.h> 
#include<string.h>
int main(){
	char s[20][100];
	printf("请输入字符串：\n");
	int cnt=0,pos,max=0;
	while(scanf("%s",s[cnt++]) != EOF){
		int len=strlen(s[cnt-1]);
		if(len>max){
			max=len,pos=cnt-1;
		}
	}
	printf("最大字符串为：%s\n",s[pos]);
	printf("长度为%d",max);
	return 0;
}
