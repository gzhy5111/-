void InitList(struct LNode *&L)
{
	L = (struct LNode *)malloc(sizeof(struct LNode));
	if (L == NULL)
	{
		printf("InitList malloc����ʧ�ܣ�\n");
		exit(-1);
	}
	L->next = L;		//ͷ���ָ���Լ����γ�ѭ��
}

int ListLength(struct LNode *&L)
{
	struct LNode *p = L->next;	//ָ��ͷ���
	int i = 0;
	while (p != L)
	{
		i++;
		p = p->next;
	}
	return i;
}

void ListInsert(struct LNode * &L, int pos, ElemType e)
{
	struct LNode *p = L->next;	//ָ��ͷ���
	int i = 0;
	if (pos<1 || pos>ListLength(L)+1)
	{
		printf("ListInsert pos�Ƿ���\n");
		exit(-1);
	}
	while (i<pos-1)
	{
		i++;
		p = p->next;
	}
	struct LNode *s = (struct LNode *)malloc(sizeof(struct LNode));
	s->data = e;
	//�ص����
	s->next = p->next;
	p->next = s;
	if (p == L)
	{
		L = s;
	}
}

void ListDelete(struct LNode *&L, int pos, ElemType &e)
{
	struct LNode *p = L->next;	//ָ��ͷ���
	int i = 0;
	if (pos <= 0 || pos>ListLength(L))
	{
		printf("ListDelete posֵ�Ƿ���\n");
		exit(-1);
	}
	//ָ��pͣ�ڵ�pos������ǰ�����
	while (i<pos-1)
	{
		i++;
		p = p->next;
	}
	struct LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	
	//β���
	if (q == L)
	{
		L = p;
	}
	free(q);
}

void ListClear(struct LNode *&L)
{
	//�ص����
	L = L->next;

	struct LNode *p = L->next;
	struct LNode *q;
	while (q != L)
	{
		q = p->next;
		free(p);
		p = q;
	}

	L->next = L;
}

void ListDestroy(struct LNode *&L)
{
	struct LNode *p = L->next;
	struct LNode *q;
	while (p != L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
}

void ListTraverse(struct LNode *&L)
{
	struct LNode *p = L->next->next;
	while (p != L)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("%5d\n", p->data);
}

void PriorElem(struct LNode *&L, ElemType cur_e, ElemType &pre_e)
{
	struct LNode *p = L->next->next;		//��һ�����
	struct LNode *q;
	while (p!= L)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			pre_e = p->data;
		}
		p = p->next;
		p = q;
	}
}

void NextElem(struct LNode *&L, ElemType cur_e, ElemType &next_e)
{
	struct LNode *p = L->next->next;
	while (p != L)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

int locateElem(struct LNode *&L, ElemType e)
{
	struct LNode *p = L->next->next;
	int i = 0;
	while (p != L->next)
	{
		i++;
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}

void GetElem(struct LNode *&L, int pos, ElemType &e)
{
	struct LNode *p = L->next->next;
	int i = 1;
	if (pos <= 0 || pos > ListLength(L))
	{
		printf("GetElem pos�Ƿ���\n");
		exit(-1);
	}
	while (i<pos)
	{
		p = p->next;
		i++;
	}
	e = p->data;
}
