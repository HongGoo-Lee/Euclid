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
	printf("안녕하세요. 테스트합시다.\n");
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
	printf("%d초가 걸렸습니다\n", t1);


	time(&start);
	for (i = 0; i < MAX; i++)
	{
		gcd2[i] = euclideRepeatitive(a[i], b[i]);
	}
	time(&fin);
	t2 = fin - start;
	printf("%d초가 걸렸습니다\n", t2);

	for (i = 0; i < MAX; i++)
	{
		printf("%d. 재귀호출: %llu, 반복: %llu\n",i,gcd1[i],gcd2[i]);
		if (gcd1[i] != gcd2[i])
		{
			err_code++;
		}
	}

	if (err_code != 0)
	{
		printf("다른 값이 생겼습니다.\n");
	}

}