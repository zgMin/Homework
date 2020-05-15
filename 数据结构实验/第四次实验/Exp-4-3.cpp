#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef int Status;
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*List;
List read(){	//��ȡ���ݲ��������� 
	List head,a,end;	//ͷ�ڵ㣬��ͨ�ڵ㣬β�ڵ� 
	head=(List)malloc(sizeof(Lnode));
	end=head;
	while(1){
		a=(List)malloc(sizeof(Lnode));
		scanf("%d",&a->data);
		if(a->data==-1)//���н���
			break;
		end->next=a;
		end=a; 
	}
	end->next=NULL;
	return head;
}
List work(List a,List b){
	List head,node,end;
	head=(List)malloc(sizeof(Lnode));
	end=head;
	List p1,p2;//p1���ڱ���a��p2���ڱ���b��
	p1=a->next,p2=b->next;
	while(p1&&p2){
		if(p1->data==p2->data){//��ͬԪ��,������±���ͬʱ���� 
			node=(List)malloc(sizeof(Lnode));
			node->data=p1->data;
			end->next=node;
			end=node;
			p1=p1->next;
			p2=p2->next;
		}
		else{//�ǽ�����ֵ��С�ĺ��� 
			if(p1->data<p2->data)
				p1=p1->next;
			else
				p2=p2->next;
		}
	} 
	end->next=NULL;
	return head;
	
}
void Print(List a){
	if(a->next==NULL){//�ձ� 
		printf("NULL");
		return;
	}
	List p;
	p=a->next;
	while(p){
		if(p->next)
			printf("%d ",p->data);
		else 
			printf("%d",p->data);
		p=p->next; 
	}
}
int main(){
	List a,b,c;
	a=read();
	b=read();
	c=work(a,b);
	Print(c);
	return 0;
} 
