/*
 * �ļ�����main2-4.cpp
 * ��  ��������ͷ����βָ��(L)��ʽ�ĵ�ѭ������
 */

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-4.cpp"

int main(void)
{
	struct LNode *L;
	InitList(L);

	//����
	printf("��ѭ������ĳ����ǣ�%d\n", ListLength(L));

	//����
	ListInsert(L, 1, 1);
	printf("��ѭ������ĳ����ǣ�%d\n", ListLength(L));
	ListInsert(L, 1, 2);
	printf("��ѭ������ĳ����ǣ�%d\n", ListLength(L));
	
	//�п�
	if (ListLength(L) == 0)
	{
		printf("Ϊ��\n");
	}
	else
	{
		printf("�ǿգ�\n");
	}

	//���
	ListClear(L);

	//����

	ListInsert(L, 1, 1);	
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);


	//����
	ListTraverse(L);

	//ǰ��
	ElemType pre_e;
	PriorElem(L, 2, pre_e);
	printf("Ԫ��2��ǰ��ֵ�ǣ�%d\n", pre_e);

	//����
	ElemType next_e;
	NextElem(L, 1, next_e);
	printf("Ԫ��1�ĺ��ֵ�ǣ�%d\n", next_e);

	//����
	//�����±�Ϊ1��Ԫ��
	ElemType e0;
	GetElem(L, 2, e0);
	printf("�±�Ϊ2��Ԫ���ǣ�%d\n", e0);

	//ɾ��
	//ɾ����2��Ԫ��
	ElemType e;
	ListDelete(L, 2, e);
	printf("��ɾ����Ԫ���ǣ�%d\n", e);
	ListTraverse(L);

	//��ѯ locateElem
	printf("Ԫ��1���±��ǣ�%d\n", locateElem(L, 1));
	
	//����
	ListDestroy(L);
	return 0;
}