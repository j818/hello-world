#include<cstdio>
#include<iostream>
#define MinInt 0 //��ʾ����ͼ��Сֵ 
#define MaxInt 32767 //��ʾ����ֵ 
#define MVNum 100   //��󶥵��� 
typedef int Status;
typedef char VerTexType; //�趥����������Ϊ�ַ��� 
typedef int ArcType; //��ߵ�ȨֵΪ���� 
using namespace std;
typedef struct{
	int visited[MVNum];
	VerTexType vexs[MVNum];   //�����
	ArcType arcs[MVNum][MVNum]; //�ڽӾ��� 	 
	int vexnum,arcnum;	//ͼ��ǰ�����ͱ��� 
}AMGraph;	//Adjacency Matrix Graph 

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
		G.visited[i]=0;
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

void DFS(AMGraph &G,int v){	//ͼGΪ�ڽӾ������� 
	int w;
	cout<<v<<"->";G.visited[v]=true;	//���ʵ�v������ 
	for(w=0;w<G.vexnum;w++)	//���˼���ڽӾ���v���ڵ��� 
		if((G.arcs[v][w]!=0)&&(!G.visited[w]))
			DFS(G,w);
		//w��v���ڽӵ㡣���wδ���ʣ���ݹ����DFS 
}



int main()
{
	AMGraph G;
	CreateUDN(G);
	DFS(G,1) ;
	return 0;
}

