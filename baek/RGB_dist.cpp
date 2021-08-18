#include <cstdio>
#include <algorithm>
int main()
{
	int N;
	scanf("%d", &N);
	int d[1001][3] = { 0 };
	int cost[3] = { 0 };
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d%d%d", &cost[0], &cost[1], &cost[2]);
		d[i][0] = std::min(d[i - 1][1], d[i - 1][2]) + cost[0];
		d[i][1] = std::min(d[i - 1][0], d[i - 1][2]) + cost[1];
		d[i][2] = std::min(d[i - 1][0], d[i - 1][1]) + cost[2];
	}
	printf("%d\n", std::min({ d[N][0], d[N][1], d[N][2] }));
}
/*
* d[N][0] -> N번째 집을 빨간색으로 칠할 때의 총 최소 비용
* -> min(d[N-1][1], d[N-1][1]) + cost[0];
*/