/*
	100ƥ����100������
	������3����������2�� ��ƥС����1����
	����С�����ƥ 
*/ 
#include<stdio.h>
int main(){
	int big,mid,small;
	for(big=0;big<=33;big++){//����������� 
		for(mid=0;mid<=50-big*3;mid++){//����������� 
			if((100-big-mid)%2==0 &&big*3+mid*2+(100-big-mid)/2==100){//ʣ�µ�100-big-mid����С����� 
				printf("����%dƥ������%dƥ��С��%dƥ\n",big,mid,100-big-mid);
			}
		}
	} 
	return 0;
} 
