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
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S){
	S.base = new SElemType[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}

Status StackEmpty(SqStack S){
	if(S.top==S.base)	return true;
	else return false;
}

int StackLength(SqStack S){
	return S.top-S.base;
}

Status ClearStack(SqStack S){
	if(S.base)	S.top=S.base;
	return OK;
}

Status DestroyStack(SqStack &S){
	if(S.base){
		delete S.base;
		S.stacksize=0;
		S.base=S.top=NULL;
	}
	return OK;
}

Status ClearStack(SqStack S){
	if(S.base)	S.top=S.base;
	return OK;
}

Status Push(SqStack &S,SElemType e){
	if(S.top-S.base==S.stacksize)	//Õ»Âú	
	return ERROR;
	*S.top++=e; 	//=>*S.top=e S.top++
	return OK;
}

Status Pop(SqStack &S,SElemType &e){
	if(S.top=S.base)	//Õ»Âú	
	return ERROR;
	e=--*S.top; 	//=>--S.top e=S.top
	return OK;
}





