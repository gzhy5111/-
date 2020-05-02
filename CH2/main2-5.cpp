/*
 * �ļ�����main2-5.cpp
 * ��  �ܣ�����ͷ����˫��ѭ�������������ļ�
 */
typedef int ElemType;
#include "c1.h"
#include "c2-4.h"
#include "bo2-5.cpp"



int main(void)
{
	struct DuLNode *L;
	ListInit(L);

	//ListLength
	printf("������Ϊ��%d\n", ListLength(L));

	//ListInsert(����ͷָ��,pos,ֵ)
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);

	//�����������
	printf("�����������");
	ListTraverse(L);
	
	//�����������
	printf("�����������");
 	ListTraverseBack(L);

	//ListDelete
	ElemType e;
	ListDelete(L, 2, e);
	printf("��ɾ����Ԫ���ǣ�%d\n", e);

	//�п�
	if (ListEmpty(L))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����ǿ�\n");
	}

	//���
	ClearList(L);

	//�п�
	printf("\n��պ������Ƿ�Ϊ�գ�");
	if (ListEmpty(L))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����ǿ�\n");
	}

	//ListInsert
	for (int i = 1; i<=5; i++)
	{
		ListInsert(L, i, i);
	}
	ListTraverse(L);

	//GetElem() ����i��Ԫ�ش���ʱ����ֵ��e1
	ElemType e1;
	GetElem(L,1,e1);
	printf("��1��Ԫ�ص�ֵ�ǣ�%d\n", e1);

	//LocateElem����ֵΪ��3����Ԫ�أ������±꣨��0��ʼ��
	printf("ֵΪ��3����Ԫ�ص��±�Ϊ��%d\n", LocateElem(L, 3));
	
	//ǰ����Ԫ�ء�2��������
	ElemType e2;
	PriorElem(L, 2, e2);
	printf("��2����ǰ��Ԫ���ǣ�%d\n", e2);

	//����
	ElemType e3;
	NextElem(L, 2, e3);
	printf("��2���ĺ���Ԫ���ǣ�%d\n", e3);	

	//����
	DestroyList(L);
	return 0;
}




