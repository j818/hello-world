#include<cstdio>
#include<iostream>
#define MinInt 0 //��ʾ����ͼ��Сֵ 
#define MaxInt 32767 //��ʾ����ֵ 
#define MVNum 100   //��󶥵��� 
typedef int Status;
typedef char VerTexType; //�趥����������Ϊ�ַ��� 
using namespace std;

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
		/*
		ArcNode *p1; 
		p1=new ArcNode;	//����һ���µı߽��*p1 
		p1->adjvex=j;	//�ڽӵ����Ϊj 
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;	//���½��*p1���붥��vi�ı߱�ͷ��
	 	*/
	 	ArcNode *p2; //����һ���µı߽��*p2 
		p2=new ArcNode;
	 	p2->adjvex=i;	//�ڽӵ����Ϊi
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;	//���½��*p2���붥��vi�ı߱�ͷ��	
		
	}
	return 1;
}//CreateUDG

//��� 
void indu(ALGraph G){
	char x;
	int i;
	cout<<"(���)��������Ҫ���ҵĵ㣺"<<endl;
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
/*
void BFS(ALGraph G,int v){	//��������ȷǵݹ������ͨͼ 
	cout<<v;visited[v]=true;	//���ʵ�v������ 
	InitQueue(Q);	//��������Q��ʼ�����ÿ� 
	EnQueue(Q,v);	//v���� 
	while(!QueueEmpty(Q)){	//���зǿ� 
		DeQueue(Q,u);	//��ͷԪ�س��Ӳ���Ϊu 
		for(w=FirstAdjVex(G,u);w>0;w=NextAdjVex(G,u,w))
			if(!visited[w]){	//wΪu����δ���ʵ��ڽӶ��� 
				cout<<w;visited[w]=true;
				EnQueue(Q,w); //w���� 
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