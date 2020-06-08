#include<iostream>
#include<cstdlib>
#include<cstdio> 
using namespace std;
int fa[100],ra[100];//fa�ȼ����ţ�ra�� 
int father(int x){		//���ҵȼ����� 
	if(x==fa[x]) return x;
	if(x!=fa[x]){
		fa[x]=father(fa[x]);		//·��ѹ�� 
	}
	return fa[x];
}
//ͬһ��ͨ������ӵ�ͬһ�ȼ����� 
void Union(int x,int y){
	int r1=father(x);
	int r2=father(y);
	if(ra[r1]<ra[r2]){			//�����Ż� 
		fa[r2]=r1;
	}
	else{
		if(ra[r1]==ra[r2]) ra[r2]++;
		fa[r1]=r2;
	}
} 
int main(){
	ios::sync_with_stdio(false);
	int n,e;
	cin>>n>>e;
	int a,b;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		Union(a,b);
	}//���벢����ȼ���
	//ѯ�� 
	cin>>a>>b;
	if(fa[a]==fa[b])
		printf("There is a path between %d and %d.",a,b); 
	else
		printf("There is no path between %d and %d.",a,b); 
	return 0; 
}
