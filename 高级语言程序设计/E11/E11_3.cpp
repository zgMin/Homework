/*
	采用链表的方法保存学生成绩，完成练习 1
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct stuNode{
	int number;
	char name[20];
	int yu,shu,ying;
	float aver;
	stuNode *next;
}stuNode,*stuLink;

typedef struct {
	stuLink head,end;
	int length;
}Linklist;//链表结构 

void Input_Work(Linklist &L){//输入n个学生信息到L表中,并计算sum和w_aver 
	printf("请分别输入五个学生的信息\n");
	L.length=0;
	stuLink head,p,end;
	head=(stuLink)malloc(sizeof(stuNode));
	end=head;
	for(int i=1;i<=5;i++){
		p=(stuLink)malloc(sizeof(stuNode));
		scanf("%d%s%d%d%d",&(p->number),p->name,&(p->yu),&(p->shu),&(p->ying));
		p->aver=(p->yu+p->shu+p->ying)/3.0;
		end->next=p;
		end=p;
		L.length++;//更新当前长度 
	}
	end->next=NULL;
	L.head=head;
	L.end=end;
}
void Output(Linklist L){//输出学生信息 
	printf("学号\t姓名\t语文\t数学\t英语\t平均分\n");
	stuLink p=L.head->next;
	while(p!=NULL){
		printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",p->number,p->name,p->yu,p->shu,p->ying,p->aver);
		p=p->next;
	}
}

int main(){
	Linklist L;
	Input_Work(L);
	Output(L);
	return 0;
} 
