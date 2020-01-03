#include<cstdio>
#include<iostream>
#define MinInt 0 //表示有向图极小值 
#define MaxInt 32767 //表示极大值 
#define MVNum 100   //最大顶点数 
typedef int Status;
typedef char VerTexType; //设顶点数据类型为字符型 
typedef int ArcType; //设边的权值为整型 
using namespace std;
typedef struct{
	int visited[MVNum];
	VerTexType vexs[MVNum];   //顶点表
	ArcType arcs[MVNum][MVNum]; //邻接矩阵 	 
	int vexnum,arcnum;	//图当前点数和边数 
}AMGraph;	//Adjacency Matrix Graph 

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
		G.visited[i]=0;
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

void DFS(AMGraph &G,int v){	//图G为邻接矩阵类型 
	int w;
	cout<<v<<"->";G.visited[v]=true;	//访问第v个顶点 
	for(w=0;w<G.vexnum;w++)	//依此检查邻接矩阵v所在的行 
		if((G.arcs[v][w]!=0)&&(!G.visited[w]))
			DFS(G,w);
		//w是v的邻接点。如果w未访问，则递归调用DFS 
}



int main()
{
	AMGraph G;
	CreateUDN(G);
	DFS(G,1) ;
	return 0;
}

