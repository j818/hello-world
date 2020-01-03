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
	//���龲̬���� 
	//ElemType data[lIST_INIT_SIZE];
	//���鶯̬���� 
	ElemType *elem;	
	int length;	//��ǰ���� 
}SqList;	//˳������� 

Status InitList_Sq(SqList &L){	//����һ�����б�	
	L.elem=new ElemType[MAXSIZE];	//Ϊ˳������ռ� 
	if(!L.elem) exit(OVERFLOW);	//�洢����ʧ�� 
	L.length=0;	//�ձ���Ϊ0 
	return OK;
}

void DestroryList_Sq(SqList &L){
	if(L.elem) delete L.elem;	//�ͷŴ洢�ռ� 
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
	//�����Ա�L�в���ֵΪe������Ԫ�أ����������
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

//�����ĺϲ� 
void MergeList_Sq(SqList LA,SqList LB,SqList &LC){
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pa=LA.elem;
	pb=LB.elem;	//ָ��pa��pb�ֱ�ָ��������ĵ�һ��Ԫ��
	LC.length=LA.length+LB.length;	//�±���Ϊ���ϲ�����ĳ���֮��		 
	LC.elem=new ElemType[LC.length];	//Ϊ�ϲ�����±����ռ�	
	pc=LC.elem;	//ָ��pcָ���±�ĵ�һ��Ԫ�� 
	pa_last=LA.elem+LA.length-1;	//ָ��pa_lastָ��LA���һ��Ԫ�� 
	pb_last=LB.elem+LB.length-1; 	//ָ��pb_lastָ��LB���һ��Ԫ��
	while(pa<=pa_last&&pb<=pb_last){	//�������ǿ� 
		if(*pa<=*pb) *pc++=*pa++;	//����ժȡ������ֵ��С�Ľ�� 
		else *pc++=*pb++;	 
	}
	while(pa<=pa_last) *pc++=*pa++;	//LB���Ѵﵽ��β����LA��ʣ��Ԫ�ؼ���LC 
	while(pb<=pb_last) *pc++=*pb++; //LA���Ѵﵽ��β����LB��ʣ��Ԫ�ؼ���LC
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





