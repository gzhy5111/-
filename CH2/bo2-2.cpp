void InitList(struct LNode * &L)
{
	L = (struct LNode *)malloc(sizeof(struct LNode));
	if (L == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	L->next = NULL;
}

void ListInsert(struct LNode * &L, int pos, ElemType e)
{
	//j��*p����ָ��ͷ���
	int j = 0;
	struct LNode *p = L;

	while (p && j<pos-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>pos-1)
	{
		printf("����Ƿ���\n");
		exit(-1);
	}
	//�����½��
	struct LNode *s = (struct LNode *)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void ListTraverse(struct LNode * &L)
{
	struct LNode *p = L->next;			//pָ���һ���ڵ�

	//��p�ƶ�
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

void GetElem(struct LNode * &L, int pos, ElemType& e)
{
	struct LNode *p = L->next;	//ָ���һ�����
	int j = 1;
	while (p !=NULL && j<pos)
	{
		p = p->next;		//��p����j��ת����x�����
		j++;
	}
	e = p->data;
}

bool ListEmpty(struct LNode * &L)
{
	if (L->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void DestoryList(struct LNode * &L)
{
	struct LNode *q;
	while (L != NULL)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ClearList(struct LNode * &L)
{
	struct LNode *p;
	struct LNode *q;
	p = L->next;		//p��ָ���һ�����
	while (p != NULL)
	{
		q = p->next;	//qָ��p����һ�����
		free(p);		
		p = q;			//p����Ų
	}
	L->next = NULL;		//ͷ���ָ��NULL���ص�Init���״̬��
}

void PriorElem(struct LNode * &L, ElemType cur_e, ElemType &pre_e)
{
	struct LNode *p = L->next;		//��ָ���һ�����
	struct LNode *q = p->next;		//qָ��p��һ�����
	while (p->next != NULL)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			pre_e = p->data;
		}
		p = q;	//p����
	}
}

void NextElem(struct LNode * &L, ElemType cur_e, ElemType &next_e)
{
	struct LNode *p = L->next;
	while (p->next != NULL)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

int ListLength(struct LNode * &L)
{
	int i = 0;
	struct LNode *p = L->next;
	while (p != NULL)
	{
		i++;
		p =p->next;
	}
	return i;
}

void ListDelete(struct LNode * &L, int pos, ElemType &e)
{
	int i = 0;
	struct LNode *p = L;
	while (p->next && i<pos-1)
	{
		p = p->next;
		i++;
	}
	if (!p->next || i>pos-1)
	{
		printf("deleteԽ�磡\n");
		exit(-1);
	}
	struct LNode *q = p->next;	//����ɾ���Ľ��ָ�뱣���������Ա��ں����free
	p->next = q->next;
	e = q->data;
	free(q);
}

int locateElem(struct LNode * &L, ElemType e)
{
	int i = 0;						
	struct LNode *p = L->next;	//pָ��ָ���һ�����
	while (p != NULL)
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