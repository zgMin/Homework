#include<iostream>
#include<cstdlib>
#include<cstdio>
#define Status int 
#define EH 0		//�ȸ�
#define LH +1		//���
#define RH -1		//�Ҹ�
using namespace std;
typedef int elemtype;
typedef struct tree{
	elemtype data;		//������
	int bf;				//ƽ������ 
	struct tree *lchild,*rchild;	//���Һ���ָ�� 
}BBTNode,*BBTree; 
void R_Rotate(BBTree &p){//���� 
	BBTree lc=p->lchild;	//����ָ��
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}
void L_Rotate(BBTree &p){//���� 
	BBTree rc=p->rchild;	//�Һ���ָ��
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;
}
BBTNode* search(BBTree T,elemtype key,BBTree pre,BBTree &p){
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
void LeftB(BBTree &T){//��ƽ�� ,��LR�ͺ�LL�� 
	BBTree lc=T->lchild;
	switch(lc->bf){
		case LH:	//LL��,���� 
			T->bf=lc->bf=EH;
			R_Rotate(T);break;
		case RH:	//LR�ͣ���������
			BBTree lrc=lc->rchild;		//lrc���ӵ��Һ���
			switch(lrc->bf){//����T�����ӵ�ƽ������
				case EH:
					T->bf=lc->bf=EH;break;
				case LH:
					T->bf=RH;lc->bf=EH;break;
				case RH: 
					T->bf=EH;lc->bf=LH;break;
			}
			lrc->bf=EH;
			L_Rotate(lc);
			R_Rotate(T);		//�������� 
	} 
}
void RightB(BBTree &T){//��ƽ�� ,��RL�ͺ�RR�� 
	BBTree rc=T->rchild;
	switch(rc->bf){
		case RH:	//RR��,���� 
			T->bf=rc->bf=EH;
			L_Rotate(T);break;
		case LH:	//RL�ͣ��������� 
			BBTree rlc=rc->lchild;		//rlc�Һ��ӵ�����
			switch(rlc->bf){//����T���Һ��ӵ�ƽ������
				case EH:
					T->bf=rc->bf=EH;break;
				case LH:
					T->bf=EH;rc->bf=RH;break;
				case RH: 
					T->bf=LH;rc->bf=EH;break;
			}
			rlc->bf=EH;
			R_Rotate(rc);
			L_Rotate(T);		//�������� 
	} 
}
Status InsertAVL(BBTree &T,elemtype key,bool &taller){//AVL�������½�� 
	//��T������Ԫ��key�����Ƿ���taller
	if(!T){			//���� 
		T=(BBTree)malloc(sizeof(BBTNode));
		T->data=key;
		T->rchild=T->lchild=NULL;
		T->bf=EH;		//�ȸ�
		taller=true; 
		return 1;
	} 
	else{
		if(T->data==key){
			taller=false; return 0;		//�����Ѵ���key������ʧ�� 
		}
		if(T->data>key){		//���������в��Ҳ���λ�� 
			if(!InsertAVL(T->lchild,key,taller))   return 0;//����ʧ��
			if(taller)//�Ѳ����������У���������������
				switch(T->bf){
					case LH:			//ԭ����ߣ�����ƽ�⴦�� 
						LeftB(T);taller=false;break;
					case EH:			//ԭ���ȸߣ�����һ�߳��� 
						T->bf=LH;taller=true;break;
					case RH:			//ԭ���Ҹߣ����ڵȸ� 
						T->bf=EH;taller=false;break;
				}
		}
		else{				//���������в��Ҳ���λ��
			if(!InsertAVL(T->rchild,key,taller))   return 0;//����ʧ��
			if(taller)//�Ѳ����������У���������������
				switch(T->bf){
					case LH:			//ԭ����ߣ����ڵȸ� 
						T->bf=EH;taller=false;break;
					case EH:			//ԭ���ȸߣ�����һ�߳��� 
						T->bf=RH;taller=true;break;
					case RH:			//ԭ���Ҹߣ���ƽ�⴦�� 
						RightB(T);taller=false;break;
				}	
		} 
	}
	return 1;
}
Status delnode(BBTree &T,elemtype key,bool &smaller){//AVL��ɾ����� 
		//��T��ɾ��Ԫ��key�����Ƿ�䰫smaller
	if(!T){					//δ�ҵ��ýڵ㣨����/��㣩 
		smaller=false;
		return 0; 
	} 
	if(T->data==key){		//�ҵ��ý�� 
		if(T->lchild==NULL){//���
			BBTree p=T;
			T=T->rchild;
			smaller=true;		//�������ƣ��䰫 
			free(p);			//�ؽ�������
			return 1; 
		}
		else if(T->rchild==NULL){//�ҿ�
			BBTree p=T;
			T=T->lchild;
			smaller=true;		//�������ƣ��䰫 
			free(p);			//�ؽ������� 
			return 1;
		}
		else{					//���Ҿ�����,���㲻ɾ���ȴ��ݹ鵽����ɾ 
			elemtype tmp=T->data;
			BBTree s;
			switch(T->bf){
				case LH:		//��� 
				case EH:		//�ȸ�
					s=T->lchild;
					while(s->rchild){
						s=s->rchild;
					}					//ת�������ߵ���ͷ
					T->data=s->data;
					s->data=tmp;		//�������� 
					break; 
				case RH:		//�Ҹ�
					s=T->rchild;
					while(s->lchild){
						s=s->lchild;
					}					//ת�ң������ߵ���ͷ
					T->data=s->data;
					s->data=tmp;		//��������	
					break;
			}
		} 
	}
	if(T->data>key){			//�������в���ɾ�����
		if(!delnode(T->lchild,key,smaller))   return 0;//����ʧ��
			if(smaller)//ɾ�������������У����������䰫��
				switch(T->bf){
					case LH:			//ԭ����ߣ�����ƽ�� 
						T->bf=EH;smaller=true;break;
					case EH:			//ԭ���ȸߣ�����һ�߱䰫 
						T->bf=RH;smaller=false;break;
					case RH:			//ԭ���Ҹߣ��ҵ���
						RightB(T);smaller=true;break;
				}
	} 
	else{							//�������в���ɾ����� 
		if(!delnode(T->rchild,key,smaller))   return 0;//����ʧ��
			if(smaller)//ɾ�������������У����������䰫��
				switch(T->bf){
					case LH:			//ԭ����ߣ������ 
						LeftB(T);smaller=true;break;
					case EH:			//ԭ���ȸߣ�����һ�߱䰫 
						T->bf=LH;smaller=false;break;
					case RH:			//ԭ���Ҹߣ����ڵȸ� 
						T->bf=EH;smaller=true;break;
				}
	} 
	return 1; 
}
int main(){
	
	return 0;
}
 
