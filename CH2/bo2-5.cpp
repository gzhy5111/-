void ListInit(struct DuLNode * &L)
{
	//malloc��������ͷ�ڵ㣬�������Ч����
	L = (struct DuLNode *)malloc(sizeof(struct DuLNode));	//ͷָ��Lָ��ͷ���
	if (L == NULL)
	{
		printf("ListInit malloc�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	L->prior = L->next = L;
}

int ListLength(DuLNode *&L)
{
	int i = 0;
	struct DuLNode *p = L->next;
	while (p != L)
	{
		i++;
		p = p->next;
	}
	return i;
}

//��˫��ѭ�������з��ص�i��Ԫ�صĵ�ַ
DuLNode* GetElemP(struct DuLNode *&L, int pos)
{
	if (pos <0 || pos >ListLength(L))
	{
		printf("GetElemP pos�Ƿ�\n");
		exit(-1);
	}

	//struct DuLNode *p = L->next;	//ָ��ͷ��㣨����Ч��㣩
	struct DuLNode *p = L;
	for (int j = 1; j<=pos; j++)	//��ȷ�������ͻ�һ��ͼ
	{
		p = p->next;
	}
	return p;
}

void ListInsert(struct DuLNode *&L, int pos, ElemType e)
{
	if (pos < 1 || pos > ListLength(L)+1)		//eg����Ϊ2��posֵ����Ϊ3������β��������
	{
		printf("ListInsert pos�Ƿ�");
		exit(-1);
	}

	struct DuLNode *p = GetElemP(L, pos-1);
	if (p == NULL)
	{
		printf("��%d������ǰ��Ԫ�ز�����\n", pos);
		exit(-1);
	}

	struct DuLNode *s = (struct DuLNode *)malloc(sizeof(struct DuLNode));
	if (!s)
	{
		printf("ListInsert�е�malloc��������ʧ�ܣ�\n");
		exit(-1);
	}
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;

}

void ListTraverse(struct DuLNode *&L)
{
	struct DuLNode *p = L->next;	//ָ���׽�㣨��һ����ЧԪ�أ�
	while (p != L)
	{
		printf("%5d", p->data);
		p =p->next;
	}
	printf("\n");
}

void ListTraverseBack(struct DuLNode *&L)
{
	struct DuLNode *p = L->prior;
	while (p != L)
	{
		printf("%5d", p->data);	
		p = p->prior;
	}
	printf("\n");
}

void ListDelete(struct DuLNode *&L, int pos, ElemType &e)
{
	if (pos<0 || pos>ListLength(L))
	{
		printf("ListDelete pos�Ƿ�\n");
		exit(-1);
	}

	struct DuLNode *p = GetElemP(L, pos);		//p��λ��posҪ��ɾ����Ԫ��
	if (!p)
	{
		exit(-1);
	}
	e = p->data;
	//��������������
	p->prior->next = p->next;
	p->next->prior = p->prior;
}

bool ListEmpty(struct DuLNode *&L)
{
	//if (ListLength(L) == 0)
	if (L->prior == L && L->next == L)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClearList(struct DuLNode *&L)
{
	struct DuLNode *q;
	struct DuLNode *p = L->next;	//�׽��
	while (p != L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L->prior = L;
}

void GetElem(struct DuLNode *&L, int pos, ElemType &e1)
{
	int j = 1;		//������
	struct DuLNode *p = L->next;	//�׽��
	while (j<pos && p != L)
	{
		j++;
		p = p->next;
	}
	if (j>pos || p ==L)
	{
		printf("GetElem posֵ���Ϸ�\n");
		exit(-1);
	}
	e1 = p->data;
}

//��ֵΪval��Ԫ�أ������±�
int LocateElem(struct DuLNode *&L, ElemType val)
{
	int i = 0;
	struct DuLNode *p = L->next;
	while (p != L)
	{
		if (val == p->data)
		{
			return i;
		}
		i++;	//���ڼ�¼�±�ֵ
		p = p->next;
	}
	return i;
}

void PriorElem(struct DuLNode *&L, ElemType cur_e, ElemType &pre_e)
{
	struct DuLNode *p = L->next->next;		//����ֱ�Ӵӵڶ�����Ч���ݽ�㿪ʼ���ң���Ϊ�׽��һ��û��ǰ��Ԫ��
	while (p != L)
	{
		if (p->data == cur_e)
		{
			pre_e = p->prior->data;
		}
		p = p->next;
	}
}

void NextElem(struct DuLNode *&L, ElemType cur_e, ElemType &next_e)
{
	struct DuLNode *p = L->next;
	while (p != L)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

void DestroyList(struct DuLNode *&L)
{
	struct DuLNode *q;
	struct DuLNode *p = L->next;	//�׽��
	while (p != L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
	L = NULL;
}