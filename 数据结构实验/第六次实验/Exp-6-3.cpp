#include<iostream>
#include<cstring>
#include<cstdlib>
#define Inf 20000 
using namespace std;
typedef struct BiTNode {
	int weight; //数据域
	int lchild, rchild,parent; //指针域
} HTNode, *HTree;
typedef char* *HuffmanCode;	//编码表 

void select(HTree T,int i,int &s1,int &s2){
	//在T的1到i中选择parent=0（即根节点）且权值最小的两个节点s1和s2
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
	//w存放权值，赫夫曼树T，编码C，字符总数n
	if(n<=1) return; 
	int i;
	HTree p;
	int m=2*n-1;	//树的节点数
	T=(HTree)malloc((m+1)*sizeof(HTNode));//0号单元未使用
	for(p=T+1,i=1;i<=n;i++,p++,w++) *p={*w,0,0,0};//初始化树集
	for(;i<=m;i++,p++) *p={0,0,0,0};
	
	for(i=n+1;i<=m;i++){//建哈夫曼树 
		//选择parent=0（即根节点）且权值最小的两个节点s1和s2
		int s1,s2;
		select(T,i-1,s1,s2);
		T[s1].parent=T[s2].parent=i;
		T[i].lchild=s1;
		T[i].rchild=s2;
		T[i].weight=T[s1].weight + T[s2].weight; 
	}
	//逆向求编码 
	C=(HuffmanCode)malloc((n+1)*sizeof(char*));//分配n个字符编码的头指针
	char *cd=(char*)malloc(n*sizeof(char));	//编码的临时辅助空间 
	cd[n-1]='\0';			//结束标志
	for(i=1;i<=n;i++){		//从叶子开始求编码 
		int start=n-1;		//倒序存放从叶子求的编码 
		for(int c=i,f=T[i].parent;f!=0;c=f,f=T[f].parent){//走向根节点 
			if(T[f].lchild==c)	cd[--start]='0';
			else cd[--start]='1';
		}
		C[i]=(char*)malloc((n-start)*sizeof(char));//分配用于存放编码的空间
		strcpy(C[i],&cd[start]);			//复制到C[i]中 
	}
	free(cd);			//释放辅助空间 
	 
}



int main(){
	ios::sync_with_stdio(false);
	int n;
	cout<<"请输入权值数量："<<endl; 
	cin>>n;
	int w[n];
	cout<<"请依次输入权值："<<endl;
	for(int i=0;i<n;i++) cin>>w[i];
	HTree T;
	HuffmanCode C;
	HuffmanCoding(T,C,w,n);
	cout<<"以下是编码表："<<endl;
	for(int i=1;i<=n;i++) cout<<i<<":"<<C[i]<<endl;
	return 0;
} 
