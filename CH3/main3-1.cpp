//ջ��˳���ʾ��ʵ��
#include "c1.h"
typedef int SElemType;
#include "c3-1.h"
#include "bo3-1.cpp"


void main()
{
	struct SqStack	S;
	//Init
	InitStack(S);

	//Push
	int j = 1;
	Push(S, j);		//���ĸ�ջ����,����ʲôֵ

	//����Push��������
	int k;
	for (k = 2; k <= 12; k++)
	{
		Push(S, k);
	}

	//����
	StackTraverse(S);


	//Pop(ɾ��������)
	int e;	//����ջ��Ԫ��
	Pop(S, e);
	printf("��ɾ����ջ��Ԫ���ǣ�%d\n", e);

	//�п�
	if (StackEmpty(S))
	{
		printf("ջ��\n");
	}
	else
	{
		printf("ջ��Ϊ��\n");
	}

	//��ȡջ��Ԫ��
	GetTop(S, e);
	printf("ջ��Ԫ���ǣ�%d\n", e);

	//ջ����
	StackLength(S);		//ͨ������ֵȡ�ó���
}