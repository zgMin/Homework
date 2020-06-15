#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool cmp(char a,char b){
	return a<=b;
}
void qsort(char *L,int left,int right,bool (*cmp)(char a,char b)){//快排 
	if(left>=right) return;//递归出口
	int i=left,j=right;
	char base=L[left];
	while(i<j){
		while(cmp(base,L[j]) && i<j) j--;	//右边都是比基准值大的
		while(cmp(L[i],base) && i<j) i++;//左边都是比基准值小的
		if(i<j){
			char tmp;
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
int main(){
	char L[10000];
	int n;
	cout<<"请输入序列个数：";
	cin>>n;
	cout<<"输入序列：";
	for(int i=1;i<=n;i++){
		cin>>L[i];
	} 
	qsort(L,1,n,cmp);
	cout<<"非递减序列：";
	for(int i=1;i<=n;i++){
		cout<<L[i]<<ends;
	} 
} 
