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
typedef int ElemType; 
using namespace std;
#define lIST_INIT_SIZE 100
#define MAXSIZE 1000
typedef struct{
	//数组静态分配 
	//ElemType data[lIST_INIT_SIZE];
	//数组动态分配 
	ElemType *elem;	
	int length;	//当前长度 
}SqList;	//顺序表类型 

Status InitList_Sq(SqList &L){	//构造一个空列表	
	L.elem=new ElemType[MAXSIZE];	//为顺序表分配空间 
	if(!L.elem) exit(OVERFLOW);	//存储分配失败 
	L.length=0;	//空表长度为0 
	return OK;
}

void DestroryList_Sq(SqList &L){
	if(L.elem) delete L.elem;	//释放存储空间 
} 

void ClearList_Sq(SqList &L){
	L.length=0;
}

int GetLength_Sq(SqList L){
	return (L.length);
}

int IsEmpty_Sq(SqList L){
	if(L.length==0) return 1;
	else return 0;
}

int GetElem_Sq(SqList L,int i,ElemType &e){
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}

int LocateElem_Sq(SqList L,ElemType e){
	//在线性表L中查找值为e的数据元素，返回其序号
	for(int i=0;i<L.length;i++)
		if(L.elem[i]==e)	return i+1;
	return 0;
	/*
	int i=0
	while(i<L.length&&L.elem[i]!=e) i++;
	if(i<L.length) return i+1;
	return 0;
	*/
}

Status ListInsert_Sq(SqList &L,int i,ElemType e){
	if(i<1||i>L.length+1) return ERROR;
	if(L.length==MAXSIZE) return ERROR;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	L.length++;
	return OK;
}

Status ListDelete_Sq(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length) return ERROR;
	if(L.length==0) return ERROR;
	e=L.elem[i-1];
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
}

//有序表的合并 
void MergeList_Sq(SqList LA,SqList LB,SqList &LC){
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pa=LA.elem;
	pb=LB.elem;	//指针pa和pb分别指向两个表的第一个元素
	LC.length=LA.length+LB.length;	//新表长度为带合并两表的长度之和		 
	LC.elem=new ElemType[LC.length];	//为合并后的新表分配空间	
	pc=LC.elem;	//指针pc指向新表的第一个元素 
	pa_last=LA.elem+LA.length-1;	//指针pa_last指向LA最后一个元素 
	pb_last=LB.elem+LB.length-1; 	//指针pb_last指向LB最后一个元素
	while(pa<=pa_last&&pb<=pb_last){	//两个表都非空 
		if(*pa<=*pb) *pc++=*pa++;	//依此摘取两表中值较小的结点 
		else *pc++=*pb++;	 
	}
	while(pa<=pa_last) *pc++=*pa++;	//LB表已达到表尾，将LA中剩余元素加入LC 
	while(pb<=pb_last) *pc++=*pb++; //LA表已达到表尾，将LB中剩余元素加入LC
}
/*
int main(){
	SqList L;
	int e;
	InitList_Sq(L);
	ListInsert_Sq(L,1,4);
	ListInsert_Sq(L,2,5);
	ListInsert_Sq(L,3,6);
	ListInsert_Sq(L,4,7);
	ListInsert_Sq(L,5,8);
	ListInsert_Sq(L,6,9);
	ListInsert_Sq(L,2,1);
	ListDelete_Sq(L,4,e);
	int i;
	for(i=0;i<L.length;i++)
		cout<<L.elem[i];	
	return 0;	
}
*/





