#include<cstdio>
#include<iostream>
#define MAXQSIZE 100
#define MinInt 0 //表示有向图极小值 
#define MaxInt 32767 //表示极大值 
#define MVNum 100   //最大顶点数 
typedef int Status;
typedef char VerTexType; //设顶点数据类型为字符型 
typedef int ArcType; //设边的权值为整型 
using namespace std;
typedef int QElemType;
bool visited[MVNum];
typedef int Status;
typedef int SElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

typedef struct{
	VerTexType vexs[MVNum];   //顶点表
	ArcType arcs[MVNum][MVNum]; //邻接矩阵 	 
	int vexnum,arcnum;	//图当前点数和边数 
}AMGraph;	//Adjacency Matrix Graph 

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

int LocateVex(AMGraph G,VerTexType u){
//在图中查找顶点u，存在则返回顶点表中的下标，否则返回-1
	int i;
	for(i=0;i<G.vexnum;i++)
	if(u==G.vexs[i]) return i;
	return -1; 
}
Status CreateUDN(AMGraph &G){
	int i,j,k;
	char v1,v2;			//采用邻接矩阵表示法	创建无线网G 
	cout<<"输入总顶点数，总边数:"<<endl;
	cin>>G.vexnum>>G.arcnum;	//输入总顶点数，总边数 
	cout<<"依次输入点的信息:"<<endl;
	for(int i=0;i<G.vexnum;i++){
		cin>>G.vexs[i];  //依次输入点的信息
	} 		 
	for(i=0;i<G.vexnum;i++){	//初始化邻接矩阵 
		for(j=0;i<G.vexnum;i++){
			G.arcs[i][j] = 0;	//边的权值均置为极大值 }
		}	
	}
	cout<<"000"<<endl	;
	for(k=0;k<G.arcnum;++k){ //构造邻接矩阵 
		cout<<"输入其中一条边所依附的顶点"<<endl;
		cin>>v1>>v2 ;  //>>w	//输入一条边所依附的顶点及边的权值 
		i=LocateVex(G,v1);  
		j=LocateVex(G,v2);	//确定v1 v2在G中的位置 
		G.arcs[i][j]=1;	//w	//边<v1,v2>的权值置为w 		
		G.arcs[j][i]=G.arcs[i][j];	//置<v1,v2>的对称边<v2,v1>的权值为w 
	}
	cout<<"输入完成"<<endl; 
	return 1;
}

int BFSTraverse(AMGraph G,int x){
	int i,j;
	SqQueue Q;
	for(i=0;i<G.vexnum;i++)
		visited[i]=false;
	InitQueue(Q);
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){
			visited[i]=true;
			cout<<G.vexs[i]<<"->";
			EnQueue(Q,i);
			while(!QueueEmpty(Q)){
				DeQueue(Q,i);
				for(j=0;j<G.vexnum;j++){
					if(G.arcs[i][j]==1&&!visited[j]){
						visited[j]=true;
						cout<<G.vexs[j]<<"->";
						EnQueue(Q,j);
					}
				}
				
			}
		}
	}
}

int main()
{
	AMGraph G;
	CreateUDN(G);
	BFSTraverse(G) ;
	return 0;
}