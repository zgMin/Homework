#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<r;i++) 
#define Status int
using namespace std;
typedef struct QNode {
	char data; //数据域
	struct QNode *next; //指针域
} QNode, *QueuePtr;
typedef struct {
	QueuePtr front; //队头指针
	QueuePtr rear; //队尾指针
} LinkQueue;
Status InitQueue(LinkQueue &Q){//构造空队列Q
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) return 0;//分配失败 
	Q.rear->next=NULL;
	return 1;
}
Status EnQueue(LinkQueue &Q,char e){//元素e入队列Q
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) return 0;//分配失败 
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;	//尾节点后边插入，并调整尾节点
	return 1; 
}
Status DeQueue(LinkQueue &Q,char &e){//队列Q出队列，元素为e
	if(Q.front==Q.rear){//队列已空 
		cout<<"queue is empty!"<<endl;
		return 0;
	}
	QueuePtr p=Q.front->next;
	e=p->data;//取出队首元素
	Q.front->next=p->next;
	free(p);//删除队首元素
	if(!Q.front)//p为唯一元素，调整队尾
		Q.rear=Q.front; 
	return 1; 
}
int main(){
	int n;
	char ch;
	LinkQueue Q;
	InitQueue(Q);
	while(1){
		cout<<"请输入选项："<<endl;
		cout<<"1.入队 2.出队 3.退出" <<endl;
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
