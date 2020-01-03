#include<cstdio>
#include<iostream>
#define MinInt 0 //表示有向图极小值 
#define MaxInt 32767 //表示极大值 
#define MVNum 100   //最大顶点数 
#define MAXQSIZE 100
typedef int Status;
typedef int QElemType;
typedef int SElemType;
typedef char VerTexType; //设顶点数据类型为字符型
using namespace std;
bool visited[MVNum];
bool visited2[MVNum];

typedef struct {
	QElemType *base;
	int front;
	int rear;
} SqQueue;

typedef struct ArcNode { //边结点
	int adjvex;	//改变所指向的顶点位置
	struct ArcNode *nextarc; //指向下一条边的指针
	//OtherInfo info; //和相关信息
} ArcNode;

typedef struct VNode { //表头节点
	VerTexType data;
	ArcNode *firstarc;
} VNode,AdjList[MVNum]; //AdjList表示邻接表类型
//AdjList v==VNode v[MVNum]

typedef struct {
	AdjList vertices; //vertex复数
	int vexnum,arcnum; //图当前顶点数和弧数
} ALGraph;

Status InitQueue(SqQueue &Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue &Q,QElemType e);
Status DeQueue(SqQueue &Q,QElemType &e);
SElemType GetHead(SqQueue Q);
bool QueueEmpty(SqQueue Q);
int LocateVex(ALGraph G,int u);
Status CreateUDG(ALGraph &G);
void outdu(ALGraph G);
void DFS(ALGraph G,int v);
void BFS(ALGraph G,int v);
int FirstAdjVex(ALGraph G,int v);
int	NextAdjVex(ALGraph G,int v,int w);
int DFSTraverse(ALGraph G, int v);
int BFSTraverse(ALGraph G, int v);


int main() {
	ALGraph G;
	CreateUDG(G);
	outdu(G);
	DFSTraverse(G,0);
	BFSTraverse(G,0);
	return 0;
}

Status InitQueue(SqQueue &Q) {
	Q.base=new QElemType[MAXQSIZE];
	if(!Q.base) exit(-1);
	Q.front=Q.rear=0;
}

int QueueLength(SqQueue Q) {
	return((Q.rear-Q.front+MAXQSIZE)%MAXQSIZE);
}

Status EnQueue(SqQueue &Q,QElemType e) {
	if((Q.rear+1)%MAXQSIZE==Q.front) return -1;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return 1;
}

Status DeQueue(SqQueue &Q,QElemType &e) {
	if(Q.rear==Q.front) return -1;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return 1;
}

SElemType GetHead(SqQueue Q) {
	if(Q.rear!=Q.front)
		return Q.base[Q.front];
}

bool QueueEmpty(SqQueue Q) {
	if(Q.front!=Q.rear)return false;
	else return true;
}

int LocateVex(ALGraph G,int u) {
	int i;
	for(i=0; i<G.vexnum; i++)
		if(u==G.vertices[i].data) return i;
	return -1;
}
Status CreateUDG(ALGraph &G) { //采用邻接表表示法，创建无向图G
	int i,j;
	char v1,v2;
	cout<<"输入总顶点数，总边数"<<endl;
	cin>>G.vexnum>>G.arcnum;  //输入总顶点数，总边数
	cout<<"输入你所要输入的顶点:"<<endl;
	for(int i=0; i<G.vexnum; ++i) {	//输入各点，构造表头结点表
		cin>>G.vertices[i].data;	//输入顶点值
		G.vertices[i].firstarc=NULL; //初始化表头结点的指针域
	}
	cout<<"输入各边的连接情况"<<endl;
	for(int k=0; k<G.arcnum; ++k) {	//输入各边，构造邻接表
		cin>>v1>>v2;	//输入一条边依附的两个结点
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		ArcNode *p1;
		p1=new ArcNode;	//生成一个新的边结点*p1
		p1->adjvex=j;	//邻接点序号为j
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;	//将新结点*p1插入顶点vi的边表头部
		/*
		p2->adjvex=i;	//邻接点序号为i
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;	//将新结点*p2插入顶点vi的边表头部
		*/
	}
	return 1;
}//CreateUDG

//出度
void outdu(ALGraph G) {
	char x;
	int i;
	cout<<"(出度)请输入你要查找的点："<<endl;
	cin>>x;
	ArcNode *p;
	p=new ArcNode;
	i=LocateVex(G,x);
	int total=0;
	while(G.vertices[i].firstarc!=NULL) {
		total++;
		p=G.vertices[i].firstarc->nextarc;
		G.vertices[i].firstarc=p;
	}
	cout<<"出度为"<<total<<endl;
}

int FirstAdjVex(ALGraph G,int v) {
	ArcNode *p;
	p=new ArcNode;
	p=G.vertices[v].firstarc;
	if(p) {
		return p->adjvex;
	} else {
		return -1;
	}
}

int	NextAdjVex(ALGraph G,int v,int w) {

	if(NULL != G.vertices[v].firstarc) {
		ArcNode *p;
		p=new ArcNode;
		p=G.vertices[v].firstarc;
		while(p!=NULL) {
			if(p->adjvex==w) {
				if(p->nextarc) {
					return p->nextarc->adjvex;
				} else {
					return -1;
				}
			}
			p=p->nextarc;
		}
		return -1;
	} else {
		return -1;
	}
}

void DFS(ALGraph G,int v) {
	visited2[v]=true;
	cout<<G.vertices[v].data<<"->";	//访问第v个顶点
	//VisitFunc(v);
	for(int w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w)) {
		if(!visited2[w]) 	DFS(G,w);
	}
}

int DFSTraverse(ALGraph G, int v) {
	//VisitFunc = Visit;//使用全局变量VisitFunc,使DFS不必设函数指针参数
	for (int v = 0; v < G.vexnum; ++v) {
		visited2[v] = false;
	}
	cout<<"DFS:";
	for (int v = 0; v < G.vexnum; ++v) {
		if (!visited2[v]) {
			DFS(G, v);
		}
	}
	printf("\b\b  \n");
}

void BFS(ALGraph G,int v) {	//按广度优先非递归遍历连通图
	SqQueue Q;
	QElemType u;
	cout<<G.vertices[v].data<<"->";
	visited[v]=true;	//访问第v个顶点
	InitQueue(Q);	//辅助队列Q初始化，置空
	EnQueue(Q,v);	//v进队
	while(!QueueEmpty(Q)) {	//队列非空
		DeQueue(Q,u);	//队头元素出队并置为u
		for(int w=FirstAdjVex(G,u); w>0; w=NextAdjVex(G,u,w))
			if(!visited[w]) {	//w为u的尚未访问的邻接顶点
				cout<<G.vertices[w].data<<"->";
				visited[w]=true;
				EnQueue(Q,w); //w进队
			}
	}
} //BFS

int BFSTraverse(ALGraph G, int v) {
	//VisitFunc = Visit;//使用全局变量VisitFunc,使DFS不必设函数指针参数
	for (int v = 0; v < G.vexnum; ++v) {
		visited[v] = false;
	}
	cout<<"BFS:";
	for (int v = 0; v < G.vexnum; ++v) {
		if (!visited[v]) {
			BFS(G, v);
		}
	}
	printf("\b\b  \n");
}
