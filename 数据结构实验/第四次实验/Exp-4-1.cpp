#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct elem{
	int data;
	elem *next;
}elemNode,*elemLink;
typedef struct {
	elemLink head;
	int length;
}Linklist;
bool cmp(int a,int b){//�ȽϺ���,a<=b 
	return a<=b;
}
void OrderInsert(Linklist &L,int e, bool (*compare)(int,int))
{//���������ж�����compare���������L���ʵ�λ�ò���Ԫ��e��
	elemLink p;
	p=L.head;
	while(p){
		if( p->next==NULL || (*compare)(e,p->next->data)){//�ҵ�λ��,���в��� 
			elemLink q=(elemLink)malloc(sizeof(elemNode));
			q->data=e;
			q->next=p->next;
			p->next=q;
			L.length++;//���³��� 
			return; 
		}
		p=p->next;
	}
	return;
}
void OrderInput(Linklist &L, bool (*compare)(int,int))
{//���������ж�����compare��������������뺯��OrderInsert�����������L��
	L.head=(elemLink)malloc(sizeof(elemNode));
	L.head->next=NULL;//��ʼ������
	int n,e;
	cout<<"������Ԫ�ظ�����";
	cin>>n;
	while(n--){
		cin>>e;
		OrderInsert(L,e,compare);
	} 
}
void OrderMerge(Linklist &La,Linklist &Lb,Linklist &Lc,bool (*compare)(int,int))
{//���������ж�����compare�������������La��Lb�鲢Ϊһ�������Lc��
	Lc.head=(elemLink)malloc(sizeof(elemNode));
	elemLink pa,pb,pc;
	pa=La.head->next;
	pb=Lb.head->next;
	pc=Lc.head;
	while(pa&&pb){
		if(compare(pa->data,pb->data)){//paС 
			pc->next=pa;//���� 
			pa=pa->next; //���� 
		}
		else{//pbС 
			pc->next=pb;
			pb=pb->next;
		}
		pc=pc->next;
		pc->next=NULL; //pc���ƣ����Ͽ����� 
	}
	//��δ�����Ԫ�أ�������ȫ������ 
	if(pa)
		pc->next=pa;
	if(pb)
		pc->next=pb;
	free(La.head);
	free(Lb.head);//�ͷ�ԭ�� 
	Lc.length=La.length+Lb.length; 
	La.length=Lb.length=0;//���³��� 
	return;
}
void Output(Linklist &L){//�����L
	elemLink p;
	p=L.head->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return;
}
int main(){
	Linklist La,Lb,Lc;
	OrderInput(La,cmp);
	cout<<"La:"<<endl;
	Output(La);
	OrderInput(Lb,cmp);
	cout<<"Lb:"<<endl;
	Output(Lb);
	OrderMerge(La,Lb,Lc,cmp);
	cout<<"Lc:"<<endl;
	Output(Lc);
	return 0;
} 
