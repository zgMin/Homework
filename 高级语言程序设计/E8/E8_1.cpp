/*
	�������ʮ���������ַ���ת���ɶ������ַ��������
	������ʹ�ÿ⺯����
*/
#include<stdio.h>
int main(){
	char s[100];
	printf("������һ��ʮ��������:\n");
	scanf("%s",s);//read char[]
	int cnt=0;
	long long shu=0;
	int bi[100];
	while(s[cnt]!='\0'){//�ַ���ת������ֵ 
		shu*=10;
		shu+=s[cnt]-'0';
		cnt++;
	}
	cnt=0;
	while(shu!=0){//ʮ������ת���ɶ�������
 		bi[cnt++]=shu%2;
 		shu/=2; 
	} 
	printf("������Ϊ��\n");
	for(int i=cnt-1;i>=0;i--){//�������
		printf("%d",bi[i]); 
	} 
	return 0;
} 
