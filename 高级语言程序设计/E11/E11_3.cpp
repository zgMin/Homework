/*
	��������ķ�������ѧ���ɼ��������ϰ 1
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
	printf("��ֱ��������ѧ������Ϣ\n");
	L.length=0;
	stuLink head,p,end;
	head=(stuLink)malloc(sizeof(stuNode));
	end=head;
	for(int i=1;i<=5;i++){
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

int main(){
	Linklist L;
	Input_Work(L);
	Output(L);
	return 0;
} 
