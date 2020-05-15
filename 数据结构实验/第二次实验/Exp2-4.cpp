#include<iostream>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<=r;i++)
#define Status bool
#define OVERFLOW -2
using namespace std;
typedef struct{
	int cnt;//最长递增子序列的头位置 
	int len;//最长递增子序列长度 
}inf;
typedef struct{
	int *data;		//存储空间基址 
	int length;		//当前长度 
	int listsize;	//当前分配容量 
} List;
Status Init(List& L,int INIT_SIZE){	//创建初始大小为INIT_SIZE的顺序表 
	L.data=(int*)malloc(INIT_SIZE*sizeof(int));
	if(!L.data) exit(OVERFLOW);
	L.length=0;
	L.listsize=INIT_SIZE;
	return true;
}
inf work(int n,int a[]){
	inf x;
	x.cnt=0,x.len=1;//答案值
	int m=0,l=1;	//当前值
	go(i,1,n-1){
		if(a[i]>a[i-1]){
			l++;
			if(x.len<l){//当前值优于答案值，更新答案
				x.cnt=m,x.len=l;
			}
		}
		else{
			l=1,m=i;
		}
	}
	return x;
} 
int main(){
	int n;
	cin>>n;
	List a;
	Init(a,n);
	go(i,0,n-1) cin>>a.data[i],a.length++;
	inf x=work(n,a.data);
	for(int i=x.cnt;i<=x.cnt+x.len-2;i++){
		cout<<a.data[i]<<" ";
	}
	cout<<a.data[x.cnt+x.len-1];
	return 0;
} 
