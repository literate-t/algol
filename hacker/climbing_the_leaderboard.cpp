#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	int my_rank = 1;
	for (size_t i = 0; i < ranked.size() - 1; ++i)
	{
		if (ranked[i] > ranked[i + 1])
			++my_rank;
	}
	++my_rank;
	int r_idx = ranked.size() - 1;
	int p_idx = 0;
	vector<int> answer;
	int size = player.size();
	answer.reserve(size);
	while (p_idx + 1 <= size)
	{
		auto me = player[p_idx];
		auto rank = ranked[r_idx];
		if (me >= rank)
		{
			if (r_idx == 0)
			{
				answer.push_back(1);
				++p_idx;
			}
			else if (ranked[r_idx - 1] != ranked[r_idx])
			{
				--my_rank;
				--r_idx;
			}
			else
				--r_idx;
		}
		else
		{
			answer.push_back(my_rank);
			++p_idx;
		}
	}
	return answer;
}

int main()
{
	vector<int> ranked{ 100,90,90,80,75,60 };
	vector<int> player{ 50,65,77,90,102 };
	auto result = climbingLeaderboard(ranked, player);
	for (int r : result) // 6 5 4 2 1
		printf("%d\n", r);
}