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
	if(t[i]==0){//i�ڵ㲻���� 
		cout<<"ERROR: T["<<i<<"] is NULL";
		return 0;
	}
	else
		if(t[j]==0){//j�ڵ㲻���� 
			cout<<"ERROR: T["<<j<<"] is NULL";
			return 0;
		}
	while(j!=0){//j����ڵ��ߣ���;���ϱ�� 
		flag[j]=1;
		j=j/2;	//ָ�򸸽ڵ� 
	} 
	while(i!=0){//i����ڵ��ߣ���lca 
		if(flag[i]){//�ҵ�lca 
			cout<<i<<" "<<t[i];
			return 0; 
		} 
		i=i/2;//ָ�򸸽ڵ� 
	}
	return 0;
}
