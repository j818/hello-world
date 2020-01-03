#include<cstdio>
#include<iostream>
#define MAXQSIZE 100
#define MinInt 0 //��ʾ����ͼ��Сֵ 
#define MaxInt 32767 //��ʾ����ֵ 
#define MVNum 100   //��󶥵��� 
typedef int Status;
typedef char VerTexType; //�趥����������Ϊ�ַ��� 
typedef int ArcType; //��ߵ�ȨֵΪ���� 
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
	VerTexType vexs[MVNum];   //�����
	ArcType arcs[MVNum][MVNum]; //�ڽӾ��� 	 
	int vexnum,arcnum;	//ͼ��ǰ�����ͱ��� 
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
//��ͼ�в��Ҷ���u�������򷵻ض�����е��±꣬���򷵻�-1
	int i;
	for(i=0;i<G.vexnum;i++)
	if(u==G.vexs[i]) return i;
	return -1; 
}
Status CreateUDN(AMGraph &G){
	int i,j,k;
	char v1,v2;			//�����ڽӾ����ʾ��	����������G 
	cout<<"�����ܶ��������ܱ���:"<<endl;
	cin>>G.vexnum>>G.arcnum;	//�����ܶ��������ܱ��� 
	cout<<"������������Ϣ:"<<endl;
	for(int i=0;i<G.vexnum;i++){
		cin>>G.vexs[i];  //������������Ϣ
	} 		 
	for(i=0;i<G.vexnum;i++){	//��ʼ���ڽӾ��� 
		for(j=0;i<G.vexnum;i++){
			G.arcs[i][j] = 0;	//�ߵ�Ȩֵ����Ϊ����ֵ }
		}	
	}
	cout<<"000"<<endl	;
	for(k=0;k<G.arcnum;++k){ //�����ڽӾ��� 
		cout<<"��������һ�����������Ķ���"<<endl;
		cin>>v1>>v2 ;  //>>w	//����һ�����������Ķ��㼰�ߵ�Ȩֵ 
		i=LocateVex(G,v1);  
		j=LocateVex(G,v2);	//ȷ��v1 v2��G�е�λ�� 
		G.arcs[i][j]=1;	//w	//��<v1,v2>��Ȩֵ��Ϊw 		
		G.arcs[j][i]=G.arcs[i][j];	//��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw 
	}
	cout<<"�������"<<endl; 
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