//algo1-3��C++���������ͺͷ��������͵�����
#include "c1.h"

void fa(int n)
{
	n++;
	printf("����fa������n = %d\n", n);
}

void fb(int& n)
{
	n++;
	printf("����fb������n = %d\n", n);
}

int main(void)
{
	int n = 1;
	printf("���������У�δ�����κκ���֮ǰ n = %d\n", n);
	fa(n);
	printf("�������е���fa֮��n = %d\n", n);
	fb(n);
	printf("�������е���fb֮��n = %d\n", n);
	return 0;
}