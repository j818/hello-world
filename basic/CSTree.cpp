typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;

/*
兄弟节点 兄弟节点之间连一条线
树变二叉树：
兄弟相连留长子 

二叉树变树:
左孩右右连双亲
去点原来右连线 

森林变二叉树：
树变二叉根相连 

二叉树变森林：
去掉全部右孩线，孤立二叉再还原 
*/
 
