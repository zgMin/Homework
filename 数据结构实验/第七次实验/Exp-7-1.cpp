#include<iostream>
#include<cstdlib>
#include<cstdio> 
#define INFINITY INT_MAX //���ֵ
#define MAX_VERTEX_NUM 20 //��󶥵����
using namespace std;
int visited[MAX_VERTEX_NUM];//����Ƿ񱻷��� 
typedef struct ArcNode //��������
{ 
	int adjvex; //�߻��������Ķ����λ��
	struct ArcNode *nextarc; //ָ����һ����������ı߻򻡵�ָ��
	int w; //�߻򻡵�Ȩֵ 
} ArcNode;
typedef struct //ͷ���(����)����
{ 
	char data; //������Ϣ
	ArcNode *firstarc; //ָ���һ����������ı߻򻡵�ָ��
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct //ͼ���ڽӱ�����
{ 
	AdjList vertices; //ͼ��ͷ�������
	int vexnum, arcnum; //ͼ�Ķ������ͱ߻���
	int kind; //ͼ�����ͱ�־
} ALGraph;
int locate(ALGraph G,char data);	//��λԪ���ڱ����±�λ�� 
void G_Create(ALGraph &G,int ctr);	//Gͼ,ctr����ͼ������ 
void dfs(ALGraph G,int v,void (*visit)(char));			//������ȱ���
void bfs(ALGraph G,int v,void (*visit)(char));			//������ȱ��� 
void visit(char data){
	cout<<data<<" ";
	return;
}
int main(){
	ios::sync_with_stdio(false);
	while(true){ 
		ALGraph G;
		cout<<"�����빦�ܺţ�\n 1.����ͼ	2.������	3.����ͼ	4.������	0.�˳�\n";
		int ctr;
		cin>>ctr;
		if(ctr==0) return 0;
		cout<<"�������������Լ��߻򻡵�������"<<endl;
		cin>>G.vexnum>>G.arcnum;
		G_Create(G,ctr);
		cout<<"dfs����"<<endl;
		for(int i=0;i<G.vexnum;i++) visited[i]=0;	//��շ������� 
		dfs(G,0,visit);
		cout<<endl;
		cout<<"bfs����"<<endl; 
		for(int i=0;i<G.vexnum;i++) visited[i]=0;	//��շ������� 
        bfs(G,0,visit);
        cout<<endl;
	}
	return 0;
}

int locate(ALGraph G,char data){
	for(int i=0; i<G.vexnum; i++){
		if(G.vertices[i].data==data) return i;
	}
	return -1;//�ߴ��� 
} 

void G_Create(ALGraph &G,int ctr){
	cout<<"��������"<<G.vexnum<<"������ֵ"<<endl; 
	for(int i=0; i<G.vexnum; i++) {
        char ch;
        cin>>ch;
        G.vertices[i].data = ch;            //ͷ���Ķ���ֵ��
        G.vertices[i].firstarc = NULL;    //firstarc�ÿ� 
    }
    cout<<"��������"<<G.arcnum<<"���ߣ�a b (c)��"<<endl; 
    char a,b;
    int m,n,c;
    ArcNode *node;
    for(int i=0; i<G.arcnum; i++){
    	node=(ArcNode*)malloc(sizeof(ArcNode));
		cin>>a>>b;
		m=locate(G,a);
		n=locate(G,b);
		if(ctr==2||ctr==4){			//�Ƿ���Ȩֵ 
			cin>>c;
			node->w=c;
		} 
		node->adjvex=n;
		node->nextarc=G.vertices[m].firstarc;	//ͷ�巨
		G.vertices[m].firstarc=node;	//���� 
		if(ctr==3){				//�Ƿ�Ϊ���� 
			node=(ArcNode*)malloc(sizeof(ArcNode));
        	node->adjvex = m;
       		node->nextarc = G.vertices[n].firstarc;
        	G.vertices[n].firstarc= node;
        	if(ctr==4)			//������Ȩ
				 node->w=c; 
		} 
	} 
}

void dfs(ALGraph G,int v,void (*visit)(char)){
	visited[v]=1;	//v���Ϸ��ʱ��
	visit(G.vertices[v].data);	//���ʽ��v
	ArcNode *p=G.vertices[v].firstarc;
	while(p){
		if(!visited[p->adjvex])		//����õ�δ�����ʣ��ݹ�����õ� 
			 dfs(G,p->adjvex,visit);
		p=p->nextarc;			//��һ���ڽӵ� 
	}
	return; 
}

void bfs(ALGraph G,int v,void (*visit)(char)){
	int q[MAX_VERTEX_NUM],front=0,end=0;//q���У�front����ָ�룬end��βָ��
	visit(G.vertices[v].data);
	visited[v]=1;
	q[end++]=v;//���ʳ����㲢���
	while(front!=end){//�Ӳ���
		 int tmp=q[front++];	//���� 
		 ArcNode *p=G.vertices[tmp].firstarc;
		 while(p){
			if(!visited[p->adjvex]){		//����õ�δ�����ʣ����ʸõ㲢��� 
				visit(G.vertices[p->adjvex].data);
				visited[p->adjvex]=1;
				q[end++]=p->adjvex;//���
			} 
			p=p->nextarc;			//��һ���ڽӵ� 
		}
	} 
}
