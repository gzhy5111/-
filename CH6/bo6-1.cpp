// ����յĶ��������������飩
void InitBiTree(SqBiTree T)			
{
	int i;
	for (i = 0; i < 100; i++)
	{
		T[i] = 0;
	}
}

// ����������
void CreateBiTree(SqBiTree T)
{
	printf("�밴����ȫ�������ķ�ʽ������ֵ���Դ�����������0��ʾ�ս�㣬999��ʾ������");
	int i = 0;
	InitBiTree(T);
	while (1)
	{
		scanf("%d", &T[i]);			//����0������ֵ��������������У�����999��
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

// �����������
int BiTreeDepth(SqBiTree T)
{
	// �������һ���������
	int i;
	for (i = 100-1; i >= 0; i--)
	{
		// ���һ����Ч���
		if (T[i] != 0)
		{
			break;
		}
	}
	// ���ڵõ������һ����Ч������ţ��������Ǵ�0��ʼ��
	i = i + 1;
	// �������
	int j = 0;			// j�����������
	do
	{
		j++;
	} while (i >= pow(2, j));
	return j;
}

void Root(SqBiTree T, TElemType &b)
{
	// ��Ϊ�գ������ڸ����
	if (BiTreeEmpty(T))
	{
		exit(-1);
	}
	else
	{
		b = T[0];
	}
}

// �������������
void LevelOrderTraverse(SqBiTree T)
{
	for (int i = 0; i < 100; i++)
	{
		if (T[i] != 0)
		{
			printf("%5d", T[i]);
		}
	}
	printf("\n");
}

// ����ұ���
void InTraverse(SqBiTree T, int i)
{	
	// �ݹ�ʵ��
	if (T[2*i+1] != 0)			// ��������Ϊ��
	{
		InTraverse(T, 2*i+1);
	}
	printf("%5d", T[i]);			// ��
	if (T[2*i+2] != 0)
	{
		InTraverse(T, 2*i+2);	//��������Ϊ��
	}
	
}

// �������������������ң�
void InOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		// ����ұ���
		InTraverse(T, 0);
	}
	printf("\n");
}

// ���Ҹ�����
void PostTravese(SqBiTree T, int i)
{
	if (T[2*i+1] != 0)			// ��������Ϊ��
	{
		PostTravese(T, 2*i+1);
	}
	if (T[2*i+2] != 0)
	{
		PostTravese(T, 2*i+2);	//��������Ϊ��
	}
	printf("%5d", T[i]);			// ��
}

// ������������������Ҹ���
void PostOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		// ���Ҹ�����
		PostTravese(T, 0);
	}
	printf("\n");
}

// Value�ǻ�ȡֵ�ĺ������ڶ��������ǽ��λ�ýṹ��
TElemType Value(SqBiTree T, position p)
{
	return T[int(pow(2, p.level-1) + p.order-2)];
}

// Assign������������, �޸Ľ��λ�ýṹ��, �޸ĺ��ֵ
void Assign(SqBiTree T, position p, TElemType newValue)
{
	int i = (pow(2, p.level-1)) + p.order-2;	// ת��Ϊ���ֵ����0��ʼ������
	// ע�⣺����ֱ�Ӹ�ֵ��Ҫ��������û�и��ڵ�����
	// ���һ����ֵ���ǡ�0������˫��Ϊ�ա����������߼�
	if (newValue != 0 && T[(i+1)/2-1] == 0)
	{
		printf("���һ����\n");
		exit(-1);
	}
	// �������Ҫ����ֵΪ0��˵�������к��ӣ���Ҫ��֤���Ӳ��ܴ��ڲ���
	if (newValue ==0 && (T[i*2+1] || T[i*2+2]))
	{
		printf("���������\n");
		exit(-1);	
	}
	T[i] = newValue;
}

// �����ұ���
void PreTravese(SqBiTree T, int i)
{
	printf("%5d", T[i]);		// ��
	if (T[2*i+1] != 0)			// ��������Ϊ��
	{
		PreTravese(T, 2*i+1);
	}
	if (T[2*i+2] != 0)
	{
		PreTravese(T, 2*i+2);	//��������Ϊ��
	}
}

// ��������������������ң�
void PreOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		// �����ұ���
		PreTravese(T, 0);
	}
	printf("\n");
}

// e����ֵ��������ֵ��˫�׽���ֵ
int Parent(SqBiTree T, TElemType e)
{
	// ����
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e)
		{
			// ����˫�׽���ֵ
			return T[(i+1)/2-1];
		}
	}
	// ���û���ҵ�e�򷵻�0
	return 0;
} 

// ����ֵ�������ӵ�ֵ
int LeftChild(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e)
		{
			// �������ӵ�ֵ
			return T[i*2+1];
		}
	}
	// ���û���ҵ�e�򷵻�0
	return 0;
}

int RightChild(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e)
		{
			// �����Һ��ӵ�ֵ
			return T[i*2+2];
		}
	}
	// ���û���ҵ�e�򷵻�0
	return 0;
}

// ����ֵ�����ֵܵ�ֵ
int LeftSibling(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e && i%2 == 0)
		{
			// �������ֵܵ�ֵ
			// ͨ���۲�ɷ��֣�������ŵĽ��ֻ�����ֵܣ�����ֻ��һ�������ֵܲ��㣩��ż����ŵĽ��ֻ�����ֵܣ����ֲ����ұ��Ϊ0�Ľ�����⣬��û���ֵܣ�
			return T[i-1];
		}
	}
	// ���û���ҵ�e�򷵻�0
	return 0;
}

int RightSibling(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e && i%2 != 0)
		{
			// �������ֵܵ�ֵ
			// ͨ���۲�ɷ��֣�������ŵĽ��ֻ�����ֵܣ�����ֻ��һ�������ֵܲ��㣩��ż����ŵĽ��ֻ�����ֵܣ����ֲ����ұ��Ϊ0�Ľ�����⣬��û���ֵܣ�
			return T[i+1];
		}
	}
	// ���û���ҵ�e�򷵻�0
	return 0;
}

// �ƶ���
// �Ѵ�q��j��㿪ʼ�������ƶ���T��i��㿪ʼ������
void Move(SqBiTree q, int j, SqBiTree T, int i)
{
	// �����������Ϊ��
	if (q[j*2+1] != 0)
	{
		Move(q, j*2+1, T, i*2+1);
	}
	// �����������Ϊ��
	if (T[j*2+2] != 0)
	{
		Move(q, j*2+2, T, i*2+2);
	}
	T[i] = q[j];
	q[j] = 0;
}

// ������
void InsertChild(SqBiTree T, SqBiTree C, int ParentValue, int judge)
{
	// ����ֵΪParentValue�ı��
	int i;			// ����i���˫�׽��ı��
	for (i = 0; i < pow(2, BiTreeDepth(T))-1; i++)
	{
		if (T[i] == ParentValue)
		{
			break;
		}
	}
	// ��������Ҫ�ж�˫�׽�㱾�������Ӻ��Һ����Ƿ����
	// ���ڵĻ������λ�ò����ʣ�����Ҫ���������ҵ�����
	int childIndex = (2*i+1) + judge;		// �����������2*i+1���Һ�����2*i+2������ͨ��Judge������
	//�������ռ��λ�ã�����Ҫ�������ҵ���
	if (T[childIndex] != 0)
	{
		// �Ѵ�T��childIndex��ʼ�Ľ���������ռλ�õ������ƶ�����childIndex������������ʼ������
		Move(T, childIndex, T, childIndex*2+2);
	}
	// ��֮ǰ���µ����������ߺ����ھͿ��Բ���������
	// �ڶ�������0��ʾ��������ȫ�����롱
	Move(C, 0, T, childIndex);
}