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
/*
typedef struct{
	char num[8];	//数据域 
	char name[8];	//数据域 
	int score;		//数据域 
}ElemType;
*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;	//LinkList为指向结构体Lnode的指针类型
 
Status InitList_L(LinkList &L){
	L=new LNode;
	L->next=NULL;
	return OK;
}

int ListEmpty_L(LinkList L){
	if(L->next)	return 0;
	else	return 1;
}

Status DestoryList_L(LinkList &L){
	LNode *p;
	while(L){
		p=L;
		L=L->next;
		delete p;
	}
	return OK;
}

Status ClearList_L(LinkList &L){
	LNode *p,*q;
	p=L->next;
	while(p){	//没到表尾 
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;	//头节点指针域为空 
	return OK;
}

int ListLength_L(LinkList L){
	LinkList p;
	p=L->next;
	int i=0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
} 

Status GetElem_L(LinkList L,int i,ElemType &e){
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&j<i){
		p=p->next; ++j;
	}
	if(!p||j>i)	return ERROR;
	e=p->data;
	return OK;
}

/* 
LNode *LocateElem_L(LinkList L;ElemType e){
	//在线性表L中查找值为e的数据元素
	//找到，则返回L中值为e的数据元素的地址，查找失败返回NULL 
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;	
}
*/
 
//在线性L中查找值为e的数据元素的位置序号 
int LocateElem_L(LinkList L,ElemType e){
//则返回L中值为e的数据元素的位置序号，查找失败返回0 
	LinkList p;
	p=L->next;
	p=L->next;int j=1;
	while(p&&p->data!=e)
	{p=p->next; j++;}
	if(p)	return j;
	else return 0;
} 	

//在L中第i个元素之前插入数据元素e
Status ListInsert_L(LinkList &L,int i,ElemType e){
	LinkList p,s;
	p=L;int j=0;
	while(p&&j<i-1){	//寻找第i-1个结点，p指向i-1个节点 
		p=p->next;++j;	
	}
	if(!p||j>i-1)	return ERROR;	//i大于表长+1或者小于1，插入位置非法 
	s=new LNode; 
	s->data=e;	//新生成结点s 
	s->next=p->next;	//将s插入L中 
	p->next=s;
	return OK;
} 

Status ListDelete_L(LinkList &L,int i,ElemType &e){
	LinkList p,q;
	p=L;int j=0;
	while(p->next&&j<i-1){
		p=p->next; ++j;	//寻找第i个结点，并令p指向其前驱 
	}
	if(!(p->next)||j>i-1)	return ERROR;	//删除位置不合理 
	q=p->next;	//临时保存被删结点的地址已备释放 
	p->next=q->next;	//改变删除节点前驱结点的指针域 
	e=q->data;	//保存删除节点的数据域 
	delete q;	//释放删除节点的空间 
	return OK;
}

void CreateList_H(LinkList &L,int n){
	for(int i=n;i>0;--i){
		LNode *p;
		p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

void CreateList_R(LinkList &L,int n){
	LinkList r,p;
	//r=new LNode;
	r=L;
	for(int i=0;i<n;++i){
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

void TraverseLinkList_L(LinkList L){
	LNode *p;
	p=new LNode;
	p=L;
	while(p->next){
		p=p->next;	
		cout<<p->data<<"\t";
	}
}

//合并线性表 
void union_L(LinkList &La,LinkList Lb){
	int La_len=ListLength_L(La);
	int Lb_len=ListLength_L(Lb);
	ElemType e;
	for(int i=1;i<=Lb_len;i++){
		GetElem_L(Lb,i,e);
		if(!LocateElem_L(La,e))
			ListInsert_L(La,++La_len,e);
	} 
}

//合并有序表
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LinkList pa,pb,pc;
	pa=La->next;pb=Lb->next;
	pc=Lc=La;	//用La的头结点作为Lc的头结点
	while(pa&&pb){
		if(pa->data<=pb->data){pc->next=pa; pc=pa; pa=pa->next;}
		else{pc->next=pb; pc=pb; pb=pb->next;}
	}
	pc->next=pa?pa:pb; //插入剩余段 
	delete Lb; //释放Lb的头结点 
}  
/*
int main(){
	LinkList L;
	InitList_L(L);
	CreateList_R(L,5);
	cout<<ListLength_L(L);
	TraverseLinkList(L);
	ListInsert_L(L,2,99);
	cout<<"\n";
	TraverseLinkList(L);
	return 0;
}
*/
