#include <cstdio>
int main()
{
	int d[1001] = {};
	int seq[1001] = {};
	int N;
	scanf("%d", &N);
	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		int prev = 0;
		scanf("%d", &seq[i]);
		for (int j = 1; j < i; ++j)
			if (seq[i] > seq[j])
				prev = prev < d[j] ? d[j] : prev;
		d[i] = prev + 1;
		max = max < d[i] ? d[i] : max;
	}
	printf("%d", max);
}
/*
* d[i] -> i번째 원소를 마지막으로 하는 수열의 수
* d[i] -> i번째 원소보다 작지만 
			가장 큰 원소를 마지막으로 하는 수열의 수 + 1
			   -
* {1, 2, 1, 2, 3, 5, 4}
* d[1] = 1
* d[2] = 2
* d[3] = 1
* d[4] = 2
* d[5] = 3
* d[6] = 6
* d[7] = 4
*/