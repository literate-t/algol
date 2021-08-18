#include <cstdio>
int main()
{
	int d[21] = {};
	int N;

	d[0] = 0;
	d[1] = 1;
	scanf("%d", &N);

	for (int i = 2; i <= N; ++i)
		d[i] = d[i - 1] + d[i - 2];
	printf("%d\n", d[N]);
}
/*
* d[n] = d[n-1] + d[n-2];
*/