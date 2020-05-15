#include<iostream>
#include<cstdio>
#include<cstdlib>
#define go(i,l,r) for(int i=l;i<r;i++) 
#define Status int
#define STACK_INIT_SIZE 100 //��ʼ����
#define STACKINCREMENT 10 //��������
using namespace std;
typedef struct {
char *base; //�洢��ַ
char *top; //ջ��ָ��
int stacksize; //�洢����
} SqStack;
Status InitStack (SqStack &S){//�����ջS
	S.base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!S.base) return 0;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}
Status Push(SqStack &S,char e){//Ԫ��e��ջS
	if(S.top-S.base>=S.stacksize){//ջ�� 
		cout<<"stack is full!"<<endl;
		return 0;
	}
	S.top++;
	*(S.top)=e;
	return 1;
}
Status Pop(SqStack &S,char &e){//ջS��ջ��Ԫ��Ϊe
	if(S.top==S.base){//ջ�� 
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
		cout<<"������ѡ�"<<endl;
		cout<<"1.��ջ 2.��ջ 3.�˳�" <<endl;
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
