#include <cstdio>
int main()
{
	unsigned long long d[91] = {};
	d[0] = 0;
	d[1] = 1;
	int N;
	scanf("%d", &N);
	for (int i = 2; i <= N; ++i)
		d[i] = d[i - 2] + d[i - 1];
	printf("%lld", d[N]);
}