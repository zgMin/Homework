#include<iostream>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<=r;i++)
#define Status bool
#define OVERFLOW -2
using namespace std;
typedef struct{
	int cnt;//����������е�ͷλ�� 
	int len;//����������г��� 
}inf;
typedef struct{
	int *data;		//�洢�ռ��ַ 
	int length;		//��ǰ���� 
	int listsize;	//��ǰ�������� 
} List;
Status Init(List& L,int INIT_SIZE){	//������ʼ��СΪINIT_SIZE��˳��� 
	L.data=(int*)malloc(INIT_SIZE*sizeof(int));
	if(!L.data) exit(OVERFLOW);
	L.length=0;
	L.listsize=INIT_SIZE;
	return true;
}
inf work(int n,int a[]){
	inf x;
	x.cnt=0,x.len=1;//��ֵ
	int m=0,l=1;	//��ǰֵ
	go(i,1,n-1){
		if(a[i]>a[i-1]){
			l++;
			if(x.len<l){//��ǰֵ���ڴ�ֵ�����´�
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
