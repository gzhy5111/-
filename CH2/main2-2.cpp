/*
 * �ļ�����main2-2.cpp
 * ��  ��: ����ͷ���ĵ�����
 */

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"

void main()
{
	struct LNode * L;			//struct LNode *���ͣ�ָ��ͷ�ڵ��ͷָ��
	InitList(L);

	//��ͷ����Ԫ��	

	for (int i = 1; i<=5; i++)
	{
		ListInsert(L, 1, i);		
	}

	//����
	ListTraverse(L);

	//�п�
	if (ListEmpty(L))
	{
		printf("�գ�\n");
	}
	else
	{
		printf("�ǿգ�\n");
	}

	//���
	ClearList(L);
	if (ListEmpty(L))
	{
		printf("�գ�\n");
	}
	else
	{
		printf("�ǿգ�\n");
	}

	//��β����
	for (int j = 1; j<=5; j++)
	{
		ListInsert(L, j, j);
	}
	ListTraverse(L);

	//��ȡָ���±��ӦԪ�ص�ֵ
	ElemType m;
	GetElem(L, 3, m);
	printf("�ڡ�3����Ԫ���ǣ�%d\n", m);

	//ǰ��
	ElemType pre_e;
	//��Ԫ�ء�2����ǰ��Ԫ��
	PriorElem(L, 2, pre_e);
	printf("Ԫ�ء�2����ǰ��Ԫ���ǣ�%d\n", pre_e);
	
	//����
	ElemType next_e;
	NextElem(L, 2, next_e);
	printf("Ԫ�ء�2���ĺ��Ԫ���ǣ�%d\n", next_e);

	//�󳤶�
	printf("��Ϊ��%d\n", ListLength(L));

	//ɾ��ĳ��Ԫ��
	ElemType e;
	//ɾ����2��Ԫ��
	ListDelete(L, 2, e);
	printf("��ɾ����Ԫ���ǣ�%d\n", e);
	ListTraverse(L);
	
	//������L�в���ֵΪ��3����Ԫ��
	printf("ֵΪ��3����Ԫ�ص��±��ǣ�%d\n", locateElem(L, 3));

	//��������
	DestoryList(L);
	ListTraverse(L);
}