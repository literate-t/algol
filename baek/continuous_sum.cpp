#include <cstdio>
int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N;
	scanf("%d", &N);
	int d[100001] = {};
	int arr[100001] = {};
	int answer = -100000000;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
		d[i] = max(d[i - 1] + arr[i], arr[i]);
		answer = max(d[i], answer);
	}
	printf("%d", answer);
}
/*
* d[i] -> i번째 요소까지의 최대 연속합
* d[i] -> max(d[i-1] + arr[i], d[i-1])
* 
* 10 -4  3 1  5  6  -35  12  21  -1
* 10  6  9 10 15 21 -14  12  33  32
* 
* -1  -2  -3  -4  -5  -6  7   8  -9  -10
* -1  -2  -3  -4  -5  -6  7  15   6  -4* 
*/