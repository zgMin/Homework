/*
	�ö�ά���鱣���û�������ַ���
	���û���ֹ����ʱ��
	����������������ַ������䳤�������
*/
#include<stdio.h> 
#include<string.h>
int main(){
	char s[20][100];
	printf("�������ַ�����\n");
	int cnt=0,pos,max=0;
	while(scanf("%s",s[cnt++]) != EOF){
		int len=strlen(s[cnt-1]);
		if(len>max){
			max=len,pos=cnt-1;
		}
	}
	printf("����ַ���Ϊ��%s\n",s[pos]);
	printf("����Ϊ%d",max);
	return 0;
}
