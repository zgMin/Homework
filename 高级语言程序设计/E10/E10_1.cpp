/*
	��ʹ������Ԫ�ش�ȡ��ʽ
	���ʵ��һ���������Խ������ַ�����Ԫ�ش��λ����ת�ĳ���
*/
#include<stdio.h>
#include<string.h> 
void nizhuan(char s[]){
	int len=strlen(s);//�ַ������� 
	for(int i=0;i<len/2;i++){//λ����ת 
		char tmp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=tmp; 
	} 
} 
int main(){
	char s[100];
	printf("������һ���ַ�����\n");
	scanf("%s",s);
	nizhuan(s);
	//show s
	printf("��ת�����\n%s",s);
	//end
	return 0;
}
