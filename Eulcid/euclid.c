#include <stdio.h>

//���ȣ��
unsigned long long euclideRecursive(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;
	
	return euclideRecursive(b, a % b);
}

//�ݺ�
unsigned long long euclideRepeatitive(unsigned long long a, unsigned long long b)
{
	unsigned long long temp = 0;
	while (b != 0)
	{
		temp = a;
		a = b;
		b = temp % a;
	}

	return a;
}