/*
	创建一个学生成绩的链表，
	完成对链表的插入、修改、删除等操作。
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
	int n;
	printf("请输入初始学生个数：");
	scanf("%d",&n);
	printf("请分别输入学生的信息\n");
	L.length=0;
	stuLink head,p,end;
	head=(stuLink)malloc(sizeof(stuNode));
	end=head;
	for(int i=1;i<=n;i++){
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
void end_add(Linklist &L){
	printf("请依次输入新学生的学号、姓名、语文数学英语成绩：\n");
	stuLink p=(stuLink)malloc(sizeof(stuNode));
	scanf("%d%s%d%d%d",&(p->number),p->name,&(p->yu),&(p->shu),&(p->ying));
	p->aver=(p->yu+p->shu+p->ying)/3.0;
	L.end->next=p;
	L.end=p;
	L.end->next=NULL;
	L.length++;//更新当前长度 
}
void del_num(Linklist &L){
	printf("请输入要删除的学生学号：");
	int num;
	scanf("%d",&num);
	stuLink p=L.head;
	while(p->next->number!=num) p=p->next;
	stuLink q=p->next;//取出目标元素
	p->next=p->next->next;//设置链表连接 
	free(q);//释放空间 
	L.length--;//更新当前长度 
}
void modify(Linklist &L){
	printf("请输入要修改的学生学号：");
	int num;
	scanf("%d",&num);
	stuLink p=L.head;
	while(p->next->number!=num) p=p->next;
	stuLink q=p->next;//取出目标元素
	int ctr;
	printf("请选择要修改的属性\n"); 
	printf("1.学号  2.姓名  3.语文成绩  4.数学成绩  5.英语成绩\n");
	printf("请输入：");
	scanf("%d",&ctr);
	printf("输入修改内容：");
	switch(ctr){
		case 1:
			scanf("%d",&(q->number));
			break;
		case 2:
			scanf("%s",q->name);
			break;
		case 3:
			scanf("%d",&(q->yu));
			q->aver=(q->yu+q->shu+q->ying)/3.0;
			break;
		case 4:
			scanf("%d",&(q->shu));
			q->aver=(q->yu+q->shu+q->ying)/3.0;
			break;
		case 5:
			scanf("%d",&(q->ying));
			q->aver=(q->yu+q->shu+q->ying)/3.0;
			break;
		default:
			printf("无效输入！");
			break;
				 
	}
}
int main(){
	Linklist L;
	Input_Work(L);
	printf("当前链表内容：\n");
	Output(L);
	end_add(L); 
	printf("插入后链表内容：\n");
	Output(L);
	del_num(L); 
	printf("删除后链表内容：\n");
	Output(L);
	modify(L); 
	printf("修改后链表内容：\n");
	Output(L);
	return 0;
} 
