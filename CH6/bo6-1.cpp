void InitBiTree(SqBiTree T)			//����յĶ��������������飩
{
	int i;
	for (i = 0; i < 100; i++)
	{
		T[i] = 0;
	}
}

void CreateBiTree(SqBiTree T)
{
	printf("�밴����ȫ�������ķ�ʽ������ֵ���Դ�����������0��ʾ�ս�㣬999��ʾ������");
	int i = 0;
	InitBiTree(T);
	while (1)
	{
		scanf("%d", T[i]);			//����0������ֵ��������������У�����999��
		if (T[i] == 999)
		{
			T[i] = 0;			//��������ֵ��999���͸�Ϊ0����ս��
			break;
		}
		i++;
	}

}

bool BiTreeEmpty(SqBiTree T)
{
	if (T[0] == 0)				//���ڵ�Ϊ0������Ϊ��
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BiTreeDepth(SqBiTree T)
{
	
}

