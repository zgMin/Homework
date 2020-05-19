#include<iostream>
#include<cstdio>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<=r;i++)
#define Inf 2147483647
using namespace std;
int flag[20000+1];
void select(int T[],int n,int &s1,int &s2){
	//在T中选择flag=0且权值最小的两个节点s1和s2
	int Min=Inf,sMin=Inf;
	for(int j=1;j<=n;j++){
		if(flag[j]==0){
			if(T[j]<Min){
				int tmp=Min;
				int s=s1;
				Min=T[j];
				sMin=tmp;
				s1=j;
				s2=s;
			}
			else{
				if(T[j]<sMin){
					sMin=T[j];
					s2=j;
				}
			}
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
	int n,ans=0;
	cin>>n;
	int t[2*n];
	go(i,1,n) cin>>t[i];
	go(i,n+1,2*n-1){
		int s1,s2;
		select(t,i-1,s1,s2);
		t[i]=t[s1]+t[s2];
		flag[s1]=1;
		flag[s2]=1;
		ans+=t[i];
	}
	cout<<ans;
    return 0;
}
