/*
	��ӡ��10�����������
*/ 
#include<stdio.h>
int tri[11][11];
int main(){
	//������������� 
	for(int i=1;i<=10;i++)
        tri[i][1] = tri[i][i] = 1;  //ÿ���ʼ�ͽ��������־�Ϊ1 
    for(int i=3;i<=10;i++)
        for(int j=2;j<=i-1;j++)
            tri[i][j]=tri[i-1][j-1]+tri[i-1][j];  //�����ߵ����ⶼ������������֮��
    //end 
    //output
	for(int i=1;i<=10;i++){
		for(int j=1;j<=i;j++){
			printf("%-3d ",tri[i][j]);
		}
		printf("\n");//���� 
	}
	//end
	return 0;
} 
