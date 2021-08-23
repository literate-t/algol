#include <cstdio>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	const int MAX = 10001;
	int d[MAX] = {0};
	int w[MAX] = {0};
	int N, answer = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &w[i]);
	d[1] = w[1];
	answer = d[2] = w[1] + w[2];
	for (int i = 3; i <= N; ++i)
	{
		d[i] = max(d[i - 3] + w[i - 1], d[i - 2]) + w[i];
		d[i] = max(d[i - 1], d[i]);
		answer = max(answer, d[i]);
	}
	printf("%d", answer);
}
/*
* d[i] = i번째까지 같이 많이 마실 수 있는 포도주의 양
* d[i] = max(d[i-3] + w[i-1], d[i-2]) + w[i]
* 
* w[i-3] w[i-2] w[i-1] w[i]
* 1 4 100 2
*/