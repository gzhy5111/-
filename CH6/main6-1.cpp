typedef int TElemType;
TElemType Nil=0; // ��������0Ϊ��

#include "c1.h"
#include "c6-1.h"
#include "bo6-1.cpp"


void main()
{
	
	SqBiTree T;

	//�����������ֻ��Ū�˸�ȫ��0�����飬���ڻ�ûʲô���壩
	InitBiTree(T);

	//����������������Ӽ�������ֵ�ˣ�
	CreateBiTree(T);

	//�ж϶������Ƿ�Ϊ��
	int empty = 0;
	if (BiTreeEmpty(T))
	{
		empty = 1;
	}
	else 
	{
		empty = 0;
	}
	printf("���������������շ񣿣�1�գ�0����)��%d\n", empty);	//����ֵΪ1�ǿգ�0�����ǿ�

	//�ж϶�������ȣ�������
	printf("������ȣ�%d\n", BiTreeDepth(T));		//����ֵ�������Ĳ���

	// �������ĸ�
	TElemType e;		//SqBiTree[100] e
	Root(T, e);
	printf("���ĸ��ǣ�%d\n", e);

	// ������������������Ǳ������飩
	printf("���������������");
	LevelOrderTraverse(T);

	// �������������������ң���ʹ�õݹ�ʵ��
	printf("���������������");
	InOrderTraverse(T);

	// ������������������Ҹ���
	printf("���������������");
	PostOrderTraverse(T);


	// �޸Ľ�㣬������޸Ľ��Ĳ�ź� �������
	// 1. �ȼ�¼Ҫ�޸Ľ��Ĳ�źͱ������
	position p;
	printf("���������޸ĵĽ��Ĳ�ţ�1��ʼ���ı�����ţ�1��ʼ��,�Կո����ֿ�");
	scanf("%d %d", &p.level, &p.order);
	//printf("%d, %d\n", p.level, p.order);

	// 2. ��ȡԭֵ��¼����ֵ
	// Value�ǻ�ȡֵ�ĺ������ڶ��������ǽ��λ�ýṹ��
	printf("���޸Ľ���ԭֵΪ��%d, ��������ֵ��", Value(T, p));
	int newValue;
	scanf("%d", &newValue);
	// 3. Assign������������, �޸Ľ��λ�ýṹ��, �޸ĺ��ֵ
	Assign(T, p, newValue);
	

	// ��������������������ң�
	printf("���������������");
	PreOrderTraverse(T);

	// ��˫�ס����Ӻ��ֵ�
	printf("������������Ľ���ֵ����������˫�ס����Ӻ��ֵܵ�ֵ��");
	scanf("%d", &e);
	printf("���Ϊ%d��˫��Ϊ%d�� ���Һ��ӷֱ�Ϊ��%d %d�� �����ֱֵܷ�Ϊ��%d %d\n", e, Parent(T, e), LeftChild(T, e), RightChild(T, e), LeftSibling(T, e), RightSibling(T, e));

	// �½��������������������뵽����
	SqBiTree S;
	InitBiTree(S);
	CreateBiTree(S);

	// ������
	int ParentValue, judge;
	printf("��S���뵽��T�У�������T����S��˫�׽���ֵ����Ҫ�����������������߻����ұ��أ���0Ϊ��1Ϊ�ң���������˫�׽���ֵ�������������жϷ����Կո����ֿ�");
	scanf("%d %d", &ParentValue, &judge);
	InsertChild(T, S, ParentValue, judge);
	// �������
	printf("���������������");
	LevelOrderTraverse(T);
}