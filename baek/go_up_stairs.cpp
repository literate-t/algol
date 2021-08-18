#include <cstdio>
#include <algorithm>
int main()
{
	int N;
	scanf("%d", &N);
	int s[301] = { 0 };
	int d[301] = { 0 };
	for (int i = 1; i <= N; ++i)
		scanf("%d", &s[i]);
	d[1] = s[1];
	d[2] = s[1] + s[2];
	d[3] = s[3] + std::max(s[1], s[2]);
	for (int i = 4; i <= N; ++i)
		d[i] = std::max(d[i - 3] + s[i - 1], d[i - 2]) + s[i];
	printf("%d", d[N]);
}
/*
* d[n]은 n번째 계단까지의 점수 최댓값
* n-3 n-2 n-1 n
* d[n-3] + s[n-1] + s[n]
* d[n-2] + s[n]
* 
* d[n] = max(d[n-3] + st[n-2], d[n-1]) + st[i]
* 
*/