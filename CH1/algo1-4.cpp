//exit()���������ã��˳����������
#include "c1.h"

int a(int i)
{
	if (i == 1)
	{
		printf("�˳���������У�\n");
		exit(1);
	}
	return i;
}

int main(void)
{
	int i;
	scanf("%d", &i);
	printf("i = %d\n", a(i));
	return 0;
}