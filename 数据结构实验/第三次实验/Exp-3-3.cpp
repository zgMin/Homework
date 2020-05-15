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
void val_swap(stuLink p1,stuLink p2){
	stuNode tmp;
	tmp.num=p1->num;
	tmp.yu=p1->yu;
	tmp.shu=p1->shu;
	tmp.ying=p1->ying;
	tmp.sum=p1->sum;
	tmp.w_aver=p1->w_aver;
	
	p1->num=p2->num;
	p1->yu=p2->yu;
	p1->shu=p2->shu;
	p1->ying=p2->ying;
	p1->sum=p2->sum;
	p1->w_aver=p2->w_aver;
	
	p2->num=tmp.num;
	p2->yu=tmp.yu;
	p2->shu=tmp.shu;
	p2->ying=tmp.ying;
	p2->sum=tmp.sum;
	p2->w_aver=tmp.w_aver;
	
}
void qsort_sum(stuLink head,stuLink end){//���ܷ�Ϊ�ؼ��ֵĿ��� 
	if(head!=end){//�ǿձ�Ͳ�ֹһ��Ԫ�� 
		float base=end->sum;//��׼ֵ
		cout<<base<<endl;
		stuLink p1,p2;//����ָ�� 
		p1=head; //p1��֤��������ȫ��С�ڻ�׼ֵ 
		p2=head;//p2��֤��������ȫ�����ڻ�׼ֵ
		while(p2!=end){
			if(p2->sum<base){//ά��p1,p2
				val_swap(p1,p2);
				p1=p1->next; 
			}
			p2=p2->next;
		} 
		//������׼ֵλ��
		if(p1!=end){//p1=end˵���Ѿ���������� 
			val_swap(p1,p2);
			qsort_sum(head,p1);//�ݹ����
			qsort_sum(p1->next,end);//�ݹ��ұ� 
		}
	}
}
void qsort_num(stuLink head,stuLink end){//��ѧ��Ϊ�ؼ��ֵĿ��� 
	if(head!=end){
		long base=end->num;//��׼ֵ
		stuLink p1,p2;//����ָ�� 
		p1=head; //p1��֤��������ȫ��С�ڻ�׼ֵ 
		p2=head;//p2��֤��������ȫ�����ڻ�׼ֵ
		while(p2!=end){
			if(p2->num<base){//ά��p1,p2 
				val_swap(p1,p2);
				p1=p1->next; 
			}
			p2=p2->next;
		} 
		//������׼ֵλ��
		if(p1!=end){//p1=end˵���Ѿ���������� 
			val_swap(p1,p2);
			qsort_num(head,p1);//�ݹ����
			qsort_num(p1->next,end);//�ݹ��ұ� 
		}
	}
}
int main(){
	Linklist a;
	Input_Work(a);
	Output(a);
	qsort_sum(a.head->next,a.end);
	cout<<"���ܷ�����"<<endl; 
	Output(a);
	qsort_num(a.head->next,a.end);
	cout<<"��ѧ������"<<endl; 
	Output(a);
	return 0;
} 
