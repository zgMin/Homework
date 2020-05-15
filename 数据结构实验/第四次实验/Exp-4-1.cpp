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
bool cmp(int a,int b){//比较函数,a<=b 
	return a<=b;
}
void OrderInsert(Linklist &L,int e, bool (*compare)(int,int))
{//根据有序判定函数compare，在有序表L的适当位置插入元素e；
	elemLink p;
	p=L.head;
	while(p){
		if( p->next==NULL || (*compare)(e,p->next->data)){//找到位置,进行插入 
			elemLink q=(elemLink)malloc(sizeof(elemNode));
			q->data=e;
			q->next=p->next;
			p->next=q;
			L.length++;//更新长度 
			return; 
		}
		p=p->next;
	}
	return;
}
void OrderInput(Linklist &L, bool (*compare)(int,int))
{//根据有序判定函数compare，并利用有序插入函数OrderInsert，构造有序表L；
	L.head=(elemLink)malloc(sizeof(elemNode));
	L.head->next=NULL;//初始化链表
	int n,e;
	cout<<"请输入元素个数：";
	cin>>n;
	while(n--){
		cin>>e;
		OrderInsert(L,e,compare);
	} 
}
void OrderMerge(Linklist &La,Linklist &Lb,Linklist &Lc,bool (*compare)(int,int))
{//根据有序判定函数compare，将两个有序表La和Lb归并为一个有序表Lc。
	Lc.head=(elemLink)malloc(sizeof(elemNode));
	elemLink pa,pb,pc;
	pa=La.head->next;
	pb=Lb.head->next;
	pc=Lc.head;
	while(pa&&pb){
		if(compare(pa->data,pb->data)){//pa小 
			pc->next=pa;//插入 
			pa=pa->next; //后移 
		}
		else{//pb小 
			pc->next=pb;
			pb=pb->next;
		}
		pc=pc->next;
		pc->next=NULL; //pc后移，并断开后链 
	}
	//将未插入的元素，按次序全部插入 
	if(pa)
		pc->next=pa;
	if(pb)
		pc->next=pb;
	free(La.head);
	free(Lb.head);//释放原表 
	Lc.length=La.length+Lb.length; 
	La.length=Lb.length=0;//更新长度 
	return;
}
void Output(Linklist &L){//输出表L
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
