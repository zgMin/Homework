#include<iostream>
#include<cstdio>
#include<cstdlib>
#define Status bool
#define OVERFLOW -2
#define go(i,l,r) for(int i=l;i<r;i++)
using namespace std;
typedef struct{
	long num;		//学号 
	float yu,shu,ying;	//语文、数学、英语成绩 
	float sum,w_aver;	//总分和加权平均分 
}Student;
typedef struct{
	Student *score;		//存储空间基址 
	int length;		//当前长度 
	int listsize;	//当前分配容量 
} stu;
Status Init(stu& L,int INIT_SIZE){	//创建初始大小为INIT_SIZE的顺序表 
	L.score=(Student*)malloc(INIT_SIZE*sizeof(Student));
	if(!L.score) exit(OVERFLOW);
	L.length=0;
	L.listsize=INIT_SIZE;
	return true;
}
Status Increase(stu &L,int INCREASE_SIZE){
	Student *new_data=(Student*)realloc(L.score,(INCREASE_SIZE+L.listsize)*sizeof(Student));
	if(!new_data) exit(OVERFLOW);
	L.score=new_data;
	L.listsize+=INCREASE_SIZE;
	return true;
}
void Input_Work(stu& L){//输入n个学生信息到L表中,并计算sum和w_aver 
	cout<<"请输入学生个数：";
	int n;
	cin>>n; 
	cout<<"每行依次输入一个学生的学号，语文成绩，数学成绩以及英语成绩"<<endl; 
	go(i,0,n){
		if(L.length==L.listsize) Increase(L,5);//已满，扩容 
		cin>>(L.score+i)->num>>(L.score+i)->yu>>(L.score+i)->shu>>(L.score+i)->ying;
		//计算sum 
		(L.score+i)->sum=(L.score+i)->yu+(L.score+i)->shu+(L.score+i)->ying;
		//计算w_aver
		(L.score+i)->w_aver=(L.score+i)->yu*0.3+(L.score+i)->shu*0.5+(L.score+i)->ying*0.2;
		L.length++;//更新当前长度 
	}
}
void Output(stu &L){//输出学生信息 
	printf("学号\t语文成绩\t数学成绩\t英语成绩\t总分\t\t加权平均分\n");
	go(i,0,L.length){
		printf("%ld\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",(L.score+i)->num,(L.score+i)->yu,(L.score+i)->shu,(L.score+i)->ying,(L.score+i)->sum,(L.score+i)->w_aver);
	}
}
int main(){
	stu a;
	Init(a,10);
	Input_Work(a);
	Output(a);
	return 0;
} 
