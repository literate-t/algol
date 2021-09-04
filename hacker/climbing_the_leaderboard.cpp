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
	for (size_t i = 0; i < N; ++i)
		scanf("%d", &ranked[i]);
	scanf("%d", &M);
	vector<int> player(M, 0);
	for (size_t i = 0; i < M; ++i)
		scanf("%d", &player[i]);

	int my_rank = 1;
	for (size_t i = 0; i < ranked.size() - 1; ++i)
		if (ranked[i] > ranked[i + 1])
			++my_rank;
	vector<int> answer;
	answer.reserve(M);
	my_rank += 1;
	size_t r_index = ranked.size() - 1;
	for (size_t i = 0; i < M; ++i)
	{
		auto my_score = player[i];
		while (my_score >= ranked[r_index])
		{
			if (0 == r_index)
			{
				my_rank = 1;
				break;
			}
			if (ranked[r_index] != ranked[r_index - 1])
			{
				--my_rank;
				--r_index;
			}
			else
				--r_index;

		}
		answer.push_back(my_rank);
	}
}