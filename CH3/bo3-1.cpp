//ջ��˳���ʾ��ʵ��

void InitStack(struct SqStack &S)
{
	S.base = (SElemType *)malloc(20*sizeof(SElemType));
	if (S.base == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	S.top = S.base;
	S.stacksize = 20;
}

void Push(struct SqStack &S, SElemType e)
{
	//�ȸ�ֵ��topԭ��ָ���λ�ÿռ䣬�ٽ�topָ��+1
	*S.top = e;
	S.top = S.top+1;
}

void StackTraverse(struct SqStack &S)
{
	SElemType* p = S.base;
	while (p != S.top)
	{
		printf("%5d", *p);
		p = p + 1;
	}
	printf("\n");
}

void Pop(struct SqStack &S, SElemType &e)
{
	//���ж�ջ�գ����ջΪ���򷵻ش���
	if (S.top == S.base)
	{
		printf("ջΪ�գ�����ɾ��Ԫ��\n");
		exit(-1);
	}
	e = *--S.top;	//�Ⱥ���һ����λ���ٷ���
}

bool StackEmpty(struct SqStack &S)
{
	if (S.top == S.base)
	{
		return 1;	//ջΪ��
	}
	else
	{
		return 0;	//����
	}
}

void GetTop(struct SqStack &S, SElemType &e)
{
	if (S.top == S.base)
	{
		printf("ջ�ǿյ�\n");
		exit(-1);
	}

	S.top = S.top - 1;
	e = *S.top;
}

int StackLength(struct SqStack &S)
{
		
}