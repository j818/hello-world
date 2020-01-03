#define MAXTSIZE 100;
#define TRUE 		1
#define	FALSE 		0
#define	OK			1
#define	ERROR 		0
#define	INFEASIBLE 	-1
#define	OVERFLOW 	-2
#include<cstdio>
#include<cstdlib>
#include<iostream>
typedef int Status;
typedef int TElemType; 
using namespace std;
typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void visit(BiTree T){
	cout<<T->data<<"\t";
}

Status PreOrderTraverse(BiTree T){
	if(T==NULL)	return OK;	//�ն����� 
	else{
		visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

Status InOrderTraverse(BiTree T){
	if(T==NULL)	return OK;	//�ն����� 
	else{
		InOrderTraverse(T->lchild);
		visit(T);
		InOrderTraverse(T->rchild);
	}
}
/* 
***********��������ķǵݹ��㷨 **************** 
Status InOrderTraverse(BiTree T){
	BiTree p; InitStack(S); p=T;
	while(p||!StackEmpty(S)){
		if(p)	{Push(S,p); p=p->lchild;}
		else {Pop(S,q); cout<<q->data; p=q->rchild;}
	}
	return OK;
}
*/
Status PostOrderTraverse(BiTree T){
	if(T==NULL)	return OK;	//�ն����� 
	else{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T);
	}
}

//���򴴽������� 
Status CreateBiTree(BiTree &T){
	cin>>ch;
	if(ch=="#") T=NULL;
	else{
		if(!(T=new BiNode)) exit(OVERFLOW);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);		
	}
	return OK;
} 

//���ƶ����� 
int Copy(BiTree T,BiTree &NewT){
	if(T==NULL){	//����ǿ������� 
		NewT=NULL; return 0;
	}
	else{
		NewT=new BiNode;
		NewT->data=T->data;
		Copy(T->lchild,NewT->lchild);
		Copy(T->rchild,NewT->rchild);
	}
}

//������������  b
int Depth(BiTree T){
	if(T==NULL) return 0;
	else{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n) return (m+1);
		else return (n+1);
	}
}

//�������������ܸ���
int NodeCount(BiTree T){
	if(T==NULL) return 0;
	else{
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	}
}

//����Ҷ�ӽڵ���
int LeadCount(BiTree T){
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return 1;	//�����Ҷ�ӽڵ㷵��1 
	else{
		return LeadCount(T->lchild)+LeadCount(T->rchild);
	}
}
 






