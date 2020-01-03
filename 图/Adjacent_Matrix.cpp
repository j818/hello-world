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
	printf("������˵���ţ�\n");
	scanf("%d",&choice);
	if(choice==6) break;
	switch(choice)
	{
	case 1:CreateUDN(G);break;
	case 2:outdu(G);break;
	case 3:indu(G);break;
	case 4:choose(G);break;
	case 5:BFS(G);break;
	default:printf("������󣡣���\n");
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
	for(k=0;k<G.arcnum;++k){ //�����ڽӾ��� 
		cout<<"��������һ�����������Ķ���"<<endl;
		cin>>v1>>v2 ;  //>>w	//����һ�����������Ķ��㼰�ߵ�Ȩֵ 
		i=LocateVex(G,v1);  
		j=LocateVex(G,v2);	//ȷ��v1 v2��G�е�λ�� 
		G.arcs[i][j]=1;	//w	//��<v1,v2>��Ȩֵ��Ϊw 		
		//G.arcs[j][i]=G.arcs[i][j];	//��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw 
	}
	cout<<"�������"<<endl; 
	for(int i=0;i<G.vexnum;i++) //��ʼ���ݹ������� 
		visited2[i]=false;
	return 1;
}

void outdu(AMGraph G){
	char x;
	int i;
	cout<<"(����)��������Ҫ���ҵĵ㣺"<<endl;
	cin>>x;
 	i=LocateVex(G,x);
 	int total=0;
 	for(int j=0;j<G.vexnum;j++)
 		total+=G.arcs[i][j];
	cout<<"����Ϊ"<<total<<endl;
}

void indu(AMGraph G){
	char x;
	int i;
	cout<<"����ȣ���������Ҫ���ҵĵ㣺"<<endl;
	cin>>x;
 	i=LocateVex(G,x);
 	int total=0;
 	for(int j=0;j<G.vexnum;j++)
 		total+=G.arcs[j][i];
	cout<<"���Ϊ"<<total<<endl;
}

void DFS(AMGraph G,int v){	//ͼGΪ�ڽӾ������� 
	int w;
	cout<<G.vexs[v]<<"->";visited2[v]=true;	//���ʵ�v������ 
	for(w=0;w<G.vexnum;w++)	//���˼���ڽӾ���v���ڵ��� 
		if((G.arcs[v][w]!=0)&&(!visited2[w]))
			DFS(G,w);
		//w��v���ڽӵ㡣���wδ���ʣ���ݹ����DFS 
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
	cout<<"�����뵱ǰ���뿪ʼ������Ԫ�أ�"<<endl;
	cin>>v;
	x=LocateVex(G,v);
	cout<<"DFS:";
	DFS(G,x);
	cout<<"\n"<<endl;
}


void menu(){
	printf("********1.��ʼ���ڽӾ���	2.����*********\n");
   	printf("********3.���    		4.DFS*********\n");
	printf("********5.BFS    		6.�˳�*********\n"); 	
}
