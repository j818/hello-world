#include "LinkList.cpp"


LinkList CreateListTail(LinkList &L, int n)
{
	LinkList r,p;
	r=L;
	for(int i=0;i<n;++i){
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	r->next=L;
	return r;
} 

LinkList Connect(LinkList Ta,LinkList Tb){
	LNode *p;
	p=new LNode;
	p=Ta->next;
	Ta->next=Tb->next->next;
	delete Tb->next;
	Tb->next=p;
	return Tb;
}

void OutList_Tail(LinkList rear)
{	
	LinkList p=rear->next->next;
	while(p!=rear->next){
		cout<<p->data<<"\t";
		p=p->next;	
	}
}

int main()
{
	LinkList L1,L2,Ta,Tb,Tc;
	InitList_L(L1);
	InitList_L(L2);
	Ta=CreateListTail(L1,5);
	Tb=CreateListTail(L2,6);
	//TraverseLinkList(L1);
	//TraverseLinkList(L2);
	Tc=Connect(Ta,Tb);
	OutList_Tail(Tc);
	return 0;
}
