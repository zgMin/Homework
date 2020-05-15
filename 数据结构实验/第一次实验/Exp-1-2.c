#include<stdio.h>
#include<stdlib.h>
int digui(int n,int k,int f[])
//递归方法求f[n] 
{
	if(f[n]!=-1) return f[n];//递归出口 
	else{					//递归体 
		int tmp=0,i;
		for(i=1;i<=k;i++){
			tmp+=digui(n-i,k,f);
		}
		f[n]=tmp;
		return f[n];
	}
}
void feidigui(int n,int k,int f[])
//非递归方法求f[n] 
{
	int i,j;
	for(i=k;i<=n;i++){//依次计算f[k].....f[n]的值 
		int tmp=0;
		for(j=1;j<=k;j++)
			tmp+=f[i-j];
		f[i]=tmp;
	}
}
int main() {
	int k,n;
	scanf("%d%d",&k,&n);
	int i,f[n+1];
	//初始化f[] 
	for(i=0;i<=n;i++){
		f[i]=-1; 
	}
	for(i=0;i<=k-2;i++){
		f[i]=0; 
	}
	f[k-1]=1;
	digui(n,k,f);
	//feidigui(n,k,f); 
	printf("%d",f[n]);
	return 0;
}
