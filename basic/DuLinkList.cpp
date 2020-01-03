typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

void ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	//�ڴ�ͷ�ڵ��˫��ѭ������L�е�i��λ�ò���Ԫ��e 
	if(!(p=GetElemP_DuL(L,i)))	return ERROR;
	s=new DuLNode; s->data=e;
	s->prior=p->prior; p->prior->next=s;
	s->next=p;	p->prior=s;
	return OK;
}

void ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
	//ɾ����ͷ�ڵ��˫��ѭ������L�е�i��Ԫ��,����e���� 
	if(!(p=GetElemP_DuL(L,i)))	return ERROR;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
	return OK;
}



