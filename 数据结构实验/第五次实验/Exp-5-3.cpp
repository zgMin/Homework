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
		//cout<<"stack is full!"<<endl;
		return 0;
	}
	S.top++;
	*(S.top)=e;
	return 1;
}
Status Pop(SqStack &S,char &e){//ջS��ջ��Ԫ��Ϊe
	if(S.top==S.base){//ջ�� 
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
		bool flag=1;//��ʾ�Ƿ�ƥ��ɹ� 
		cout<<"��������ʽ��"<<endl;
		while(1){
			ch=getchar();
			if(ch=='\n') break;
			if(flag){//��ǰû�г��ִ��� 
				if((ch == '{' )|| (ch =='[') || (ch =='(')){
					//���������ţ���ջ
					Push(S,ch);
				}
				if((ch == '}') || (ch ==']') || (ch ==')')){
					//���������ţ���ջ����ƥ��
					char tmp;
					if(!Pop(S,tmp)){//û�������� 
						flag=0;
					}
					if(!((tmp == '{' && ch == '}') || (tmp == '(' && ch == ')') || (tmp == '[' && ch == ']')))
						flag = 0; //��ƥ�� 
				}
			} 
		} 
		if(flag) cout<<"yes\n";
		else cout<<"no\n";
		clear(S);
	}
	return 0;
}
