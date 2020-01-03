#define MAX_TREE_SIZE 100
typedef struct PTNode{
	TElemType data;
	int parent;
}PTNode;

typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;	//根结点的位置和结点的个数 
}PTree;


