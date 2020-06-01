#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define go(i,l,r) for(int i=l;i<=r;i++)
#define rgo(i,r,l) for(int i=r;r>=l;i--)
const int maxn(200000+10);
int n,m,dad[maxn];
struct edge{
	int a,b,c;//a到b有长度为c的边 
}e[maxn];	//边的结构 
bool cmp(edge a,edge b){
	return a.c<=b.c;
}
int find(int x){//等价类 
    while(x!=dad[x]) x=dad[x]=dad[dad[x]];
    return x;
}
void qsort(edge *L,int left,int right,bool (*cmp)(edge,edge)){//以总分为关键字的快排 
	if(left>=right) return;//递归出口
	int i=left,j=right;
	edge base=L[left];
	while(i<j){
		while(cmp(base,L[j]) && i<j) j--;	//右边都是比基准值大的
		while(cmp(L[i],base) && i<j) i++;//左边都是比基准值小的
		if(i<j){
			edge tmp;
			tmp=L[i];
			L[i]=L[j];
			L[j]=tmp;
		} 
	} 
	//调整基准值位置 
	L[left]=L[i];
	L[i]=base;
	qsort(L,left,i-1,cmp);//递归左边
	qsort(L,i+1,right,cmp);//递归右边 
	return;
}
void kruskal(){
    qsort(e,1,m,cmp);//排序边 
	int p=0,ans=0;			//p记录边数 ，ans记录花费 
 	go(i,1,n) dad[i]=i;//初始化dad 
	go(i,1,m){
	    int ea=find(e[i].a),eb=find(e[i].b);
		if(ea!=eb){
			ans+=e[i].c;					//记录答案 
			dad[find(e[i].a)]=e[i].b;		//添加到同一等价类 
			p++;							//记录边数 
			if(p==n-1){						//是否完成最小生成树 
				cout<<ans;
				return;
			}
		}
	}
	cout<<-1;//不连通
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
