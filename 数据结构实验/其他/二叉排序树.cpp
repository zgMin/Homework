#include<iostream>
#include<cstdlib>
#include<cstdio>
#define Status int 
using namespace std;
typedef int elemtype;
typedef struct tree{
	elemtype data;		//������
	struct tree *lchild,*rchild;	//���Һ���ָ�� 
}BiTNode,*BiTree; 
BiTNode* search(BiTree T,elemtype key,BiTree pre,BiTree &p){
	//����T�в���data==key�Ľ�㣬�����ؽ���ַ,p��Ŀ����ĸ���� ,pre��ǰ���ڵ� 
	if(!T){
		p=pre;
		return NULL;
	}
	if(T->data==key){
		return T;	//�ҵ������ؽ�� 
	} 
	if(T->data>key)
		return search(T->lchild,key,T,p);		//�ݹ����������
	if(T->data<key)
		return search(T->rchild,key,T,p);		//�ݹ����������	 
}
void insert(BiTree &T,elemtype key){
	BiTree p;
	if(search(T,key,NULL,p)==NULL){		//���в�����key
		BiTree node=(BiTree)malloc(sizeof(BiTNode));
		node->data=key,node->lchild=node->rchild=NULL;		//�����½��
		if(p==NULL)
			T=node;				//ԭ��Ϊ���� 
		else if(key<p->data)
			p->lchild=node;		//�嵽����
		else
			p->rchild=node;		//�嵽�Һ��� 
	}
	return;
}
Status delnode(BiTree &p){//ɾ�����p
	if(p==NULL) return 0;	//p������ 
	if(p->rchild==NULL){//�������ǿյ�
	 	BiTree q=p;
		p=p->lchild;
		free(q);			//�ؽ������� 
	}
	else if(p->lchild==NULL){//�������ǿյ�
		BiTree q=p;
		p=p->rchild;
		free(q);			//�ؽ������� 
	}
	else{					//�������������� 
		BiTree pre=p;
		BiTree s=p->rchild;
		while(s->lchild){
			pre=s;
			s=s->lchild;
		}					//ת�ң������ߵ���ͷ
		p->data=s->data;
		if(pre!=p) pre->lchild=s->rchild;		
		else pre->rchild=s->rchild;		//�ؽ�s���ҽ��
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
