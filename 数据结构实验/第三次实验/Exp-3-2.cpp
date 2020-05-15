#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define Status bool
#define OVERFLOW -2
#define go(i,l,r) for(int i=l;i<r;i++)
using namespace std;
typedef struct stuNode{
	long num;		//学号 
	float yu,shu,ying;	//语文、数学、英语成绩 
	float sum,w_aver;	//总分和加权平均分 
	stuNode *next; 
}stuNode,*stuLink;
typedef struct {
	stuLink head,end;
	int length;
}Linklist;
void Input_Work(Linklist &L){//输入n个学生信息到L表中,并计算sum和w_aver 
	cout<<"请输入学生个数：";
	int n;
	cin>>n; 
	cout<<"每行依次输入一个学生的学号，语文成绩，数学成绩以及英语成绩"<<endl;
	L.length=0;
	stuLink head,p,end;
	head=(stuLink)malloc(sizeof(stuNode));
	end=head;
	go(i,0,n){
		p=(stuLink)malloc(sizeof(stuNode));
		cin>>p->num>>p->yu>>p->shu>>p->ying;
		p->sum= p->yu +p->shu + p->ying;
		p->w_aver= p->yu * 0.3 + p->shu *0.5 + p->ying *0.2;
		end->next=p;
		end=p;
		L.length++;//更新当前长度 
	}
	end->next=NULL;
	L.head=head;
	L.end=end;
}
void Output(Linklist L){//输出学生信息 
	printf("学号\t语文成绩\t数学成绩\t英语成绩\t总分\t\t加权平均分\n");
	stuLink p=L.head->next;
	while(p!=NULL){
		printf("%ld\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",p->num,p->yu,p->shu,p->ying,p->sum,p->w_aver);
		p=p->next;
	}
}
void end_add(Linklist &L){
	cout<<"请依次输入新学生的学号、语文数学英语成绩："<<endl;
	stuLink p=(stuLink)malloc(sizeof(stuNode));
	cin>>p->num>>p->yu>>p->shu>>p->ying;
	p->sum= p->yu +p->shu + p->ying;
	p->w_aver= p->yu * 0.3 + p->shu *0.5 + p->ying *0.2;
	L.end->next=p;
	L.end=p;
	L.end->next=NULL;
	L.length++;//更新当前长度 
}
void del_num(Linklist &L){
	cout<<"请输入要删除的学生学号：";
	long num;
	cin>>num;
	stuLink p=L.head;
	while(p->next->num!=num) p=p->next;
	stuLink q=p->next;//取出目标元素
	p->next=p->next->next;//设置链表连接 
	free(q);//释放空间 
	L.length--;//更新当前长度 
}
int main(){
	Linklist a;
	Input_Work(a);
	Output(a);
	end_add(a);
	Output(a);
	del_num(a);
	Output(a);
	//qsort_sum(a,0,a.length-1);
	//cout<<"按总分升序："<<endl; 
	//Output(a);
	//qsort_num(a,0,a.length-1);
	//cout<<"按学号升序："<<endl; 
	//Output(a);
	return 0;
} 
