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
		//cout<<"stack is full!"<<endl;
		return 0;
	}
	S.top++;
	*(S.top)=e;
	return 1;
}
Status Pop(SqStack &S,char &e){//栈S出栈，元素为e
	if(S.top==S.base){//栈空 
		//cout<<"stack is empty!"<<endl;
		return 0;
	}
	e=*(S.top);
	S.top--;
	return 1;
}
void clear(SqStack &S){
	char ch;
	while(Pop(S,ch)){
		continue;
	}
	return;
}
int main(){
	int n;
	char ch;
	SqStack S;
	InitStack(S);
	go(i,0,2){
		bool flag=1;//表示是否匹配成功 
		cout<<"请输入表达式："<<endl;
		while(1){
			ch=getchar();
			if(ch=='\n') break;
			if(flag){//当前没有出现错误 
				if((ch == '{' )|| (ch =='[') || (ch =='(')){
					//读到左括号，入栈
					Push(S,ch);
				}
				if((ch == '}') || (ch ==']') || (ch ==')')){
					//读到右括号，出栈进行匹配
					char tmp;
					if(!Pop(S,tmp)){//没有左括号 
						flag=0;
					}
					if(!((tmp == '{' && ch == '}') || (tmp == '(' && ch == ')') || (tmp == '[' && ch == ']')))
						flag = 0; //不匹配 
				}
			} 
		} 
		if(flag) cout<<"yes\n";
		else cout<<"no\n";
		clear(S);
	}
	return 0;
}
