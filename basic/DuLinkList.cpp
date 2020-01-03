typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

void ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	//在带头节点的双向循环链表L中第i个位置插入元素e 
	if(!(p=GetElemP_DuL(L,i)))	return ERROR;
	s=new DuLNode; s->data=e;
	s->prior=p->prior; p->prior->next=s;
	s->next=p;	p->prior=s;
	return OK;
}

void ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
	//删除带头节点的双向循环链表L中第i个元素,并用e返回 
	if(!(p=GetElemP_DuL(L,i)))	return ERROR;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
	return OK;
}



