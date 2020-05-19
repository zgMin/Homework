#include<iostream>
#include<cstring>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int flag[1000+1];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int t[n+1];
	int i,j;
	go(k,1,n) cin>>t[k];
	cin>>i>>j;
	if(t[i]==0){//i节点不存在 
		cout<<"ERROR: T["<<i<<"] is NULL";
		return 0;
	}
	else
		if(t[j]==0){//j节点不存在 
			cout<<"ERROR: T["<<j<<"] is NULL";
			return 0;
		}
	while(j!=0){//j向根节点走，沿途打上标记 
		flag[j]=1;
		j=j/2;	//指向父节点 
	} 
	while(i!=0){//i向根节点走，找lca 
		if(flag[i]){//找到lca 
			cout<<i<<" "<<t[i];
			return 0; 
		} 
		i=i/2;//指向父节点 
	}
	return 0;
}
