#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"
#define MAX 1000

void test_euclid()
{
	unsigned long long gcd1[MAX] = { 0 }, gcd2[MAX] = { 0 }, a[MAX] = { 0 }, b[MAX] = { 0 };
	int i = 0, err_code=0, t1=0,t2=0;
	time_t start = 0, fin = 0;
	printf("�ȳ��ϼ���. �׽�Ʈ�սô�.\n");
	srand((unsigned)time(NULL));

	for (i = 0; i < MAX; i++)
	{
		a[i] = rand()+1;
		b[i] = rand()+1;
		a[i] = a[i];
		b[i] = b[i];
	}
	
	time(&start);
	for (i = 0; i < MAX; i++)
	{
		gcd1[i] = euclideRecursive(a[i], b[i]);
	}
	time(&fin);
	t1 = fin - start;
	printf("%d�ʰ� �ɷȽ��ϴ�\n", t1);


	time(&start);
	for (i = 0; i < MAX; i++)
	{
		gcd2[i] = euclideRepeatitive(a[i], b[i]);
	}
	time(&fin);
	t2 = fin - start;
	printf("%d�ʰ� �ɷȽ��ϴ�\n", t2);

	for (i = 0; i < MAX; i++)
	{
		printf("%d. ���ȣ��: %llu, �ݺ�: %llu\n",i,gcd1[i],gcd2[i]);
		if (gcd1[i] != gcd2[i])
		{
			err_code++;
		}
	}

	if (err_code != 0)
	{
		printf("�ٸ� ���� ������ϴ�.\n");
	}

}