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
	char num[8];	//������ 
	char name[8];	//������ 
	int score;		//������ 
}ElemType;
*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;	//LinkListΪָ��ṹ��Lnode��ָ������
 
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
	while(p){	//û����β 
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;	//ͷ�ڵ�ָ����Ϊ�� 
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
	//�����Ա�L�в���ֵΪe������Ԫ��
	//�ҵ����򷵻�L��ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL 
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;	
}
*/
 
//������L�в���ֵΪe������Ԫ�ص�λ����� 
int LocateElem_L(LinkList L,ElemType e){
//�򷵻�L��ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0 
	LinkList p;
	p=L->next;
	p=L->next;int j=1;
	while(p&&p->data!=e)
	{p=p->next; j++;}
	if(p)	return j;
	else return 0;
} 	

//��L�е�i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert_L(LinkList &L,int i,ElemType e){
	LinkList p,s;
	p=L;int j=0;
	while(p&&j<i-1){	//Ѱ�ҵ�i-1����㣬pָ��i-1���ڵ� 
		p=p->next;++j;	
	}
	if(!p||j>i-1)	return ERROR;	//i���ڱ�+1����С��1������λ�÷Ƿ� 
	s=new LNode; 
	s->data=e;	//�����ɽ��s 
	s->next=p->next;	//��s����L�� 
	p->next=s;
	return OK;
} 

Status ListDelete_L(LinkList &L,int i,ElemType &e){
	LinkList p,q;
	p=L;int j=0;
	while(p->next&&j<i-1){
		p=p->next; ++j;	//Ѱ�ҵ�i����㣬����pָ����ǰ�� 
	}
	if(!(p->next)||j>i-1)	return ERROR;	//ɾ��λ�ò����� 
	q=p->next;	//��ʱ���汻ɾ���ĵ�ַ�ѱ��ͷ� 
	p->next=q->next;	//�ı�ɾ���ڵ�ǰ������ָ���� 
	e=q->data;	//����ɾ���ڵ�������� 
	delete q;	//�ͷ�ɾ���ڵ�Ŀռ� 
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

//�ϲ����Ա� 
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

//�ϲ������
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LinkList pa,pb,pc;
	pa=La->next;pb=Lb->next;
	pc=Lc=La;	//��La��ͷ�����ΪLc��ͷ���
	while(pa&&pb){
		if(pa->data<=pb->data){pc->next=pa; pc=pa; pa=pa->next;}
		else{pc->next=pb; pc=pb; pb=pb->next;}
	}
	pc->next=pa?pa:pb; //����ʣ��� 
	delete Lb; //�ͷ�Lb��ͷ��� 
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
