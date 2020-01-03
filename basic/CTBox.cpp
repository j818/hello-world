//孩子结点 
typedef struct CTNode{
	int child;
	struct CTNode *next;
}*ChildPtr;

//双亲结点 
typedef struct{
	TElemType data;
	ChildPtr firstchild; //孩子链表头指针 
}CTBox;
