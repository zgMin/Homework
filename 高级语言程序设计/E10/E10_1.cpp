/*
	请使用数组元素存取方式
	设计实现一个函数可以将任意字符数组元素存放位置逆转的程序。
*/
#include<stdio.h>
#include<string.h> 
void nizhuan(char s[]){
	int len=strlen(s);//字符串长度 
	for(int i=0;i<len/2;i++){//位置逆转 
		char tmp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=tmp; 
	} 
} 
int main(){
	char s[100];
	printf("请输入一个字符串：\n");
	scanf("%s",s);
	nizhuan(s);
	//show s
	printf("逆转结果：\n%s",s);
	//end
	return 0;
}
