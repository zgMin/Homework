#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define Status bool
#define OVERFLOW -2
#define go(i,l,r) for(int i=l;i<r;i++)
using namespace std;
typedef struct stuNode{
	long num;		//ѧ�� 
	float yu,shu,ying;	//���ġ���ѧ��Ӣ��ɼ� 
	float sum,w_aver;	//�ֺܷͼ�Ȩƽ���� 
	stuNode *next; 
}stuNode,*stuLink;
typedef struct {
	stuLink head,end;
	int length;
}Linklist;
void Input_Work(Linklist &L){//����n��ѧ����Ϣ��L����,������sum��w_aver 
	cout<<"������ѧ��������";
	int n;
	cin>>n; 
	cout<<"ÿ����������һ��ѧ����ѧ�ţ����ĳɼ�����ѧ�ɼ��Լ�Ӣ��ɼ�"<<endl;
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
		L.length++;//���µ�ǰ���� 
	}
	end->next=NULL;
	L.head=head;
	L.end=end;
}
void Output(Linklist L){//���ѧ����Ϣ 
	printf("ѧ��\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\t��Ȩƽ����\n");
	stuLink p=L.head->next;
	while(p!=NULL){
		printf("%ld\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",p->num,p->yu,p->shu,p->ying,p->sum,p->w_aver);
		p=p->next;
	}
}
void end_add(Linklist &L){
	cout<<"������������ѧ����ѧ�š�������ѧӢ��ɼ���"<<endl;
	stuLink p=(stuLink)malloc(sizeof(stuNode));
	cin>>p->num>>p->yu>>p->shu>>p->ying;
	p->sum= p->yu +p->shu + p->ying;
	p->w_aver= p->yu * 0.3 + p->shu *0.5 + p->ying *0.2;
	L.end->next=p;
	L.end=p;
	L.end->next=NULL;
	L.length++;//���µ�ǰ���� 
}
void del_num(Linklist &L){
	cout<<"������Ҫɾ����ѧ��ѧ�ţ�";
	long num;
	cin>>num;
	stuLink p=L.head;
	while(p->next->num!=num) p=p->next;
	stuLink q=p->next;//ȡ��Ŀ��Ԫ��
	p->next=p->next->next;//������������ 
	free(q);//�ͷſռ� 
	L.length--;//���µ�ǰ���� 
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
	//cout<<"���ܷ�����"<<endl; 
	//Output(a);
	//qsort_num(a,0,a.length-1);
	//cout<<"��ѧ������"<<endl; 
	//Output(a);
	return 0;
} 
