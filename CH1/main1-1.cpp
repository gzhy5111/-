#include "c1.h"
typedef int ElemType;
#include "c1-1.h"
#include "bo1-1.cpp"

void main()
{
	Triplet T;	//T��ָ���������
	//��ʼ��
	InitTriplet(T, 5, 7, 9);
	printf("%d %d %d\n", T[0], T[1], T[2]);

	//Get
	ElemType m;			//int��
	Get(T, 1, m);		//mʹ��������
	printf("�±�Ϊ1��Ԫ���ǣ�%d\n", m);

	//Put
	Put(T, 2, 6);		//���ڶ���ֵ��Ϊ6
	printf("%d %d %d\n", T[0], T[1], T[2]);

	//�ж�����
	if (IsAscending(T))
	{
		printf("����\n");
	}

	//�жϽ���
	if (IsDescending(T))
	{
		printf("����\n");
	}

	//���ֵ
	ElemType max;
	Max(T, max);
	printf("max = %d\n", max);

	//��Сֵ
	ElemType min;
	Min(T, min);
	printf("min = %d\n", min);

	//����
	if (Destroy(T))
	{
		printf("���ٳɹ���\n");
	}
}