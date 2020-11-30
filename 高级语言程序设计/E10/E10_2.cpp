/*
	请使用指针存取方式完成练习 1
*/
#include<stdio.h> 
#include<string.h>
void nizhuan(char *p,int len){
	for(int i=0;i<len/2;i++){//位置逆转 
		char tmp=*(p+i);
		*(p+i)=*(p+len-i-1);
		*(p+len-i-1)=tmp; 
	} 
}
int main(){
	char s[100];
	char *p=s; 
	printf("请输入一个字符串：\n");
	scanf("%s",s);
	int len=strlen(s);//字符串长度
	nizhuan(s,len);
	//show s
	printf("逆转结果：\n%s",s);
	//end 
	return 0;
}
