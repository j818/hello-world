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

bool visited[MVNum];
bool visited2[MVNum];
Status InitQueue(SqQueue &Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue &Q,QElemType e);
Status DeQueue(SqQueue &Q,QElemType &e);
SElemType GetHead(SqQueue Q);
bool QueueEmpty(SqQueue Q);
int LocateVex(AMGraph G,VerTexType u);
Status CreateUDN(AMGraph &G);
void outdu(AMGraph G);
void indu(AMGraph G);
void DFS(AMGraph G,int v);
int BFS(AMGraph G);
int choose(AMGraph G);
void menu();

int main()
{	
	AMGraph G;
	SqQueue Q;
	int choice;
	InitQueue(Q);
	while(1)
	{
	menu();
	printf("请输入菜单序号：\n");
	scanf("%d",&choice);
	if(choice==6) break;
	switch(choice)
	{
	case 1:CreateUDN(G);break;
	case 2:outdu(G);break;
	case 3:indu(G);break;
	case 4:choose(G);break;
	case 5:BFS(G);break;
	default:printf("输入错误！！！\n");
	}
	}
	return 0;
}


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
	for(k=0;k<G.arcnum;++k){ //构造邻接矩阵 
		cout<<"输入其中一条边所依附的顶点"<<endl;
		cin>>v1>>v2 ;  //>>w	//输入一条边所依附的顶点及边的权值 
		i=LocateVex(G,v1);  
		j=LocateVex(G,v2);	//确定v1 v2在G中的位置 
		G.arcs[i][j]=1;	//w	//边<v1,v2>的权值置为w 		
		//G.arcs[j][i]=G.arcs[i][j];	//置<v1,v2>的对称边<v2,v1>的权值为w 
	}
	cout<<"输入完成"<<endl; 
	for(int i=0;i<G.vexnum;i++) //初始化递归标记数组 
		visited2[i]=false;
	return 1;
}

void outdu(AMGraph G){
	char x;
	int i;
	cout<<"(出度)请输入你要查找的点："<<endl;
	cin>>x;
 	i=LocateVex(G,x);
 	int total=0;
 	for(int j=0;j<G.vexnum;j++)
 		total+=G.arcs[i][j];
	cout<<"出度为"<<total<<endl;
}

void indu(AMGraph G){
	char x;
	int i;
	cout<<"（入度）请输入你要查找的点："<<endl;
	cin>>x;
 	i=LocateVex(G,x);
 	int total=0;
 	for(int j=0;j<G.vexnum;j++)
 		total+=G.arcs[j][i];
	cout<<"入度为"<<total<<endl;
}

void DFS(AMGraph G,int v){	//图G为邻接矩阵类型 
	int w;
	cout<<G.vexs[v]<<"->";visited2[v]=true;	//访问第v个顶点 
	for(w=0;w<G.vexnum;w++)	//依此检查邻接矩阵v所在的行 
		if((G.arcs[v][w]!=0)&&(!visited2[w]))
			DFS(G,w);
		//w是v的邻接点。如果w未访问，则递归调用DFS 
}

int BFS(AMGraph G){
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
	cout<<"\n"<<endl;
}

int choose(AMGraph G){
	char v;
	int x;
	cout<<"请输入当前你想开始搜索的元素："<<endl;
	cin>>v;
	x=LocateVex(G,v);
	cout<<"DFS:";
	DFS(G,x);
	cout<<"\n"<<endl;
}


void menu(){
	printf("********1.初始化邻接矩阵	2.出度*********\n");
   	printf("********3.入度    		4.DFS*********\n");
	printf("********5.BFS    		6.退出*********\n"); 	
}
