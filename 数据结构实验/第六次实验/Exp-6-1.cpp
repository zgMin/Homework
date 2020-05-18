#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct BiTNode {
	char data; //������
	struct BiTNode *lchild, *rchild; //���Һ���ָ����
} BiTNode, *BiTree;
bool flag;	//�ж��Ƿ��Ǵ������� 
int cnt;		//��������ǰ������ 
void create(char a[],char b[],BiTree root,int l,int r){//�����������򴴽��� 
	//a����b����root���ڵ㣬lr����ȷ��������������
	if(!flag) return;
	int pos=0;			//pos�������Ҹ��ڵ������������е�λ�� 
	root->data=a[cnt++];
	while(root->data!=b[pos]){
		pos++;
		if(pos>r){
			flag=0;
			return;
		}
	}
	if(l==r){			//û���������� 
		root->lchild=NULL;
        root->rchild=NULL;
        return ;
	}
	if(l<pos){//�ݹ��������� 
		BiTree l_child=(BiTree)malloc(sizeof(BiTNode)); 
		root->lchild=l_child;
		create(a,b,root->lchild,l,pos-1);
	}
	else root->lchild=NULL;
	
	if(r>pos){//�ݹ��Һ������� 
		BiTree r_child=(BiTree)malloc(sizeof(BiTNode)); 
		root->rchild=r_child;
		create(a,b,root->rchild,pos+1,r);
	}
	else root->rchild=NULL;

	return ;
}
void travel(BiTree root,int order){//order=0����1����2���� 
	if(!root) return;
	switch(order){
		case 0:
			cout<<root->data<<" ";
			travel(root->lchild,order);
			travel(root->rchild,order);
			break;
		case 1:
			travel(root->lchild,order);
			cout<<root->data<<" ";
			travel(root->rchild,order);
			break;
		case 2:
			travel(root->lchild,order);
			travel(root->rchild,order);
			cout<<root->data<<" ";
			break;
		default:break; 
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(true){
		flag=1;
		cnt=0;
		cout<<"��ֱ�������������������������������������"<<endl; 
		char a[20],b[20],c[20];	//a��������b����c����
		BiTree root;
		root=(BiTree)malloc(sizeof(BiTNode)); 
		cin>>a>>b;
		int len=strlen(b);
		create(a,b,root,0,len-1);
		if(!flag){
			cout<<"�������ݣ�"<<endl;
			continue; 
		}
		cout<<"���·ֱ����������򡢺���������У�"<<endl;
		for(int i=0;i<=2;i++){
			travel(root,i);
			cout<<endl;
		}
		
	}	
	return 0;
} 
