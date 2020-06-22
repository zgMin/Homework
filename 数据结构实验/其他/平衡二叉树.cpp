#include<iostream>
#include<cstdlib>
#include<cstdio>
#define Status int 
#define EH 0		//等高
#define LH +1		//左高
#define RH -1		//右高
using namespace std;
typedef int elemtype;
typedef struct tree{
	elemtype data;		//数据域
	int bf;				//平衡因子 
	struct tree *lchild,*rchild;	//左右孩子指针 
}BBTNode,*BBTree; 
void R_Rotate(BBTree &p){//右旋 
	BBTree lc=p->lchild;	//左孩子指针
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}
void L_Rotate(BBTree &p){//左旋 
	BBTree rc=p->rchild;	//右孩子指针
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;
}
BBTNode* search(BBTree T,elemtype key,BBTree pre,BBTree &p){
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
void LeftB(BBTree &T){//左平衡 ,分LR型和LL型 
	BBTree lc=T->lchild;
	switch(lc->bf){
		case LH:	//LL型,右旋 
			T->bf=lc->bf=EH;
			R_Rotate(T);break;
		case RH:	//LR型，左旋右旋
			BBTree lrc=lc->rchild;		//lrc左孩子的右孩子
			switch(lrc->bf){//修正T及左孩子的平衡因子
				case EH:
					T->bf=lc->bf=EH;break;
				case LH:
					T->bf=RH;lc->bf=EH;break;
				case RH: 
					T->bf=EH;lc->bf=LH;break;
			}
			lrc->bf=EH;
			L_Rotate(lc);
			R_Rotate(T);		//左旋右旋 
	} 
}
void RightB(BBTree &T){//右平衡 ,分RL型和RR型 
	BBTree rc=T->rchild;
	switch(rc->bf){
		case RH:	//RR型,左旋 
			T->bf=rc->bf=EH;
			L_Rotate(T);break;
		case LH:	//RL型，右旋左旋 
			BBTree rlc=rc->lchild;		//rlc右孩子的左孩子
			switch(rlc->bf){//修正T及右孩子的平衡因子
				case EH:
					T->bf=rc->bf=EH;break;
				case LH:
					T->bf=EH;rc->bf=RH;break;
				case RH: 
					T->bf=LH;rc->bf=EH;break;
			}
			rlc->bf=EH;
			R_Rotate(rc);
			L_Rotate(T);		//右旋左旋 
	} 
}
Status InsertAVL(BBTree &T,elemtype key,bool &taller){//AVL树插入新结点 
	//树T，插入元素key，树是否变高taller
	if(!T){			//空树 
		T=(BBTree)malloc(sizeof(BBTNode));
		T->data=key;
		T->rchild=T->lchild=NULL;
		T->bf=EH;		//等高
		taller=true; 
		return 1;
	} 
	else{
		if(T->data==key){
			taller=false; return 0;		//树中已存在key，插入失败 
		}
		if(T->data>key){		//在左子树中查找插入位置 
			if(!InsertAVL(T->lchild,key,taller))   return 0;//插入失败
			if(taller)//已插入左子树中，且左子树长高了
				switch(T->bf){
					case LH:			//原本左高，做左平衡处理 
						LeftB(T);taller=false;break;
					case EH:			//原本等高，现在一边长高 
						T->bf=LH;taller=true;break;
					case RH:			//原本右高，现在等高 
						T->bf=EH;taller=false;break;
				}
		}
		else{				//在右子树中查找插入位置
			if(!InsertAVL(T->rchild,key,taller))   return 0;//插入失败
			if(taller)//已插入左子树中，且左子树长高了
				switch(T->bf){
					case LH:			//原本左高，现在等高 
						T->bf=EH;taller=false;break;
					case EH:			//原本等高，现在一边长高 
						T->bf=RH;taller=true;break;
					case RH:			//原本右高，右平衡处理 
						RightB(T);taller=false;break;
				}	
		} 
	}
	return 1;
}
Status delnode(BBTree &T,elemtype key,bool &smaller){//AVL树删除结点 
		//树T，删除元素key，树是否变矮smaller
	if(!T){					//未找到该节点（空树/结点） 
		smaller=false;
		return 0; 
	} 
	if(T->data==key){		//找到该结点 
		if(T->lchild==NULL){//左空
			BBTree p=T;
			T=T->rchild;
			smaller=true;		//孩子上移，变矮 
			free(p);			//重接右子树
			return 1; 
		}
		else if(T->rchild==NULL){//右空
			BBTree p=T;
			T=T->lchild;
			smaller=true;		//孩子上移，变矮 
			free(p);			//重接左子树 
			return 1;
		}
		else{					//左右均不空,换点不删，等待递归到了再删 
			elemtype tmp=T->data;
			BBTree s;
			switch(T->bf){
				case LH:		//左高 
				case EH:		//等高
					s=T->lchild;
					while(s->rchild){
						s=s->rchild;
					}					//转左，向右走到尽头
					T->data=s->data;
					s->data=tmp;		//交换数据 
					break; 
				case RH:		//右高
					s=T->rchild;
					while(s->lchild){
						s=s->lchild;
					}					//转右，向左走到尽头
					T->data=s->data;
					s->data=tmp;		//交换数据	
					break;
			}
		} 
	}
	if(T->data>key){			//左子树中查找删除结点
		if(!delnode(T->lchild,key,smaller))   return 0;//插入失败
			if(smaller)//删除点在左子树中，且左子树变矮了
				switch(T->bf){
					case LH:			//原本左高，现在平衡 
						T->bf=EH;smaller=true;break;
					case EH:			//原本等高，现在一边变矮 
						T->bf=RH;smaller=false;break;
					case RH:			//原本右高，右调整
						RightB(T);smaller=true;break;
				}
	} 
	else{							//右子树中查找删除结点 
		if(!delnode(T->rchild,key,smaller))   return 0;//插入失败
			if(smaller)//删除点在左子树中，且左子树变矮了
				switch(T->bf){
					case LH:			//原本左高，左调整 
						LeftB(T);smaller=true;break;
					case EH:			//原本等高，现在一边变矮 
						T->bf=LH;smaller=false;break;
					case RH:			//原本右高，现在等高 
						T->bf=EH;smaller=true;break;
				}
	} 
	return 1; 
}
int main(){
	
	return 0;
}
 
