void InitList(struct LNode * &L)
{
	L = NULL;
}

void ClearList(struct LNode * &L)
{
	struct LNode *p = L;			//ָ���һ�����
	struct LNode *q;
	while(p->next != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L = NULL;
}

//DestroyList()�������ClearList()һ��������L = NULL
//����д�� #define DestroyList ClearList Ҳ����
void DestroyList(struct LNode * &L)
{
	struct LNode *q;
	while (L->next != NULL)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ListInsert(struct LNode *&L, int pos , ElemType e)
{
	int i = 1;
	struct LNode *p = L;
	if (pos<1)
	{
		printf("ListInsert���Ϸ���\n");
	}

	//�½��
	struct LNode *s = (struct LNode *)malloc(sizeof(LNode));
	s->data = e;
	
	//��ͷ����Ԫ��
	if (pos == 1)			//�ڱ�ͷ֮ǰ����Ԫ��
	{
		L = s;
		L->next = NULL;
	}
	else
	{
		while (p != NULL && i<pos-1)		//��p��λ��posǰ��Ľ��
		{
			p = p->next;
			i++;
		}
		s->next = p->next;
		p->next = s;
	}
}

void ListTraverse(struct LNode * &L)
{
	struct LNode *p = L;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

bool ListEmpty(struct LNode *&L)
{
	if (L == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void GetElem(struct LNode *&L, int pos , ElemType &e)
{
	struct LNode *p = L;
	int i = 1;
	if (i<1)
	{
		printf("Խ�磡\n");
		exit(-1);
	}
	while (i<pos && p)
	{
		i++;
		p = p->next;
	}
	if (i == pos)
	{
		e = p->data;
	}
	else
	{
		printf("δ�ҵ���\n");
	}
}

void PriorElem(struct LNode * &L, ElemType cur_e, ElemType &pre_e)
{
	struct LNode *p = L;
	struct LNode *q;
	while (p->next != NULL)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			pre_e = p->data;
		}
		p = q;
	}
}

void NextElem(struct LNode * &L, ElemType cur_e, ElemType &next_e)
{
	struct LNode *p = L;
	while (p->next != NULL)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

void ListDelete(struct LNode * &L, int pos, ElemType &e)
{
	struct LNode *p = L;
	int i = 1;
	if (pos == 1)
	{
		L = p->next;
		e = p->data;
		free(p);
	}
	else
	{
		while (p->next != NULL && i<pos-1)
		{
			i++;
			p = p->next;
		}
	}
	if (p->next == NULL || i>pos-1)
	{
		printf("ListDeleteλ�÷Ƿ���\n");
		exit(-1);
	}
	struct LNode *q;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
}

int locateElem(struct LNode * &L, ElemType e1)	//�������Ա���ֵΪe1��Ԫ�ز������±�ֵ����������ڷ���false
{
	struct LNode *p = L;
	int i = 1;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
		if (p->data == e1)
		{
			return i;
		}
	}
	return 0;
}

