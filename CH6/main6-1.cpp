typedef int TElemType;
TElemType Nil=0; // ��������0Ϊ��

#include "c1.h"
#include "c6-1.h"
#include "bo6-1.cpp"


void main()
{
	TElemType e;		//SqBiTree[100] e
	SqBiTree T;

	//�����������ֻ��Ū�˸�ȫ��0�����飬���ڻ�ûʲô���壩
	InitBiTree(T);

	//����������������Ӽ�������ֵ�ˣ�
	CreateBiTree(T);

	//�ж϶������Ƿ�Ϊ�գ�
	BiTreeEmpty(T);		//����ֵΪ1�ǿգ�0�����ǿ�

	//�ж϶�������ȣ���������
	//BiTreeDepth(T);		//����ֵ�������Ĳ���
}