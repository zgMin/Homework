#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef struct elem{
	int expon;//指数
	float coef;//系数 
	elem *next;
}elemNode,*elemLink;
typedef struct {
	elemLink head;
	int length;
}Linklist;
bool cmp(int a,int b){//比较函数,a<b 
	return a<b;
}
void OrderInsert(Linklist &L,int expon,float coef, bool (*compare)(int,int))
{//根据有序判定函数compare，在有序表L的适当位置插入数据；
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
		else if( p->next==NULL || (*compare)(expon,p->next->expon)){//找到位置,进行插入 
			elemLink q=(elemLink)malloc(sizeof(elemNode));
			q->expon=expon;
			q->coef=coef;
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
	int n,expon;
	float coef;
	cout<<"请输入项数：";
	cin>>n; 
	while(n--){
		cout<<"请分别输入该项系数和指数：";
		cin>>coef>>expon; 
		OrderInsert(L,expon,coef,compare);
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
		bool insert_ok=0;//是否插入 
		if(compare(pa->expon,pb->expon)){//pa小 
			pc->next=pa;//插入 
			pa=pa->next; //后移 
			insert_ok=1;
		}
		else if(compare(pb->expon,pa->expon)){//pb小 
			pc->next=pb;//插入 
			pb=pb->next; //后移 
			insert_ok=1;
		}
		else{//相等，合并，插入 
			pa->coef+=pb->coef;//合并 
			elemLink tmp;
			if(fabs(pa->coef)< 1e-6){//系数为0，此项消除 
				tmp=pa;
				pa=pa->next;
				free(tmp); 
			} 
			else{//否则插入 
				pc->next=pa;//插入 
				pa=pa->next; //后移 
				insert_ok=1;
			} 
			tmp=pb;
			pb=pb->next;
			free(tmp);//释放无用空间
		}
		if(insert_ok)
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
	bool is_first=1;//判断是否是首项 
	while(p){
		if(!is_first && p->coef>0)
			cout<<'+';//补充符号 
		if(p->coef!=1)
			if(p->coef==-1)
				cout<<'-';
			else cout<<p->coef;
		is_first=0;
		if(p->expon!=0)//特判常数项和一次项 
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
