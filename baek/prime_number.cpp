#include <cstdio>

bool IsPrimeNumber(int num)
{
	if (num <= 1)
	{
		return false;
	}

	for (int i = 2; i*i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		bool result = IsPrimeNumber(num);
		if (true == result)
		{
			++count;
		}
	}
	printf("%d\n", count);
}