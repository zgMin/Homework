#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int binary_search(char L[],int left,int right,char key){//key�Ƿ���L�У��ڷ����±꣬���ڷ���-1 
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
	cout<<"���������и�����";
	cin>>n;
	cout<<"����ǵݼ����У�";
	for(int i=1;i<=n;i++){
		cin>>L[i];
	} 
	int cnt=2;//��ѯ����
	while(cnt--){
		char tmp;
		cout<<"�������ѯԪ�أ�";
		cin>>tmp;
		int pos=binary_search(L,1,n,tmp);
		if(pos!=-1)
			cout<<"�ǵ�"<<pos<<"��Ԫ��"<<endl;
		else
			cout<<"��Ԫ�ز���������"<<endl;
	} 
	return 0;
}
