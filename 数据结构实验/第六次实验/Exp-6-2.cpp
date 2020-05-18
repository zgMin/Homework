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
int TreeLeaf(BiTNode *root)
{
    static int num=0;
    if(!root)
    	return num;
    if(root->lchild==NULL && root->rchild==NULL)//左右子树均空 
    	num++;
    TreeLeaf(root->lchild);
    TreeLeaf(root->rchild);
    return num;
}
int TreeDepth(BiTree root){
    int r=0;
    int l=0;
    int deep=0;
    if(!root)
    	return deep;
    r=TreeDepth(root->rchild);//计算左子树的深度
    l=TreeDepth(root->lchild);//计算右子树的深度
    deep=r>l ? r+1 : l+1;	//取最大值+1 
    return deep;
}
int main(){
	ios::sync_with_stdio(false);
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
		}
		cout<<"以下是叶子节点数和树的深度："<<endl;
		cout<<TreeLeaf(root)<<endl;
		cout<<TreeDepth(root)<<endl;
	return 0;
} 
