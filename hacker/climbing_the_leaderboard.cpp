#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int N, M;
	scanf("%d", &N);
	vector<int> ranked(N, 0);
	for (int i = 0; i < N; ++i)
		scanf("%d", &ranked[i]);
	scanf("%d", &M);
	vector<int> player(M, 0);
	for (int i = 0; i < M; ++i)
		scanf("%d", &player[i]);

	int my_rank = 1;
	for (size_t i = 0; i < ranked.size() - 1; ++i)
		if (ranked[i] > ranked[i + 1])
			++my_rank;

	my_rank += 1;
	int r_index = ranked.size() - 1;
	for (size_t i = 0; i < M; ++i)
	{
		auto p_score = player[i];
		while (p_score)
		{
		}
		printf("%d\n", my_rank);
	}
}