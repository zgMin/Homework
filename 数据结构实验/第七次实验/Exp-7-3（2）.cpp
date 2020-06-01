#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define go(i,l,r) for(int i=l;i<=r;i++)
#define rgo(i,r,l) for(int i=r;r>=l;i--)
const int maxn(200000+10);
int n,m,dad[maxn];
struct edge{
	int a,b,c;//a��b�г���Ϊc�ı� 
}e[maxn];	//�ߵĽṹ 
bool cmp(edge a,edge b){
	return a.c<=b.c;
}
int find(int x){//�ȼ��� 
    while(x!=dad[x]) x=dad[x]=dad[dad[x]];
    return x;
}
void qsort(edge *L,int left,int right,bool (*cmp)(edge,edge)){//���ܷ�Ϊ�ؼ��ֵĿ��� 
	if(left>=right) return;//�ݹ����
	int i=left,j=right;
	edge base=L[left];
	while(i<j){
		while(cmp(base,L[j]) && i<j) j--;	//�ұ߶��ǱȻ�׼ֵ���
		while(cmp(L[i],base) && i<j) i++;//��߶��ǱȻ�׼ֵС��
		if(i<j){
			edge tmp;
			tmp=L[i];
			L[i]=L[j];
			L[j]=tmp;
		} 
	} 
	//������׼ֵλ�� 
	L[left]=L[i];
	L[i]=base;
	qsort(L,left,i-1,cmp);//�ݹ����
	qsort(L,i+1,right,cmp);//�ݹ��ұ� 
	return;
}
void kruskal(){
    qsort(e,1,m,cmp);//����� 
	int p=0,ans=0;			//p��¼���� ��ans��¼���� 
 	go(i,1,n) dad[i]=i;//��ʼ��dad 
	go(i,1,m){
	    int ea=find(e[i].a),eb=find(e[i].b);
		if(ea!=eb){
			ans+=e[i].c;					//��¼�� 
			dad[find(e[i].a)]=e[i].b;		//��ӵ�ͬһ�ȼ��� 
			p++;							//��¼���� 
			if(p==n-1){						//�Ƿ������С������ 
				cout<<ans;
				return;
			}
		}
	}
	cout<<-1;//����ͨ
	return; 
}
int main(){
    ios::sync_with_stdio(false);
  
    cin>>n>>m;
    go(i,1,m){
    	cin>>e[i].a>>e[i].b>>e[i].c;
    }
  
    kruskal();
    return 0;
}
