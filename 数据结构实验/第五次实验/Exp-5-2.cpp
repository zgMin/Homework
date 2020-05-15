#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<r;i++) 
#define Status int
using namespace std;
typedef struct QNode {
	char data; //������
	struct QNode *next; //ָ����
} QNode, *QueuePtr;
typedef struct {
	QueuePtr front; //��ͷָ��
	QueuePtr rear; //��βָ��
} LinkQueue;
Status InitQueue(LinkQueue &Q){//����ն���Q
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) return 0;//����ʧ�� 
	Q.rear->next=NULL;
	return 1;
}
Status EnQueue(LinkQueue &Q,char e){//Ԫ��e�����Q
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) return 0;//����ʧ�� 
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;	//β�ڵ��߲��룬������β�ڵ�
	return 1; 
}
Status DeQueue(LinkQueue &Q,char &e){//����Q�����У�Ԫ��Ϊe
	if(Q.front==Q.rear){//�����ѿ� 
		cout<<"queue is empty!"<<endl;
		return 0;
	}
	QueuePtr p=Q.front->next;
	e=p->data;//ȡ������Ԫ��
	Q.front->next=p->next;
	free(p);//ɾ������Ԫ��
	if(!Q.front)//pΪΨһԪ�أ�������β
		Q.rear=Q.front; 
	return 1; 
}
int main(){
	int n;
	char ch;
	LinkQueue Q;
	InitQueue(Q);
	while(1){
		cout<<"������ѡ�"<<endl;
		cout<<"1.��� 2.���� 3.�˳�" <<endl;
		cin>>n;
		switch(n){
			case 1:
				cin>>ch;
				EnQueue(Q,ch);
				break;
			case 2:
				if(DeQueue(Q,ch)) cout<<ch<<endl;
				break;
			case 3: return 0;
			default:
				cout<<"invalid operator!"<<endl;
				break;
		}
	}
	return 0;
}
