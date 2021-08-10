#include <cstdio>

int main()
{
	int dp[41]{ 0, 1, 1 };
	int T;
	scanf("%d", &T);
	for (int i = 3; i < 41; ++i)
		dp[i] = dp[i - 2] + dp[i - 1];
	
	while (T--)
	{
		int N;
		scanf("%d", &N);
		if (0 == N)
			printf("1 0\n");
		else
			printf("%d %d\n", dp[N-1], dp[N]);
	}
}