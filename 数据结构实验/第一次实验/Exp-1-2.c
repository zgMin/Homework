#include<stdio.h>
#include<stdlib.h>
int digui(int n,int k,int f[])
//�ݹ鷽����f[n] 
{
	if(f[n]!=-1) return f[n];//�ݹ���� 
	else{					//�ݹ��� 
		int tmp=0,i;
		for(i=1;i<=k;i++){
			tmp+=digui(n-i,k,f);
		}
		f[n]=tmp;
		return f[n];
	}
}
void feidigui(int n,int k,int f[])
//�ǵݹ鷽����f[n] 
{
	int i,j;
	for(i=k;i<=n;i++){//���μ���f[k].....f[n]��ֵ 
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
	//��ʼ��f[] 
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
