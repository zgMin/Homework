#include<iostream>
#include<cstdlib>
#include<cstdio>
#define Status int 
using namespace std;
typedef int elemtype;
typedef struct tree{
	elemtype data;		//数据域
	struct tree *lchild,*rchild;	//左右孩子指针 
}BiTNode,*BiTree; 
BiTNode* search(BiTree T,elemtype key,BiTree pre,BiTree &p){
	//在树T中查找data==key的结点，并返回结点地址,p是目标结点的父结点 ,pre是前驱节点 
	if(!T){
		p=pre;
		return NULL;
	}
	if(T->data==key){
		return T;	//找到并返回结点 
	} 
	if(T->data>key)
		return search(T->lchild,key,T,p);		//递归查找左子树
	if(T->data<key)
		return search(T->rchild,key,T,p);		//递归查找右子树	 
}
void insert(BiTree &T,elemtype key){
	BiTree p;
	if(search(T,key,NULL,p)==NULL){		//树中不存在key
		BiTree node=(BiTree)malloc(sizeof(BiTNode));
		node->data=key,node->lchild=node->rchild=NULL;		//设置新结点
		if(p==NULL)
			T=node;				//原树为空树 
		else if(key<p->data)
			p->lchild=node;		//插到左孩子
		else
			p->rchild=node;		//插到右孩子 
	}
	return;
}
Status delnode(BiTree &p){//删除结点p
	if(p==NULL) return 0;	//p不存在 
	if(p->rchild==NULL){//右子树是空的
	 	BiTree q=p;
		p=p->lchild;
		free(q);			//重接左子树 
	}
	else if(p->lchild==NULL){//左子树是空的
		BiTree q=p;
		p=p->rchild;
		free(q);			//重接右子树 
	}
	else{					//左右子树均不空 
		BiTree pre=p;
		BiTree s=p->rchild;
		while(s->lchild){
			pre=s;
			s=s->lchild;
		}					//转右，向左走到尽头
		p->data=s->data;
		if(pre!=p) pre->lchild=s->rchild;		
		else pre->rchild=s->rchild;		//重接s的右结点
	}
	return 1;
}
int main(){
	BiTree T=NULL;
	for(int i=0;i<7;i++){
		int tmp;
		cin>>tmp;
		insert(T,tmp);
	}
	int cnt=3;
	BiTree p;
	while(true){
		int key;
		cin>>key;
		p=search(T,key,NULL,p);
		cout<<delnode(p)<<endl;;
	}
	return 0;
}
