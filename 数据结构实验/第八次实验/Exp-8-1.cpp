#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool cmp(char a,char b){
	return a<=b;
}
void qsort(char *L,int left,int right,bool (*cmp)(char a,char b)){//���� 
	if(left>=right) return;//�ݹ����
	int i=left,j=right;
	char base=L[left];
	while(i<j){
		while(cmp(base,L[j]) && i<j) j--;	//�ұ߶��ǱȻ�׼ֵ���
		while(cmp(L[i],base) && i<j) i++;//��߶��ǱȻ�׼ֵС��
		if(i<j){
			char tmp;
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
int main(){
	char L[10000];
	int n;
	cout<<"���������и�����";
	cin>>n;
	cout<<"�������У�";
	for(int i=1;i<=n;i++){
		cin>>L[i];
	} 
	qsort(L,1,n,cmp);
	cout<<"�ǵݼ����У�";
	for(int i=1;i<=n;i++){
		cout<<L[i]<<ends;
	} 
} 
