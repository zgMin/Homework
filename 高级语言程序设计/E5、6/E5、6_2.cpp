/*
	用户给定 n 的值计算出 n!的值，显示出来。
	请分别使用递归和迭代的方式完成
*/
#include<stdio.h>
double digui(int n){//递归方法 
	if(n==0)
		return 1;
	return n*digui(n-1);
}
double diedai(int n){//迭代方法 
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
	printf("递归方法%d! = %.0lf\n",n,ans1);
	printf("迭代方法%d! = %.0lf",n,ans2);
	return 0;
}
