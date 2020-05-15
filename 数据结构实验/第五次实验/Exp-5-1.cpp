#include<iostream>
#include<cstdio>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<r;i++) 
#define Status int
#define STACK_INIT_SIZE 100 //初始容量
#define STACKINCREMENT 10 //容量增量
using namespace std;
typedef struct {
char *base; //存储基址
char *top; //栈顶指针
int stacksize; //存储容量
} SqStack;
Status InitStack (SqStack &S){//构造空栈S
	S.base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!S.base) return 0;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}
Status Push(SqStack &S,char e){//元素e入栈S
	if(S.top-S.base>=S.stacksize){//栈满 
		cout<<"stack is full!"<<endl;
		return 0;
	}
	S.top++;
	*(S.top)=e;
	return 1;
}
Status Pop(SqStack &S,char &e){//栈S出栈，元素为e
	if(S.top==S.base){//栈空 
		cout<<"stack is empty!"<<endl;
		return 0;
	}
	e=*(S.top);
	S.top--;
	return 1;
}
int main(){
	int n;
	char ch;
	SqStack S;
	InitStack(S);
	while(1){
		cout<<"请输入选项："<<endl;
		cout<<"1.入栈 2.出栈 3.退出" <<endl;
		cin>>n;
		switch(n){
			case 1:
				cin>>ch;
				Push(S,ch);
				break;
			case 2:
				if(Pop(S,ch)) cout<<ch<<endl;
				break;
			case 3: return 0;
			default:
				cout<<"invalid operator!"<<endl;
				break;
		}
	}
	return 0;
}
