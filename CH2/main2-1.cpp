typedef int ElemType;	//��������int��Ϊ������������
#include "c2-1.h"
#include "c1.h"
#include "bo2-1.cpp"

int main(void)
{
	struct sqList L;
	
	//��ʼ��
	InitList(L);
	
	//�������
	for (int j = 1; j <= 5; j++)
	{
		ListInsert(L, 1, j);
	}
	
	for (int i = 0; i<5; i++)
	{
		printf("%5d", L.elem[i]);
	}
	printf("\nlength = %d\n", L.length);

	//�п�
	if (ListEmpty(L))
	{
		printf("Ϊ�գ�\n");
	}

	//���
	ClearList(L);

	//�������
	for (int k = 1; k <= 5; k++)
	{
		ListInsert(L, k, k);
	}
	for (int m = 1; m <= 5; m++)
	{
		printf("%5d", L.elem[m-1]);
	}
	printf("\nlength = %d\n", L.length);

	//��ͷ����Ԫ�ء�0��
	ListInsert(L, 1, 100);
	for (int n = 1; n <= 6; n++)
	{
		printf("%5d", L.elem[n-1]);
	}
	printf("\nlength = %d\n", L.length);
	
	//��ȡĳһ��Ԫ�ص�ֵ
	ElemType e;
	GetElem(L, 2, e);
	printf("�ڶ���Ԫ�ص�ֵΪ��%d\n", e);

	//ǰ��
	ElemType pre_e;
	PriorElem(L, 3, pre_e);
	printf("Ԫ�ء�3����ǰ���ǣ�%d\n", pre_e);

	//���
	ElemType next_e;
	NextElem(L, 3, next_e);
	printf("Ԫ�ء�3���ĺ��Ԫ���ǣ�%d\n", next_e);

	//ɾ��
	ElemType del;
	ListDelete(L, 3, del);
	printf("��ɾ����Ԫ���ǣ�%d\n", del);
	
	//����
	ListTraverse(L);

	//����
	printf("%d\n", locateElem(L, 4));

	//����
	DestroyList(L);
	return 0;
}
