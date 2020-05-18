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
int TreeLeaf(BiTNode *root)
{
    static int num=0;
    if(!root)
    	return num;
    if(root->lchild==NULL && root->rchild==NULL)//������������ 
    	num++;
    TreeLeaf(root->lchild);
    TreeLeaf(root->rchild);
    return num;
}
int TreeDepth(BiTree root){
    int r=0;
    int l=0;
    int deep=0;
    if(!root)
    	return deep;
    r=TreeDepth(root->rchild);//���������������
    l=TreeDepth(root->lchild);//���������������
    deep=r>l ? r+1 : l+1;	//ȡ���ֵ+1 
    return deep;
}
int main(){
	ios::sync_with_stdio(false);
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
		}
		cout<<"������Ҷ�ӽڵ�����������ȣ�"<<endl;
		cout<<TreeLeaf(root)<<endl;
		cout<<TreeDepth(root)<<endl;
	return 0;
} 
