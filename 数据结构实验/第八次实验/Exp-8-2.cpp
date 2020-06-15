#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int binary_search(char L[],int left,int right,char key){//key是否在L中，在返回下标，不在返回-1 
	while(left<=right){
		int mid=(left+right)>>1;
		if(key==L[mid])
			return mid;
		else if(key>L[mid])
			left=mid+1;
		else if(key<L[mid])
			right=mid-1;
	}
	return -1;
}
int main(){
	char L[10000];
	int n;
	cout<<"请输入序列个数：";
	cin>>n;
	cout<<"输入非递减序列：";
	for(int i=1;i<=n;i++){
		cin>>L[i];
	} 
	int cnt=2;//查询次数
	while(cnt--){
		char tmp;
		cout<<"请输入查询元素：";
		cin>>tmp;
		int pos=binary_search(L,1,n,tmp);
		if(pos!=-1)
			cout<<"是第"<<pos<<"个元素"<<endl;
		else
			cout<<"该元素不在序列中"<<endl;
	} 
	return 0;
}
