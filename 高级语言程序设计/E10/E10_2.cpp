/*
	��ʹ��ָ���ȡ��ʽ�����ϰ 1
*/
#include<stdio.h> 
#include<string.h>
void nizhuan(char *p,int len){
	for(int i=0;i<len/2;i++){//λ����ת 
		char tmp=*(p+i);
		*(p+i)=*(p+len-i-1);
		*(p+len-i-1)=tmp; 
	} 
}
int main(){
	char s[100];
	char *p=s; 
	printf("������һ���ַ�����\n");
	scanf("%s",s);
	int len=strlen(s);//�ַ�������
	nizhuan(s,len);
	//show s
	printf("��ת�����\n%s",s);
	//end 
	return 0;
}
