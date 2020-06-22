
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<cmath>

#define OK 1
#define ERROR 0

#define m 3 //B-树的阶，暂设为3
#define n 17
using namespace std;

typedef int Status;
typedef int KeyType; 
//B-树结点和树的类型
typedef struct BTNode{
    int keynum;            //结点中关键字个数
    struct BTNode *parent; //指向双亲结点
    KeyType key[m + 1];    //关键字向量，0号单位元未用；
						   //末尾多保留一个空间用于分裂时存放多出的节点； 
						   //实际上也可以用多出的0号位置来存，懒得改了 
    struct BTNode *ptr[m + 1];//子树指针向量
}BTNode, *BTree;
//——end—— 

//B-树的查找结果类型
typedef struct{
    BTNode *pt;    //指向找到的结点
    int i;         //1...m,在结点中的关键字序号
    int tag;       //1:查找成功；0：查找失败 
}Result;
//——end—— 

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
//创建一个队列 
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue *Q, BTree e)
//入队 
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
//出队 
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
//判断是否队空 
{
	if (Q.front == Q.rear)return OK;
	else return ERROR;
}

int Search(BTree p, KeyType k);//在节点p中查找关键字k，返回关键字所在区间的左边界
Result SearchBTree(BTree T, KeyType k);//在树T中查找关键字K的结点，返回查找结果 
Status InsertBTree(BTree &T, KeyType k,BTree q,int pos);//在树T中q节点 pos-pos+1之间插入关键字k 
Status Insert(BTree &q, int pos,KeyType k,BTree ap);//将关键字k和右指针ap插入到q节点的pos-pos+1之间 
Status split(BTree &q,int mid_key, BTree &ap);//分裂节点q，q保留原来的左半段，ap为分裂出去的右半段，mid_key是中间的关键字 
Status NewRoot(BTree &T,KeyType x,BTree ap);//根节点分裂上升产生新的根节点关键字为k，k的左边指针是T，右边是ap 
Status DeleteBTree(BTree &T, BTree node,int pos);//在树T中删除node节点的第pos个关键字 
Status MergeBTree(BTree &T, BTree node);	//合并node与其邻近节点，使T仍是m阶B-树 
Status TraverseBTree(BTree T, LinkQueue Q,int newline,int sum);
void print(BTree T);
void InputKey(BTree &T, KeyType K[]);
Status DeleteKey(BTree &T, KeyType K);

int main(){
	BTree T = NULL;
	Result s;
	KeyType key[n] = { 24, 45, 79, 12, 37, 61, 90, 100, 70, 3, 30, 26, 11, 20, 29, 40, 87 };
	InputKey(T, key);//生成B-树
	cout<<2<<endl;
	KeyType k[4] = { 12, 80, 5, 37 };//查找关键字 
	for (int i = 0; i < 4; i++)
	{
		system("cls");
		printf("%d阶B-树为：", m);
		printf("\n");
		print(T);
		printf("\n");
		printf("查找关键字%d：", k[i]);
		_getch();
		s = SearchBTree(T, k[i]);
		if (s.tag)printf("查找成功！\n");
		else printf("查找失败！\n");
		_getch();
	}
	//删除B-树 
	for (int i = 0; i < n; i++)
	{
		system("cls");
		printf("%d阶B-树为：", m);
		printf("\n");
		print(T);
		printf("\n");
		printf("删除关键字%d\n",key[i]);
		DeleteKey(T, key[i]);
		print(T);
		_getch();
	}
	return 0;
} 

int Search(BTree p, KeyType k){
	int pos=0;//左边界位置 
	for(int i=1; i<=p->keynum; i++){	//遍历查找关键字
		if (p->key[i] <= k)
			pos=i;
		else break;
	}
	return pos;
} 

Result SearchBTree(BTree T, KeyType k){
	BTree p = T, q = NULL;	//p是遍历结点的指针, q是p前驱 
	bool is_found = false;
	Result r;
	int pos=0;

	while (p && (!is_found))
	{
		pos = Search(p, k);//在p结点中中查找关键字k 
		if ((pos > 0) && (p->key[pos] == k))	//找到结点 
			is_found = true;
		else
		{
			q = p; 
			p = p->ptr[pos];
		}
	}
	r.i = pos;
	if (is_found){ r.pt = p; r.tag = 1; }//查找成功
	else { r.pt = q; r.tag = 0; }//查找不成功，返回k的插入位置信息
	return r;
}

Status Insert(BTree &q, int pos,KeyType k,BTree ap){
	int j;
	for (j = q->keynum ; j > pos; --j)
	{
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}									//指针和关键字后移，为插入空出地方 
	q->key[pos + 1] = k;
	q->ptr[pos + 1] =ap;
	q->keynum++; 
	return OK;
}

Status split(BTree &q,int mid_key, BTree &ap){
	ap = (BTree)malloc(sizeof(BTNode));//生成新的结点
	ap->ptr[0] = q->ptr[mid_key];//原来结点中间位置关键字相应指针指向的子树放到
    q->ptr[mid_key]=NULL;        //新生成结点的0棵子树中去
	for (int i = mid_key + 1, j = 1; i <= q->keynum; i++,j++)
	{		//i表示旧节点右半段mid_key+1到keynum段，j表示新节点的对应段 
		ap->key[j] = q->key[i];
		ap->ptr[j] = q->ptr[i];
		q->key[i]=0;q->ptr[i]=NULL;//清空右半段 
	}
	ap->keynum = q->keynum - mid_key;				//修正分裂出去右半段的关键字数 
	ap->parent = q->parent;					//修改ap的双亲指针 
	for (int i = 0; i <= q->keynum - mid_key;i++)
		if (ap->ptr[i])
			ap->ptr[i]->parent = ap;		//修正分裂出去的节点的子树的双亲指针 
	q->keynum = mid_key - 1;						//修正左半段关键字数 
	return OK;
} 

Status NewRoot(BTree &T,KeyType k,BTree ap){
	BTree p;
	p = (BTree)malloc(sizeof(BTNode));	//上升的新根节点 
	p->ptr[0] = T;						//链接左半段 
	p->ptr[1] = ap;						//链接右半段 
	p->parent = NULL;
	p->keynum = 1;
	p->key[1] = k;						//设置新根节点属性 
	T = p;								//更新根节点
	if (T->ptr[0]) 
		T->ptr[0]->parent = T;			
	if (T->ptr[1])
		T->ptr[1]->parent = T;			//修正左右半段双亲指针 ，加判断是为了防止空树 
	return OK;
} 

Status InsertBTree(BTree &T, KeyType k,BTree q,int pos){
	// 插入关键字，若节点过大则进行分裂 
	KeyType x=k;
	bool is_finish = false;		// 判断是否结束 
	BTree ap = NULL;
	int mid_key; 
	while (q&&!is_finish)		
	{	
		Insert(q, pos, x,ap);//将x和ap分别插入到q->key[i+1]和q->ptr[i+1]
		if (q->keynum < m)is_finish=true;//插入完成
		else                              //分裂结点*q
		{
			//将q->key[s+1..m]和q->ptr[s..m]移入新结点*ap
			mid_key = (m + 1) / 2;
			split(q, mid_key, ap);
			x = q->key[mid_key];					//分裂后，待上升的关键字 
			q = q->parent;					//待插入位置上升 
			if (q)							//非根分裂的情况 
			    pos = Search(q, x);//在双亲结点q中查找x的插入位置
		}
	}
	if (!is_finish)//T是空树或者根节点分裂等待上升的情况 
		NewRoot(T, x, ap);
	return OK;
}

Status DeleteBTree(BTree &T, BTree node,int pos){
	//节点过少时，进行合并
	BTree child = node->ptr[pos - 1], orig = node;

	//使用node->ptr[i-1]中最大值替代被删除的关键字
	while (child != NULL)			//不是 叶子的上一层 
	{
		node = child;
		child = node->ptr[child->keynum];
	}
	orig->key[pos] = node->key[node->keynum];

	//处理最底层被删除的关键字
	node->key[node->keynum--] = 0;
	//若引起结点过小，则沿双亲链进行必要的结点合并调整，使T仍是m阶B-树
	if (node->keynum < ceil(m/2.0)-1)
		MergeBTree(T, node);
	return OK; 
} 

Status MergeBTree(BTree &T, BTree node){
	int i = 0, mid = 0, r=0, l=0;
	BTree parent = node->parent, right = NULL, left = NULL;
	
	//node是根结点, 不必进行合并处理 
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

	//查找node为parent的第几个结点
	for (i = 0; i <= parent->keynum; i++){
		if (parent->ptr[i] == node)break;
	}

	if (i > parent->keynum)return ERROR;
	r=i+1, l=i-1;
	if(l>=0){//左兄弟存在 
		left=parent->ptr[l];
		if(left->keynum > ceil(m/2.0)-1){//左边可以在不改变特性前提下送出关键字(以及其最右指针) 
			node->keynum++;
			for(int j=node->keynum; j>0; j--){
				node->key[j]=node->key[j-1];
				node->ptr[j]=node->ptr[j-1];
			}			//为借入关键字（及指针）让出地方 
			node->key[1]=parent->key[i];
			node->ptr[0]=left->ptr[left->keynum]; 
			if(node->ptr[0])
				node->ptr[0]->parent=node;		//修正双亲指针 
			parent->key[i]=left->key[left->keynum]; 
			left->key[left->keynum]=0;			
			left->ptr[left->keynum--]=NULL;			//清空送出的 
			return OK; 
		} 
	}
	if(r <= parent->keynum){//右兄弟存在 
		right=parent->ptr[r];
		if(right->keynum > ceil(m/2.0)-1){//右边可以在不改变特性前提下送出关键字(以及最左指针)
			node->key[++node->keynum]=parent->key[r];
			node->ptr[node->keynum]=right->ptr[0]; 
			if(node->ptr[node->keynum])
				node->ptr[node->keynum]->parent=node;		//修正双亲 
			parent->key[r]=right->key[1];
			right->keynum--;
			for(int j=0; j < right->keynum; j++){
				right->key[j+1]=right->key[j+2];
				right->ptr[j]=right ->ptr[j+1];
			}			//左对齐，补充空缺 
			right->ptr[right->keynum]=NULL;
			return OK; 
		} 
	}
	//以下是左右兄弟均没有富裕关键字的情况
	if(left!=NULL){//有左兄弟 ，合并左兄弟及相应双亲关键字 
		node->keynum=node->keynum+left->keynum+1;
		for(int j=node->keynum; j>=left->keynum+1; j--){
			node->key[j]=node->key[j-(left->keynum+1)];
			node->ptr[j]=node->ptr[j-(left->keynum+1)];
		}			//为合并让出地方 
		
		node->key[left->keynum+1]=parent->key[i];	//相应双亲关键字合并 
		for(int j=0;j<=left->keynum;j++){
			node->ptr[j]=left->ptr[j];
			node->key[j]=left->key[j];
		}											//合并左兄弟
		for(int j=0;j<=node->keynum;j++)
			if(node->ptr[j]!=NULL)
				node->ptr[j]->parent=node;			//修正双亲指针 
		for(int j=l,jj=l+1;j<parent->keynum;j++,jj++){
			parent->ptr[j]=parent->ptr[j+1];
			parent->key[jj]=parent->key[jj+1];
		}
		parent->ptr[parent->keynum]=NULL; 							
		parent->keynum--;				//移位补充双亲空缺 
		free(left);						//清空送出的 
		if(parent->keynum < ceil(m/2.0)-1)		//双亲太小，去合并 
			return MergeBTree(T,parent); 
	} 
	else{			//没左兄弟，合并右兄弟 
		node->key[++(node->keynum)]=parent->key[r];	//相应双亲关键字合并
		for(int j=0,jj=1;j<right->keynum;j++,jj++){
			node->ptr[node->keynum++]=right->ptr[j];
			node->key[node->keynum]=right->key[jj];
		}											
		node->ptr[node->keynum]=right->ptr[right->keynum]; //合并右兄弟
		for(int j=0;j<=node->keynum;j++)
			if(node->ptr[j]!=NULL)
				node->ptr[j]->parent=node;			//修正双亲指针 
		for(int j=r;j<=parent->keynum;j++){
			parent->ptr[j]=parent->ptr[j+1];
			parent->key[j]=parent->key[j+1];
		}
		parent->keynum--;				//移位补充双亲空缺 
		free(right);						//清空送出的 
		if(parent->keynum < ceil(m/2.0)-1)		//双亲太小，去合并 
			return MergeBTree(T,parent); 
	} 
	return OK;
} 

Status TraverseBTree(BTree T, LinkQueue Q,int newline,int sum)
// 初始条件: 动态查找表T存在，Visit是对结点操作的应用函数
// 操作结果: 按关键字的顺序对DT的每个结点调用函数Visit()一次且至多一次
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
			printf("待插入关键字有%d个：\n", n - i -1);
			for (int j = i + 1; j < n; j++)
				printf("%d ", K[j]);
			printf("\n");
			printf("插入关键字%d:", K[i]);
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

