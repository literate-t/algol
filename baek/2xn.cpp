#include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	int d[1001] = {};
	if (1 == n || 2 == n)
		printf("%d\n", n);
	else
	{
		d[1] = 1;
		d[2] = 2;
		for (int i = 3; i <= n; ++i)
			d[i] = (d[i - 1] + d[i - 2]) % 10007;
		printf("%d\n", d[n]);
	}	
}
/*
* d[n] -> 2 x n을 타일로 채우는 방법 수
*	   -> d[n-1] + d[n-2]
*/