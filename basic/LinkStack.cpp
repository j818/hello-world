#define MAXSIZE 100
#define TRUE 		1
#define	FALSE 		0
#define	OK			1
#define	ERROR 		0
#define	INFEASIBLE 	-1
#define	OVERFLOW 	-2
#include<iostream>
#include<cstdio>
#include<cstdlib>
typedef int Status;
typedef int SElemType; 
using namespace std;
typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

void InitStack(LinkStack &S){
	S=NULL;
	return OK;
}

Status StackEmpty(LinkStack S){
	if(S==NULL)	return true;
	else return false;
}

Status Push(LinkStack &S,SElemType e){
	p=new StackNode;
	p->data=e;
	p->next=S;
	S=p;
	return OK;
}

Status Pop(LinkStack &S,SElemType &e){
	if(S==NULL) return ERROR;
	e=S->data;
	p=S;
	S=S>next;
	delete p;
	return OK;
}

SElemType GetTop(LinkStack S){
	if(S!=NULL)	return S->data;
}

