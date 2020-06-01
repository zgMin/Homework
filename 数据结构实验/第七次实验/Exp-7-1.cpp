#include<iostream>
#include<cstdlib>
#include<cstdio> 
#define INFINITY INT_MAX //最大值
#define MAX_VERTEX_NUM 20 //最大顶点个数
using namespace std;
int visited[MAX_VERTEX_NUM];//结点是否被访问 
typedef struct ArcNode //表结点类型
{ 
	int adjvex; //边或弧所依附的顶点的位置
	struct ArcNode *nextarc; //指向下一条依附顶点的边或弧的指针
	int w; //边或弧的权值 
} ArcNode;
typedef struct //头结点(数组)类型
{ 
	char data; //顶点信息
	ArcNode *firstarc; //指向第一条依附顶点的边或弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct //图的邻接表类型
{ 
	AdjList vertices; //图的头结点数组
	int vexnum, arcnum; //图的顶点数和边或弧数
	int kind; //图的类型标志
} ALGraph;
int locate(ALGraph G,char data);	//定位元素在表中下标位置 
void G_Create(ALGraph &G,int ctr);	//G图,ctr控制图的类型 
void dfs(ALGraph G,int v,void (*visit)(char));			//深度优先遍历
void bfs(ALGraph G,int v,void (*visit)(char));			//广度优先遍历 
void visit(char data){
	cout<<data<<" ";
	return;
}
int main(){
	ios::sync_with_stdio(false);
	while(true){ 
		ALGraph G;
		cout<<"请输入功能号：\n 1.有向图	2.有向网	3.无向图	4.无向网	0.退出\n";
		int ctr;
		cin>>ctr;
		if(ctr==0) return 0;
		cout<<"请输入结点总数以及边或弧的数量："<<endl;
		cin>>G.vexnum>>G.arcnum;
		G_Create(G,ctr);
		cout<<"dfs序列"<<endl;
		for(int i=0;i<G.vexnum;i++) visited[i]=0;	//清空访问数组 
		dfs(G,0,visit);
		cout<<endl;
		cout<<"bfs序列"<<endl; 
		for(int i=0;i<G.vexnum;i++) visited[i]=0;	//清空访问数组 
        bfs(G,0,visit);
        cout<<endl;
	}
	return 0;
}

int locate(ALGraph G,char data){
	for(int i=0; i<G.vexnum; i++){
		if(G.vertices[i].data==data) return i;
	}
	return -1;//边错误 
} 

void G_Create(ALGraph &G,int ctr){
	cout<<"依次输入"<<G.vexnum<<"个结点的值"<<endl; 
	for(int i=0; i<G.vexnum; i++) {
        char ch;
        cin>>ch;
        G.vertices[i].data = ch;            //头结点的顶点值，
        G.vertices[i].firstarc = NULL;    //firstarc置空 
    }
    cout<<"依次输入"<<G.arcnum<<"个边（a b (c)）"<<endl; 
    char a,b;
    int m,n,c;
    ArcNode *node;
    for(int i=0; i<G.arcnum; i++){
    	node=(ArcNode*)malloc(sizeof(ArcNode));
		cin>>a>>b;
		m=locate(G,a);
		n=locate(G,b);
		if(ctr==2||ctr==4){			//是否有权值 
			cin>>c;
			node->w=c;
		} 
		node->adjvex=n;
		node->nextarc=G.vertices[m].firstarc;	//头插法
		G.vertices[m].firstarc=node;	//后移 
		if(ctr==3){				//是否为无向 
			node=(ArcNode*)malloc(sizeof(ArcNode));
        	node->adjvex = m;
       		node->nextarc = G.vertices[n].firstarc;
        	G.vertices[n].firstarc= node;
        	if(ctr==4)			//无向有权
				 node->w=c; 
		} 
	} 
}

void dfs(ALGraph G,int v,void (*visit)(char)){
	visited[v]=1;	//v打上访问标记
	visit(G.vertices[v].data);	//访问结点v
	ArcNode *p=G.vertices[v].firstarc;
	while(p){
		if(!visited[p->adjvex])		//如果该点未被访问，递归遍历该点 
			 dfs(G,p->adjvex,visit);
		p=p->nextarc;			//下一个邻接点 
	}
	return; 
}

void bfs(ALGraph G,int v,void (*visit)(char)){
	int q[MAX_VERTEX_NUM],front=0,end=0;//q队列，front队首指针，end队尾指针
	visit(G.vertices[v].data);
	visited[v]=1;
	q[end++]=v;//访问出发点并入队
	while(front!=end){//队不空
		 int tmp=q[front++];	//出队 
		 ArcNode *p=G.vertices[tmp].firstarc;
		 while(p){
			if(!visited[p->adjvex]){		//如果该点未被访问，访问该点并入队 
				visit(G.vertices[p->adjvex].data);
				visited[p->adjvex]=1;
				q[end++]=p->adjvex;//入队
			} 
			p=p->nextarc;			//下一个邻接点 
		}
	} 
}
