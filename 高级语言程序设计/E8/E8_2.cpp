/*
	��дһ������ͳ��������ַ����У��������ַ�������������������
	��ʾ������ĵ�����ָǰ����ǿհ��ַ����ַ����У�
	���� adsaf asdfdsaf, <sdfsd �й��� 1 �С�23 ���ַ���3 ������
*/
#include<stdio.h>
int main(){ 
 	char c; 
	int chars=0;
	int lines=1;
	int words=0;
	bool inword=false;
	
	printf("�������ַ�($���ڽ�������):\n"); 
	
	while((c=getchar())!='$'){ 
		chars++;
		if(c=='\n') lines++; 
		if(c==' '&& !inword){ 
			inword=true; 
			words++;
		}else if(c==' '&&inword)  inword=false; 
	} 
	printf("\n�ַ���=%d,����=%d,������=%d",chars,lines,words); 
	return 0; 
}
