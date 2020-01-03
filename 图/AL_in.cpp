#include<cstdio>
#include<iostream>
#define MinInt 0 //表示有向图极小值 
#define MaxInt 32767 //表示极大值 
#define MVNum 100   //最大顶点数 
typedef int Status;
typedef char VerTexType; //设顶点数据类型为字符型 
using namespace std;

typedef struct ArcNode{ //边结点 
	int adjvex;	//改变所指向的顶点位置 
	struct ArcNode *nextarc; //指向下一条边的指针 
	//OtherInfo info; //和相关信息 
}ArcNode;

typedef struct VNode{ //表头节点 
	VerTexType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum]; //AdjList表示邻接表类型 
//AdjList v==VNode v[MVNum]

typedef struct{
	AdjList vertices; //vertex复数
	int vexnum,arcnum; //图当前顶点数和弧数 
}ALGraph;

int LocateVex(ALGraph G,int u){
	int i;
	for(i=0;i<G.vexnum;i++)
	if(u==G.vertices[i].data) return i;
	return -1; 
} 
Status CreateUDG(ALGraph &G){ //采用邻接表表示法，创建无向图G 
	int i,j;
	char v1,v2;
	cout<<"输入总顶点数，总边数"<<endl;
	cin>>G.vexnum>>G.arcnum;  //输入总顶点数，总边数 
	cout<<"输入你所要输入的顶点:"<<endl;
	for(int i=0;i<G.vexnum;++i){	//输入各点，构造表头结点表 
		cin>>G.vertices[i].data;	//输入顶点值 
		G.vertices[i].firstarc=NULL; //初始化表头结点的指针域 
	}
	cout<<"输入各边的连接情况"<<endl;
	for(int k=0;k<G.arcnum;++k){	//输入各边，构造邻接表 
		cin>>v1>>v2;	//输入一条边依附的两个结点 
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		/*
		ArcNode *p1; 
		p1=new ArcNode;	//生成一个新的边结点*p1 
		p1->adjvex=j;	//邻接点序号为j 
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;	//将新结点*p1插入顶点vi的边表头部
	 	*/
	 	ArcNode *p2; //生成一个新的边结点*p2 
		p2=new ArcNode;
	 	p2->adjvex=i;	//邻接点序号为i
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;	//将新结点*p2插入顶点vi的边表头部	
		
	}
	return 1;
}//CreateUDG

//入度 
void indu(ALGraph G){
	char x;
	int i;
	cout<<"(入度)请输入你要查找的点："<<endl;
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
	cout<<"出度为"<<total<<endl;
}
/*
void BFS(ALGraph G,int v){	//按广度优先非递归遍历连通图 
	cout<<v;visited[v]=true;	//访问第v个顶点 
	InitQueue(Q);	//辅助队列Q初始化，置空 
	EnQueue(Q,v);	//v进队 
	while(!QueueEmpty(Q)){	//队列非空 
		DeQueue(Q,u);	//队头元素出队并置为u 
		for(w=FirstAdjVex(G,u);w>0;w=NextAdjVex(G,u,w))
			if(!visited[w]){	//w为u的尚未访问的邻接顶点 
				cout<<w;visited[w]=true;
				EnQueue(Q,w); //w进队 
			}
	}
} //BFS 
*/
int main(){
	ALGraph G;
	CreateUDG(G);
	indu(G);
	return 0;
}