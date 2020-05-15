#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef int Status;
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*List;
List read(){	//读取数据并建立链表 
	List head,a,end;	//头节点，普通节点，尾节点 
	head=(List)malloc(sizeof(Lnode));
	end=head;
	while(1){
		a=(List)malloc(sizeof(Lnode));
		scanf("%d",&a->data);
		if(a->data==-1)//序列结束
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
	List p1,p2;//p1用于遍历a表，p2用于遍历b表
	p1=a->next,p2=b->next;
	while(p1&&p2){
		if(p1->data==p2->data){//共同元素,则加入新表，并同时后移 
			node=(List)malloc(sizeof(Lnode));
			node->data=p1->data;
			end->next=node;
			end=node;
			p1=p1->next;
			p2=p2->next;
		}
		else{//非降序，数值较小的后移 
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
	if(a->next==NULL){//空表 
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
