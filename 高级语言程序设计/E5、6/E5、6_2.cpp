/*
	�û����� n ��ֵ����� n!��ֵ����ʾ������
	��ֱ�ʹ�õݹ�͵����ķ�ʽ���
*/
#include<stdio.h>
double digui(int n){//�ݹ鷽�� 
	if(n==0)
		return 1;
	return n*digui(n-1);
}
double diedai(int n){//�������� 
	double ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	int n;
	double ans1,ans2;
	scanf("%d",&n);
	ans1=digui(n);
	ans2=diedai(n);
	printf("�ݹ鷽��%d! = %.0lf\n",n,ans1);
	printf("��������%d! = %.0lf",n,ans2);
	return 0;
}
