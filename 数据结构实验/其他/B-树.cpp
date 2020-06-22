
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<cmath>

#define OK 1
#define ERROR 0

#define m 3 //B-���Ľף�����Ϊ3
#define n 17
using namespace std;

typedef int Status;
typedef int KeyType; 
//B-��������������
typedef struct BTNode{
    int keynum;            //����йؼ��ָ���
    struct BTNode *parent; //ָ��˫�׽��
    KeyType key[m + 1];    //�ؼ���������0�ŵ�λԪδ�ã�
						   //ĩβ�ౣ��һ���ռ����ڷ���ʱ��Ŷ���Ľڵ㣻 
						   //ʵ����Ҳ�����ö����0��λ�����棬���ø��� 
    struct BTNode *ptr[m + 1];//����ָ������
}BTNode, *BTree;
//����end���� 

//B-���Ĳ��ҽ������
typedef struct{
    BTNode *pt;    //ָ���ҵ��Ľ��
    int i;         //1...m,�ڽ���еĹؼ������
    int tag;       //1:���ҳɹ���0������ʧ�� 
}Result;
//����end���� 

typedef struct QNode
{
	BTree data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q)
//����һ������ 
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue *Q, BTree e)
//��� 
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, BTree *e)
//���� 
{
	QueuePtr p;
	if (Q->front == Q->rear)return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return OK;
}

Status QueueEmpty(LinkQueue Q)
//�ж��Ƿ�ӿ� 
{
	if (Q.front == Q.rear)return OK;
	else return ERROR;
}

int Search(BTree p, KeyType k);//�ڽڵ�p�в��ҹؼ���k�����عؼ��������������߽�
Result SearchBTree(BTree T, KeyType k);//����T�в��ҹؼ���K�Ľ�㣬���ز��ҽ�� 
Status InsertBTree(BTree &T, KeyType k,BTree q,int pos);//����T��q�ڵ� pos-pos+1֮�����ؼ���k 
Status Insert(BTree &q, int pos,KeyType k,BTree ap);//���ؼ���k����ָ��ap���뵽q�ڵ��pos-pos+1֮�� 
Status split(BTree &q,int mid_key, BTree &ap);//���ѽڵ�q��q����ԭ�������Σ�apΪ���ѳ�ȥ���Ұ�Σ�mid_key���м�Ĺؼ��� 
Status NewRoot(BTree &T,KeyType x,BTree ap);//���ڵ�������������µĸ��ڵ�ؼ���Ϊk��k�����ָ����T���ұ���ap 
Status DeleteBTree(BTree &T, BTree node,int pos);//����T��ɾ��node�ڵ�ĵ�pos���ؼ��� 
Status MergeBTree(BTree &T, BTree node);	//�ϲ�node�����ڽ��ڵ㣬ʹT����m��B-�� 
Status TraverseBTree(BTree T, LinkQueue Q,int newline,int sum);
void print(BTree T);
void InputKey(BTree &T, KeyType K[]);
Status DeleteKey(BTree &T, KeyType K);

int main(){
	BTree T = NULL;
	Result s;
	KeyType key[n] = { 24, 45, 79, 12, 37, 61, 90, 100, 70, 3, 30, 26, 11, 20, 29, 40, 87 };
	InputKey(T, key);//����B-��
	cout<<2<<endl;
	KeyType k[4] = { 12, 80, 5, 37 };//���ҹؼ��� 
	for (int i = 0; i < 4; i++)
	{
		system("cls");
		printf("%d��B-��Ϊ��", m);
		printf("\n");
		print(T);
		printf("\n");
		printf("���ҹؼ���%d��", k[i]);
		_getch();
		s = SearchBTree(T, k[i]);
		if (s.tag)printf("���ҳɹ���\n");
		else printf("����ʧ�ܣ�\n");
		_getch();
	}
	//ɾ��B-�� 
	for (int i = 0; i < n; i++)
	{
		system("cls");
		printf("%d��B-��Ϊ��", m);
		printf("\n");
		print(T);
		printf("\n");
		printf("ɾ���ؼ���%d\n",key[i]);
		DeleteKey(T, key[i]);
		print(T);
		_getch();
	}
	return 0;
} 

int Search(BTree p, KeyType k){
	int pos=0;//��߽�λ�� 
	for(int i=1; i<=p->keynum; i++){	//�������ҹؼ���
		if (p->key[i] <= k)
			pos=i;
		else break;
	}
	return pos;
} 

Result SearchBTree(BTree T, KeyType k){
	BTree p = T, q = NULL;	//p�Ǳ�������ָ��, q��pǰ�� 
	bool is_found = false;
	Result r;
	int pos=0;

	while (p && (!is_found))
	{
		pos = Search(p, k);//��p������в��ҹؼ���k 
		if ((pos > 0) && (p->key[pos] == k))	//�ҵ���� 
			is_found = true;
		else
		{
			q = p; 
			p = p->ptr[pos];
		}
	}
	r.i = pos;
	if (is_found){ r.pt = p; r.tag = 1; }//���ҳɹ�
	else { r.pt = q; r.tag = 0; }//���Ҳ��ɹ�������k�Ĳ���λ����Ϣ
	return r;
}

Status Insert(BTree &q, int pos,KeyType k,BTree ap){
	int j;
	for (j = q->keynum ; j > pos; --j)
	{
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}									//ָ��͹ؼ��ֺ��ƣ�Ϊ����ճ��ط� 
	q->key[pos + 1] = k;
	q->ptr[pos + 1] =ap;
	q->keynum++; 
	return OK;
}

Status split(BTree &q,int mid_key, BTree &ap){
	ap = (BTree)malloc(sizeof(BTNode));//�����µĽ��
	ap->ptr[0] = q->ptr[mid_key];//ԭ������м�λ�ùؼ�����Ӧָ��ָ��������ŵ�
    q->ptr[mid_key]=NULL;        //�����ɽ���0��������ȥ
	for (int i = mid_key + 1, j = 1; i <= q->keynum; i++,j++)
	{		//i��ʾ�ɽڵ��Ұ��mid_key+1��keynum�Σ�j��ʾ�½ڵ�Ķ�Ӧ�� 
		ap->key[j] = q->key[i];
		ap->ptr[j] = q->ptr[i];
		q->key[i]=0;q->ptr[i]=NULL;//����Ұ�� 
	}
	ap->keynum = q->keynum - mid_key;				//�������ѳ�ȥ�Ұ�εĹؼ����� 
	ap->parent = q->parent;					//�޸�ap��˫��ָ�� 
	for (int i = 0; i <= q->keynum - mid_key;i++)
		if (ap->ptr[i])
			ap->ptr[i]->parent = ap;		//�������ѳ�ȥ�Ľڵ��������˫��ָ�� 
	q->keynum = mid_key - 1;						//�������ιؼ����� 
	return OK;
} 

Status NewRoot(BTree &T,KeyType k,BTree ap){
	BTree p;
	p = (BTree)malloc(sizeof(BTNode));	//�������¸��ڵ� 
	p->ptr[0] = T;						//�������� 
	p->ptr[1] = ap;						//�����Ұ�� 
	p->parent = NULL;
	p->keynum = 1;
	p->key[1] = k;						//�����¸��ڵ����� 
	T = p;								//���¸��ڵ�
	if (T->ptr[0]) 
		T->ptr[0]->parent = T;			
	if (T->ptr[1])
		T->ptr[1]->parent = T;			//�������Ұ��˫��ָ�� �����ж���Ϊ�˷�ֹ���� 
	return OK;
} 

Status InsertBTree(BTree &T, KeyType k,BTree q,int pos){
	// ����ؼ��֣����ڵ��������з��� 
	KeyType x=k;
	bool is_finish = false;		// �ж��Ƿ���� 
	BTree ap = NULL;
	int mid_key; 
	while (q&&!is_finish)		
	{	
		Insert(q, pos, x,ap);//��x��ap�ֱ���뵽q->key[i+1]��q->ptr[i+1]
		if (q->keynum < m)is_finish=true;//�������
		else                              //���ѽ��*q
		{
			//��q->key[s+1..m]��q->ptr[s..m]�����½��*ap
			mid_key = (m + 1) / 2;
			split(q, mid_key, ap);
			x = q->key[mid_key];					//���Ѻ󣬴������Ĺؼ��� 
			q = q->parent;					//������λ������ 
			if (q)							//�Ǹ����ѵ���� 
			    pos = Search(q, x);//��˫�׽��q�в���x�Ĳ���λ��
		}
	}
	if (!is_finish)//T�ǿ������߸��ڵ���ѵȴ���������� 
		NewRoot(T, x, ap);
	return OK;
}

Status DeleteBTree(BTree &T, BTree node,int pos){
	//�ڵ����ʱ�����кϲ�
	BTree child = node->ptr[pos - 1], orig = node;

	//ʹ��node->ptr[i-1]�����ֵ�����ɾ���Ĺؼ���
	while (child != NULL)			//���� Ҷ�ӵ���һ�� 
	{
		node = child;
		child = node->ptr[child->keynum];
	}
	orig->key[pos] = node->key[node->keynum];

	//������ײ㱻ɾ���Ĺؼ���
	node->key[node->keynum--] = 0;
	//���������С������˫�������б�Ҫ�Ľ��ϲ�������ʹT����m��B-��
	if (node->keynum < ceil(m/2.0)-1)
		MergeBTree(T, node);
	return OK; 
} 

Status MergeBTree(BTree &T, BTree node){
	int i = 0, mid = 0, r=0, l=0;
	BTree parent = node->parent, right = NULL, left = NULL;
	
	//node�Ǹ����, ���ؽ��кϲ����� 
	if (parent == NULL)
	{
		if (node->keynum == 0)
		{
			if (node->ptr[0] != NULL)
			{
				T = node->ptr[0];
				node->ptr[0]->parent = NULL;
			}
			else {
				T = NULL;
			}
			free(node);
		}
		return OK;
	}

	//����nodeΪparent�ĵڼ������
	for (i = 0; i <= parent->keynum; i++){
		if (parent->ptr[i] == node)break;
	}

	if (i > parent->keynum)return ERROR;
	r=i+1, l=i-1;
	if(l>=0){//���ֵܴ��� 
		left=parent->ptr[l];
		if(left->keynum > ceil(m/2.0)-1){//��߿����ڲ��ı�����ǰ�����ͳ��ؼ���(�Լ�������ָ��) 
			node->keynum++;
			for(int j=node->keynum; j>0; j--){
				node->key[j]=node->key[j-1];
				node->ptr[j]=node->ptr[j-1];
			}			//Ϊ����ؼ��֣���ָ�룩�ó��ط� 
			node->key[1]=parent->key[i];
			node->ptr[0]=left->ptr[left->keynum]; 
			if(node->ptr[0])
				node->ptr[0]->parent=node;		//����˫��ָ�� 
			parent->key[i]=left->key[left->keynum]; 
			left->key[left->keynum]=0;			
			left->ptr[left->keynum--]=NULL;			//����ͳ��� 
			return OK; 
		} 
	}
	if(r <= parent->keynum){//���ֵܴ��� 
		right=parent->ptr[r];
		if(right->keynum > ceil(m/2.0)-1){//�ұ߿����ڲ��ı�����ǰ�����ͳ��ؼ���(�Լ�����ָ��)
			node->key[++node->keynum]=parent->key[r];
			node->ptr[node->keynum]=right->ptr[0]; 
			if(node->ptr[node->keynum])
				node->ptr[node->keynum]->parent=node;		//����˫�� 
			parent->key[r]=right->key[1];
			right->keynum--;
			for(int j=0; j < right->keynum; j++){
				right->key[j+1]=right->key[j+2];
				right->ptr[j]=right ->ptr[j+1];
			}			//����룬�����ȱ 
			right->ptr[right->keynum]=NULL;
			return OK; 
		} 
	}
	//�����������ֵܾ�û�и�ԣ�ؼ��ֵ����
	if(left!=NULL){//�����ֵ� ���ϲ����ֵܼ���Ӧ˫�׹ؼ��� 
		node->keynum=node->keynum+left->keynum+1;
		for(int j=node->keynum; j>=left->keynum+1; j--){
			node->key[j]=node->key[j-(left->keynum+1)];
			node->ptr[j]=node->ptr[j-(left->keynum+1)];
		}			//Ϊ�ϲ��ó��ط� 
		
		node->key[left->keynum+1]=parent->key[i];	//��Ӧ˫�׹ؼ��ֺϲ� 
		for(int j=0;j<=left->keynum;j++){
			node->ptr[j]=left->ptr[j];
			node->key[j]=left->key[j];
		}											//�ϲ����ֵ�
		for(int j=0;j<=node->keynum;j++)
			if(node->ptr[j]!=NULL)
				node->ptr[j]->parent=node;			//����˫��ָ�� 
		for(int j=l,jj=l+1;j<parent->keynum;j++,jj++){
			parent->ptr[j]=parent->ptr[j+1];
			parent->key[jj]=parent->key[jj+1];
		}
		parent->ptr[parent->keynum]=NULL; 							
		parent->keynum--;				//��λ����˫�׿�ȱ 
		free(left);						//����ͳ��� 
		if(parent->keynum < ceil(m/2.0)-1)		//˫��̫С��ȥ�ϲ� 
			return MergeBTree(T,parent); 
	} 
	else{			//û���ֵܣ��ϲ����ֵ� 
		node->key[++(node->keynum)]=parent->key[r];	//��Ӧ˫�׹ؼ��ֺϲ�
		for(int j=0,jj=1;j<right->keynum;j++,jj++){
			node->ptr[node->keynum++]=right->ptr[j];
			node->key[node->keynum]=right->key[jj];
		}											
		node->ptr[node->keynum]=right->ptr[right->keynum]; //�ϲ����ֵ�
		for(int j=0;j<=node->keynum;j++)
			if(node->ptr[j]!=NULL)
				node->ptr[j]->parent=node;			//����˫��ָ�� 
		for(int j=r;j<=parent->keynum;j++){
			parent->ptr[j]=parent->ptr[j+1];
			parent->key[j]=parent->key[j+1];
		}
		parent->keynum--;				//��λ����˫�׿�ȱ 
		free(right);						//����ͳ��� 
		if(parent->keynum < ceil(m/2.0)-1)		//˫��̫С��ȥ�ϲ� 
			return MergeBTree(T,parent); 
	} 
	return OK;
} 

Status TraverseBTree(BTree T, LinkQueue Q,int newline,int sum)
// ��ʼ����: ��̬���ұ�T���ڣ�Visit�ǶԽ�������Ӧ�ú���
// �������: ���ؼ��ֵ�˳���DT��ÿ�������ú���Visit()һ��������һ��
{
	BTree p;
	int i;
	if (T)
	{
		printf("[ ");
		EnQueue(&Q, T->ptr[0]);
		for (i = 1; i <= T->keynum; i++)
		{
			printf("%d ", T->key[i]);
			EnQueue(&Q, T->ptr[i]);
		}
		sum += T->keynum + 1;
		printf("]");
		if (newline == 0)
		{
			printf("\n");
			newline = sum - 1;
			sum = 0;
		}
		else
			--newline;
		if (!QueueEmpty(Q))
		{
			DeQueue(&Q, &p);
			TraverseBTree(p, Q, newline, sum);
		}
	}
	return OK;
}//TraverseBTree

void print(BTree T)
{
	LinkQueue Q;
	if (!T)
	{
		printf("[ ]\n");
		return ;
	}
	InitQueue(&Q);
	TraverseBTree(T, Q, 0, 0);
	return;
}

void InputKey(BTree &T, KeyType K[])
{
	Result s;
	for (int i = 0; i < n; i++)
	{
		s = SearchBTree(T, K[i]); 
		if (!s.tag)
		{
			InsertBTree(T, K[i], s.pt, s.i);
			system("cls");
			printf("������ؼ�����%d����\n", n - i -1);
			for (int j = i + 1; j < n; j++)
				printf("%d ", K[j]);
			printf("\n");
			printf("����ؼ���%d:", K[i]);
			printf("\n");
			print(T);
			_getch();
		}		
	}
}

Status DeleteKey(BTree &T, KeyType K)
{
	int i = 0;
	BTree node = T;
	Result s;

	while (NULL != node)
	{
		s = SearchBTree(T, K);
		node = s.pt;
		i = s.i; 
		if (K == node->key[i])
			return DeleteBTree(T, node, i);
		else if (K < node->key[i])break;
	}
	return OK;
}

