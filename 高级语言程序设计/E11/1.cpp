/*
	����һ��ѧ���ɼ�������
	��ɶ�����Ĳ��롢�޸ġ�ɾ���Ȳ�����
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
}Linklist;//����ṹ 

void Input_Work(Linklist &L){//����n��ѧ����Ϣ��L����,������sum��w_aver 
	int n;
	printf("�������ʼѧ��������");
	scanf("%d",&n);
	printf("��ֱ�����ѧ������Ϣ\n");
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
		L.length++;//���µ�ǰ���� 
	}
	end->next=NULL;
	L.head=head;
	L.end=end;
}
void Output(Linklist L){//���ѧ����Ϣ 
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\tƽ����\n");
	stuLink p=L.head->next;
	while(p!=NULL){
		printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",p->number,p->name,p->yu,p->shu,p->ying,p->aver);
		p=p->next;
	} 
}
void end_add(Linklist &L){
	printf("������������ѧ����ѧ�š�������������ѧӢ��ɼ���\n");
	stuLink p=(stuLink)malloc(sizeof(stuNode));
	scanf("%d%s%d%d%d",&(p->number),p->name,&(p->yu),&(p->shu),&(p->ying));
	p->aver=(p->yu+p->shu+p->ying)/3.0;
	L.end->next=p;
	L.end=p;
	L.end->next=NULL;
	L.length++;//���µ�ǰ���� 
}
void del_num(Linklist &L){
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	int num;
	scanf("%d",&num);
	stuLink p=L.head;
	while(p->next->number!=num) p=p->next;
	stuLink q=p->next;//ȡ��Ŀ��Ԫ��
	p->next=p->next->next;//������������ 
	free(q);//�ͷſռ� 
	L.length--;//���µ�ǰ���� 
}
void modify(Linklist &L){
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	int num;
	scanf("%d",&num);
	stuLink p=L.head;
	while(p->next->number!=num) p=p->next;
	stuLink q=p->next;//ȡ��Ŀ��Ԫ��
	int ctr;
	printf("��ѡ��Ҫ�޸ĵ�����\n"); 
	printf("1.ѧ��  2.����  3.���ĳɼ�  4.��ѧ�ɼ�  5.Ӣ��ɼ�\n");
	printf("�����룺");
	scanf("%d",&ctr);
	printf("�����޸����ݣ�");
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
			printf("��Ч���룡");
			break;
				 
	}
}
int main(){
	Linklist L;
	Input_Work(L);
	printf("��ǰ�������ݣ�\n");
	Output(L);
	end_add(L); 
	printf("������������ݣ�\n");
	Output(L);
	del_num(L); 
	printf("ɾ�����������ݣ�\n");
	Output(L);
	modify(L); 
	printf("�޸ĺ��������ݣ�\n");
	Output(L);
	return 0;
} 
