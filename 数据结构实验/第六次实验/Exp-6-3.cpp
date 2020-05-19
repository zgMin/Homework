#include<iostream>
#include<cstring>
#include<cstdlib>
#define Inf 20000 
using namespace std;
typedef struct BiTNode {
	int weight; //������
	int lchild, rchild,parent; //ָ����
} HTNode, *HTree;
typedef char* *HuffmanCode;	//����� 

void select(HTree T,int i,int &s1,int &s2){
	//��T��1��i��ѡ��parent=0�������ڵ㣩��Ȩֵ��С�������ڵ�s1��s2
	int Min=Inf,sMin=Inf;
	for(int j=1;j<=i;j++){
		if(T[j].parent==0){
			if(T[j].weight<Min){
				int tmp=Min;
				int s=s1;
				Min=T[j].weight;
				sMin=tmp;
				s1=j;
				s2=s;
			}
			else{
				if(T[j].weight<sMin){
					sMin=T[j].weight;
					s2=j;
				}
			}
		}
	}
}

void HuffmanCoding(HTree &T,HuffmanCode &C,int *w,int n){
	//w���Ȩֵ���շ�����T������C���ַ�����n
	if(n<=1) return; 
	int i;
	HTree p;
	int m=2*n-1;	//���Ľڵ���
	T=(HTree)malloc((m+1)*sizeof(HTNode));//0�ŵ�Ԫδʹ��
	for(p=T+1,i=1;i<=n;i++,p++,w++) *p={*w,0,0,0};//��ʼ������
	for(;i<=m;i++,p++) *p={0,0,0,0};
	
	for(i=n+1;i<=m;i++){//���������� 
		//ѡ��parent=0�������ڵ㣩��Ȩֵ��С�������ڵ�s1��s2
		int s1,s2;
		select(T,i-1,s1,s2);
		T[s1].parent=T[s2].parent=i;
		T[i].lchild=s1;
		T[i].rchild=s2;
		T[i].weight=T[s1].weight + T[s2].weight; 
	}
	//��������� 
	C=(HuffmanCode)malloc((n+1)*sizeof(char*));//����n���ַ������ͷָ��
	char *cd=(char*)malloc(n*sizeof(char));	//�������ʱ�����ռ� 
	cd[n-1]='\0';			//������־
	for(i=1;i<=n;i++){		//��Ҷ�ӿ�ʼ����� 
		int start=n-1;		//�����Ŵ�Ҷ����ı��� 
		for(int c=i,f=T[i].parent;f!=0;c=f,f=T[f].parent){//������ڵ� 
			if(T[f].lchild==c)	cd[--start]='0';
			else cd[--start]='1';
		}
		C[i]=(char*)malloc((n-start)*sizeof(char));//�������ڴ�ű���Ŀռ�
		strcpy(C[i],&cd[start]);			//���Ƶ�C[i]�� 
	}
	free(cd);			//�ͷŸ����ռ� 
	 
}



int main(){
	ios::sync_with_stdio(false);
	int n;
	cout<<"������Ȩֵ������"<<endl; 
	cin>>n;
	int w[n];
	cout<<"����������Ȩֵ��"<<endl;
	for(int i=0;i<n;i++) cin>>w[i];
	HTree T;
	HuffmanCode C;
	HuffmanCoding(T,C,w,n);
	cout<<"�����Ǳ����"<<endl;
	for(int i=1;i<=n;i++) cout<<i<<":"<<C[i]<<endl;
	return 0;
} 
