/*
	Ŀ���Ϊ��A��Ŀ�ĸ�Ϊ B��������Ϊ��C
	���õݹ����
	�� N �麺ŵ����Ƭ�� A �ᶯ�� B �Ĳ�����ʾ������
*/
#include<stdio.h>

void move(char A,char C)
//���A��C·�� 
{
	printf("%c--->%c\n",A,C); 
}
void digui(int n,char A,char B,char C)
//�ݹ鷽����ÿ���ƶ�Ϊ��n�����Ӵӵڶ��������������ĸ����� 
{
	if(n==1) move(A,C);
	else{
		//n-1��A->B 
		digui(n-1,A,C,B);
		//��n��A->C
		move(A,C);
		//n-1��B->C
		digui(n-1,B,A,C); 
	}
}
int main(){
	int n;
	scanf("%d",&n);
	digui(n,'A','C','B');
	return 0;
} 
