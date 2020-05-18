#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct BiTNode {
	char data; //数据域
	struct BiTNode *lchild, *rchild; //左右孩子指针域
} BiTNode, *BiTree;
bool flag;	//判断是否是错误数据 
int cnt;		//用来遍历前序序列 
void create(char a[],char b[],BiTree root,int l,int r){//根据先序中序创建树 
	//a先序，b中序，root根节点，lr用来确定左右子树区间
	if(!flag) return;
	int pos=0;			//pos用来查找根节点在中序序列中的位置 
	root->data=a[cnt++];
	while(root->data!=b[pos]){
		pos++;
		if(pos>r){
			flag=0;
			return;
		}
	}
	if(l==r){			//没有左右子树 
		root->lchild=NULL;
        root->rchild=NULL;
        return ;
	}
	if(l<pos){//递归左孩子区间 
		BiTree l_child=(BiTree)malloc(sizeof(BiTNode)); 
		root->lchild=l_child;
		create(a,b,root->lchild,l,pos-1);
	}
	else root->lchild=NULL;
	
	if(r>pos){//递归右孩子区间 
		BiTree r_child=(BiTree)malloc(sizeof(BiTNode)); 
		root->rchild=r_child;
		create(a,b,root->rchild,pos+1,r);
	}
	else root->rchild=NULL;

	return ;
}
void travel(BiTree root,int order){//order=0先序；1中序；2后序 
	if(!root) return;
	switch(order){
		case 0:
			cout<<root->data<<" ";
			travel(root->lchild,order);
			travel(root->rchild,order);
			break;
		case 1:
			travel(root->lchild,order);
			cout<<root->data<<" ";
			travel(root->rchild,order);
			break;
		case 2:
			travel(root->lchild,order);
			travel(root->rchild,order);
			cout<<root->data<<" ";
			break;
		default:break; 
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(true){
		flag=1;
		cnt=0;
		cout<<"请分别输入先序序列与中序序列来创建二叉树："<<endl; 
		char a[20],b[20],c[20];	//a代表先序，b中序，c后序
		BiTree root;
		root=(BiTree)malloc(sizeof(BiTNode)); 
		cin>>a>>b;
		int len=strlen(b);
		create(a,b,root,0,len-1);
		if(!flag){
			cout<<"错误数据！"<<endl;
			continue; 
		}
		cout<<"以下分别是先序、中序、后序遍历序列："<<endl;
		for(int i=0;i<=2;i++){
			travel(root,i);
			cout<<endl;
		}
		
	}	
	return 0;
} 
