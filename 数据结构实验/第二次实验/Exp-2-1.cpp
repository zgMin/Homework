#include<iostream>
#include<cstdio>
#include<cstdlib>
#define Status bool
#define OVERFLOW -2
#define go(i,l,r) for(int i=l;i<r;i++)
using namespace std;
typedef struct{
	long num;		//ѧ�� 
	float yu,shu,ying;	//���ġ���ѧ��Ӣ��ɼ� 
	float sum,w_aver;	//�ֺܷͼ�Ȩƽ���� 
}Student;
typedef struct{
	Student *score;		//�洢�ռ��ַ 
	int length;		//��ǰ���� 
	int listsize;	//��ǰ�������� 
} stu;
Status Init(stu& L,int INIT_SIZE){	//������ʼ��СΪINIT_SIZE��˳��� 
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
void Input_Work(stu& L){//����n��ѧ����Ϣ��L����,������sum��w_aver 
	cout<<"������ѧ��������";
	int n;
	cin>>n; 
	cout<<"ÿ����������һ��ѧ����ѧ�ţ����ĳɼ�����ѧ�ɼ��Լ�Ӣ��ɼ�"<<endl; 
	go(i,0,n){
		if(L.length==L.listsize) Increase(L,5);//���������� 
		cin>>(L.score+i)->num>>(L.score+i)->yu>>(L.score+i)->shu>>(L.score+i)->ying;
		//����sum 
		(L.score+i)->sum=(L.score+i)->yu+(L.score+i)->shu+(L.score+i)->ying;
		//����w_aver
		(L.score+i)->w_aver=(L.score+i)->yu*0.3+(L.score+i)->shu*0.5+(L.score+i)->ying*0.2;
		L.length++;//���µ�ǰ���� 
	}
}
void Output(stu &L){//���ѧ����Ϣ 
	printf("ѧ��\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\t��Ȩƽ����\n");
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
