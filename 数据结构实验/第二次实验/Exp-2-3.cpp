#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
void Input_Work(stu& L){//输入n个学生信息到L表中,并计算sum和w_aver 
	cout<<"请输入学生个数：";
	int n;
	cin>>n; 
	cout<<"每行依次输入一个学生的学号，语文成绩，数学成绩以及英语成绩"<<endl; 
	go(i,0,n){
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
void qsort_sum(stu &L,int left,int right){//以总分为关键字的快排 
	if(left>=right) return;//递归出口
	int i=left,j=right;
	Student base=L.score[left];
	while(i<j){
		while(L.score[j].sum>=base.sum && i<j) j--;	//右边都是比基准值大的
		while(L.score[i].sum<=base.sum && i<j) i++;//左边都是比基准值小的
		if(i<j){
			Student tmp;
			tmp=L.score[i];
			L.score[i]=L.score[j];
			L.score[j]=tmp;
		} 
	} 
	//调整基准值位置 
	L.score[left]=L.score[i];
	L.score[i]=base;
	qsort_sum(L,left,i-1);//递归左边
	qsort_sum(L,i+1,right);//递归右边 
}
void qsort_num(stu &L,int left,int right){//以学号为关键字的快排 
	if(left>=right) return;//递归出口
	int i=left,j=right;
	Student base=L.score[left];
	while(i<j){
		while(L.score[j].num>=base.num && i<j) j--;	//右边都是比基准值大的
		while(L.score[i].num<=base.num && i<j) i++;//左边都是比基准值小的
		if(i<j){
			Student tmp;
			tmp=L.score[i];
			L.score[i]=L.score[j];
			L.score[j]=tmp;
		} 
	} 
	//调整基准值位置 
	L.score[left]=L.score[i];
	L.score[i]=base;
	qsort_num(L,left,i-1);//递归左边
	qsort_num(L,i+1,right);//递归右边 
}
int main(){
	stu a;
	Init(a,10);
	Input_Work(a);
	Output(a);
	qsort_sum(a,0,a.length-1);
	cout<<"按总分升序："<<endl; 
	Output(a);
	qsort_num(a,0,a.length-1);
	cout<<"按学号升序："<<endl; 
	Output(a);
	return 0;
} 
