//���ӽ�� 
typedef struct CTNode{
	int child;
	struct CTNode *next;
}*ChildPtr;

//˫�׽�� 
typedef struct{
	TElemType data;
	ChildPtr firstchild; //��������ͷָ�� 
}CTBox;
