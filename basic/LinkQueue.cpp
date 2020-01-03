#define	FALSE 		0
#define	OK			1
#define	ERROR 		0
#define	INFEASIBLE 	-1
#define	OVERFLOW 	-2
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef int QElemType;
typedef int Status;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr; 

typedef struct{
		QueuePtr front;	//队头指针 
		QuenePtr rear;	//队尾指针 
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front) exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
} 

Status DestroyQueue(LinkQueue &Q){
	while(Q.front){
		p=Q.front->next;
		delete Q.front;
		Q.front=p;
	}//Q.rear=Q.front->next;free(Q.front);Q.front=Q.rear;
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	p=new QNode;
	if(!p)	exit(OVERFLOW);
	p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.rear=Q.front)	return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)	Q.rear=Q.front;
	delete p;
	return OK;
}

Status GetHead(LinkQueue Q,QElemType &e){
	if(Q.front==Q.rear) return ERROR;
	e=Q.front->next->data;
	return OK;
}











