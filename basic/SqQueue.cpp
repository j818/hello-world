#define MAXQSIZE 100
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
using namespace std;
typedef int QElemType;
typedef int Status;
//typedef int SElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXQSIZE];
	if(!Q.base) exit(OVERFLOW); 
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q){
	return((Q.rear-Q.front+MAXQSIZE)%MAXQSIZE);
}

Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return OK;		
}

Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.rear==Q.front) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;		
}

QElemType GetHead(SqQueue Q){
	if(Q.rear!=Q.front)	
		return Q.base[Q.front];
}






