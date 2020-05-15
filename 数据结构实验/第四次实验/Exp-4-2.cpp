#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef struct elem{
	int expon;//ָ��
	float coef;//ϵ�� 
	elem *next;
}elemNode,*elemLink;
typedef struct {
	elemLink head;
	int length;
}Linklist;
bool cmp(int a,int b){//�ȽϺ���,a<b 
	return a<b;
}
void OrderInsert(Linklist &L,int expon,float coef, bool (*compare)(int,int))
{//���������ж�����compare���������L���ʵ�λ�ò������ݣ�
	elemLink p;
	p=L.head;
	while(p){
		if(p->next!=NULL&&p->next->expon==expon){
			p->next->coef+=coef;
			if(fabs(p->next->coef)<1e-6){
			elemLink tmp=p->next;
			p->next=p->next->next;
			free(tmp);
			}
			return;
		} 
		else if( p->next==NULL || (*compare)(expon,p->next->expon)){//�ҵ�λ��,���в��� 
			elemLink q=(elemLink)malloc(sizeof(elemNode));
			q->expon=expon;
			q->coef=coef;
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
	int n,expon;
	float coef;
	cout<<"������������";
	cin>>n; 
	while(n--){
		cout<<"��ֱ��������ϵ����ָ����";
		cin>>coef>>expon; 
		OrderInsert(L,expon,coef,compare);
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
		bool insert_ok=0;//�Ƿ���� 
		if(compare(pa->expon,pb->expon)){//paС 
			pc->next=pa;//���� 
			pa=pa->next; //���� 
			insert_ok=1;
		}
		else if(compare(pb->expon,pa->expon)){//pbС 
			pc->next=pb;//���� 
			pb=pb->next; //���� 
			insert_ok=1;
		}
		else{//��ȣ��ϲ������� 
			pa->coef+=pb->coef;//�ϲ� 
			elemLink tmp;
			if(fabs(pa->coef)< 1e-6){//ϵ��Ϊ0���������� 
				tmp=pa;
				pa=pa->next;
				free(tmp); 
			} 
			else{//������� 
				pc->next=pa;//���� 
				pa=pa->next; //���� 
				insert_ok=1;
			} 
			tmp=pb;
			pb=pb->next;
			free(tmp);//�ͷ����ÿռ�
		}
		if(insert_ok)
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
	bool is_first=1;//�ж��Ƿ������� 
	while(p){
		if(!is_first && p->coef>0)
			cout<<'+';//������� 
		if(p->coef!=1)
			if(p->coef==-1)
				cout<<'-';
			else cout<<p->coef;
		is_first=0;
		if(p->expon!=0)//���г������һ���� 
			if(p->expon==1)
				cout<<'x';
			else{
				cout<<"x^"<<p->expon;
			}
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
