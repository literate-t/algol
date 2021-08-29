#include <cstdio>
#include <vector>
using namespace std;

// 2805��
int main()
{	
	int N; // ���� ��
	scanf("%d", &N);

	vector<long long> trees(N);
	long long M;		  // �ʿ��� ������ ����
	long long answer = 0; // ���ܱ⿡ ������ �ִ� ����
	long long high = 0, low = 1;
	scanf("%lld", &M);

	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &trees[i]);
		high = high < trees[i] ? trees[i] : high;
	}
	while (low <= high)
	{
		long long mid = (high + low) / 2;
		long long sum = 0;
		for (int i = 0; i < N; ++i)
		{
			auto cut_reulst = trees[i] - mid;
			if (cut_reulst <= 0) continue;
			sum += cut_reulst;
		}
		if (M <= sum)
		{
			answer = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	printf("%lld\n", answer);
}