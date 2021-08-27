#include <cstdio>
int main()
{
	int N, M;
	int e[100000] = {};
	scanf("%d%d", &N, &M);
	long long high = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &e[i]);
		high = high < e[i] ? e[i] : high;
	}

	high = high * M;
	long long low = 1;
	// long long answer = 0;
	while (low <= high)
	{
		long long m = 0;
		long long mid = (low + high) / 2;		
		for (int i = 0; i < N; ++i)
			m += mid / e[i];
		if (m < M)
			low = mid + 1;
		else
		{
			//answer = mid;
			high = mid - 1;
		}
	}
	printf("%lld\n", low);
	//printf("%lld\n", answer);
}
/*
  이분 탐색을 위한 최대값 구하기
  최대 값은 심사대기가 가장 오래 걸리는 시간 * 인원 수
* 1번 심사대는 7분
* 2번 심사대는 10분이 걸린다
* 심사 인원은 6명
* 심사를 마치는데 걸리는 시간의 최소 값
*
* 주어진 심사대를 기준으로 생각해보자.
* 10분의 시간이 주어진다면
* 10/10 + 10/7 = 2
* 2명이 입국심사를 받을 수 있음
* 
* 15분의 시간이 주어진다면
* 15/10 + 15/7 = 3
* 3명이 입국심사를 받을 수 있음 * 
* 14분도
* 14/10 + 14/7 = 3
* 3명임
* 
*/