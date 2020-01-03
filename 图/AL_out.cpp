#include<cstdio>
#include<iostream>
#define MinInt 0 //��ʾ����ͼ��Сֵ 
#define MaxInt 32767 //��ʾ����ֵ 
#define MVNum 100   //��󶥵��� 
#define MAXQSIZE 100
typedef int Status;
typedef int QElemType;
typedef int SElemType;
typedef char VerTexType; //�趥����������Ϊ�ַ��� 
using namespace std;
bool visited[MVNum];
bool visited2[MVNum];
Status (* VisitFunc)(int v);
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXQSIZE];
	if(!Q.base) exit(-1); 
	Q.front=Q.rear=0;
}

int QueueLength(SqQueue Q){
	return((Q.rear-Q.front+MAXQSIZE)%MAXQSIZE);
}

Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXQSIZE==Q.front) return -1;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return 1;		
}

Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.rear==Q.front) return -1;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return 1;		
}

SElemType GetHead(SqQueue Q){
	if(Q.rear!=Q.front)	
		return Q.base[Q.front];
}

bool QueueEmpty(SqQueue Q)
{
	if(Q.front!=Q.rear)return false;
	else return true;
}
typedef struct ArcNode{ //�߽�� 
	int adjvex;	//�ı���ָ��Ķ���λ�� 
	struct ArcNode *nextarc; //ָ����һ���ߵ�ָ�� 
	//OtherInfo info; //�������Ϣ 
}ArcNode;

typedef struct VNode{ //��ͷ�ڵ� 
	VerTexType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum]; //AdjList��ʾ�ڽӱ����� 
//AdjList v==VNode v[MVNum]

typedef struct{
	AdjList vertices; //vertex����
	int vexnum,arcnum; //ͼ��ǰ�������ͻ��� 
}ALGraph;

int LocateVex(ALGraph G,int u){
	int i;
	for(i=0;i<G.vexnum;i++)
	if(u==G.vertices[i].data) return i;
	return -1; 
} 
Status CreateUDG(ALGraph &G){ //�����ڽӱ��ʾ������������ͼG 
	int i,j;
	char v1,v2;
	cout<<"�����ܶ��������ܱ���"<<endl;
	cin>>G.vexnum>>G.arcnum;  //�����ܶ��������ܱ��� 
	cout<<"��������Ҫ����Ķ���:"<<endl;
	for(int i=0;i<G.vexnum;++i){	//������㣬�����ͷ���� 
		cin>>G.vertices[i].data;	//���붥��ֵ 
		G.vertices[i].firstarc=NULL; //��ʼ����ͷ����ָ���� 
	}
	cout<<"������ߵ��������"<<endl;
	for(int k=0;k<G.arcnum;++k){	//������ߣ������ڽӱ� 
		cin>>v1>>v2;	//����һ����������������� 
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		ArcNode *p1; 
		p1=new ArcNode;	//����һ���µı߽��*p1 
		p1->adjvex=j;	//�ڽӵ����Ϊj 
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;	//���½��*p1���붥��vi�ı߱�ͷ��
	 	/*
	 	p2->adjvex=i;	//�ڽӵ����Ϊi
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;	//���½��*p2���붥��vi�ı߱�ͷ��	
		*/
	}
	return 1;
}//CreateUDG

//���� 
void outdu(ALGraph G){
	char x;
	int i;
	cout<<"(����)��������Ҫ���ҵĵ㣺"<<endl;
	cin>>x;
	ArcNode *p;
	p=new ArcNode;
 	i=LocateVex(G,x);
 	int total=0;
 	while(G.vertices[i].firstarc!=NULL){
		total++;	 
		p=G.vertices[i].firstarc->nextarc;
		G.vertices[i].firstarc=p;	 	
	 }
	cout<<"����Ϊ"<<total<<endl;
}

Status Visit(int v)
{
     printf("%d->", v);
}
int FirstAdjVex(ALGraph G,int v){
	ArcNode *p;
	p=new ArcNode;
	p=G.vertices[v].firstarc;
	if(p)
	{
		return p->adjvex;
	}else
	{
		return -1;
	}
}

int	NextAdjVex(ALGraph G,int v,int w){

	if(NULL != G.vertices[v].firstarc)
	{
		ArcNode *p;
		p=new ArcNode;
		p=G.vertices[v].firstarc;
		while(p!=NULL)
		{
			if(p->adjvex==w)
			{
				if(p->nextarc)
				{
					return p->nextarc->adjvex;
				} 
				else
				{
					return -1;	
				} 
			}
			p=p->nextarc;
		}
		return -1;
	}
	else
	{
		return -1;
	}
} 

void DFS(ALGraph G,int v){
	visited2[v]=true;//cout<<G.vertices[v].data<<"->";	//���ʵ�v������ 
	VisitFunc(v);
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
		{if(!visited[w]) 	DFS(G,w);}
}

void DFSTraverse(ALGraph G,Status (* Visit)(int v)){
	VisitFunc = Visit;
	for (int v = 0; v < G.vexnum; ++v)
    {
         visited2[v] = false;
    }
    for (int v = 0; v < G.vexnum; ++v)
    {
    	if (!visited[v])
     	{
           DFS(G, v);
        }
    }
}

void BFS(ALGraph G,int v){	//��������ȷǵݹ������ͨͼ 
	SqQueue Q;
	QElemType u;
	cout<<"BFS:";
	cout<<G.vertices[v].data<<"->";visited[v]=true;	//���ʵ�v������ 
	InitQueue(Q);	//��������Q��ʼ�����ÿ� 
	EnQueue(Q,v);	//v���� 
	while(!QueueEmpty(Q)){	//���зǿ� 
		DeQueue(Q,u);	//��ͷԪ�س��Ӳ���Ϊu 
		for(int w=FirstAdjVex(G,u);w>0;w=NextAdjVex(G,u,w))
			if(!visited[w]){	//wΪu����δ���ʵ��ڽӶ��� 
				cout<<G.vertices[w].data<<"->";visited[w]=true;
				EnQueue(Q,w); //w���� 
			}
	}
} //BFS 

int main(){
	ALGraph G;
	int v;
	char x;
	CreateUDG(G);
	outdu(G);
	cout<<"������ĸ�Ԫ�ؿ�ʼ������";
	cin>>x;
	v=LocateVex(G,x); 
	cout<<"DFS:";
	//DFS(G,v);
	//cout<<"\n";
	DFSTraverse(G,Visit);
	cout<<"\n";
	BFS(G,v);
	return 0;
}