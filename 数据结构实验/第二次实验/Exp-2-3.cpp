#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
void Input_Work(stu& L){//����n��ѧ����Ϣ��L����,������sum��w_aver 
	cout<<"������ѧ��������";
	int n;
	cin>>n; 
	cout<<"ÿ����������һ��ѧ����ѧ�ţ����ĳɼ�����ѧ�ɼ��Լ�Ӣ��ɼ�"<<endl; 
	go(i,0,n){
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
void qsort_sum(stu &L,int left,int right){//���ܷ�Ϊ�ؼ��ֵĿ��� 
	if(left>=right) return;//�ݹ����
	int i=left,j=right;
	Student base=L.score[left];
	while(i<j){
		while(L.score[j].sum>=base.sum && i<j) j--;	//�ұ߶��ǱȻ�׼ֵ���
		while(L.score[i].sum<=base.sum && i<j) i++;//��߶��ǱȻ�׼ֵС��
		if(i<j){
			Student tmp;
			tmp=L.score[i];
			L.score[i]=L.score[j];
			L.score[j]=tmp;
		} 
	} 
	//������׼ֵλ�� 
	L.score[left]=L.score[i];
	L.score[i]=base;
	qsort_sum(L,left,i-1);//�ݹ����
	qsort_sum(L,i+1,right);//�ݹ��ұ� 
}
void qsort_num(stu &L,int left,int right){//��ѧ��Ϊ�ؼ��ֵĿ��� 
	if(left>=right) return;//�ݹ����
	int i=left,j=right;
	Student base=L.score[left];
	while(i<j){
		while(L.score[j].num>=base.num && i<j) j--;	//�ұ߶��ǱȻ�׼ֵ���
		while(L.score[i].num<=base.num && i<j) i++;//��߶��ǱȻ�׼ֵС��
		if(i<j){
			Student tmp;
			tmp=L.score[i];
			L.score[i]=L.score[j];
			L.score[j]=tmp;
		} 
	} 
	//������׼ֵλ�� 
	L.score[left]=L.score[i];
	L.score[i]=base;
	qsort_num(L,left,i-1);//�ݹ����
	qsort_num(L,i+1,right);//�ݹ��ұ� 
}
int main(){
	stu a;
	Init(a,10);
	Input_Work(a);
	Output(a);
	qsort_sum(a,0,a.length-1);
	cout<<"���ܷ�����"<<endl; 
	Output(a);
	qsort_num(a,0,a.length-1);
	cout<<"��ѧ������"<<endl; 
	Output(a);
	return 0;
} 
