/*
	ͳ�ƶ���������ַ������ȣ�
	����ͳ�ƽ��������ʽ�г���
	��ˮƽ��״ͼ����ʽ��ʾ������
*/
#include<stdio.h>
#include<string.h>
int	biao[100];
int main(){
	char s[100];
	int Lmax=0;
	while(scanf("%s", s) != EOF){
		int L=strlen(s);
		Lmax=Lmax<L?L:Lmax;
		biao[L]++;
	}
	printf("length\tNumber\tGraphic\n������������������������\n");
	for(int i=1;i<=Lmax;i++){
		if(biao[i]){
			printf("%d\t%d\t",i,biao[i]);
			for(int j=1;j<=biao[i];j++){
				printf("��");
			}
			printf("\n");
		}
	}
	return 0;
} 
