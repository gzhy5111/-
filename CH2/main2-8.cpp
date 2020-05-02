/*
 * �ļ�����main2-8.cpp
 * ��  ����������������ͷ���
 */

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-8.cpp"


int main(void)
{
	struct LNode *L;
	
	//��ʼ��
	InitList(L);

	//����
	for (int i = 1; i<=5; i++)
	{
		ListInsert(L, i, i);
	}

	//���
	ClearList(L);

	//�п�
	if (ListEmpty(L))
	{
		printf("Ϊ�գ�\n");
	}
	else
	{
		printf("�ǿգ�\n");
	}

	//ָ��λ�ò���
	for (int j = 1; j<=5; j++)
	{
		ListInsert(L, j, j);
	}
	
	//����
	ListTraverse(L);

	//��2��Ԫ�ص�ֵ
	ElemType e;
	GetElem(L, 2, e);
	printf("��2��Ԫ�ص�ֵΪ��%d\n", e);

	//ǰ��
	ElemType pre_e;
	PriorElem(L, 3, pre_e);
	printf("��3����ǰ��Ԫ���ǣ�%d\n", pre_e);

	//���
	ElemType next_e;
	NextElem(L, 3, next_e);
	printf("��3���ĺ��Ԫ���ǣ�%d\n", next_e);

	//ɾ����2��Ԫ��
	ElemType del;
	ListDelete(L, 2, del);
	printf("��2��Ԫ���Ѿ���ɾ��������ֵ�ǣ�%d\n", del);

	ListTraverse(L);
	
	//locateElem
	ElemType e1;
	printf("ֵΪ4���±�ֵΪ��%d\n", locateElem(L, 4));
	
	//�������Ա�
	DestroyList(L);
	
	return 0;
}