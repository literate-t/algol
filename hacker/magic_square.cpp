#include <iostream>
#include <vector>
#include <string>
using namespace std;

int formingMagicSquare(vector<vector<int>> s)
{
	vector<vector<int>> magic = {
		{8, 3, 4}, {1, 5, 9}, {6, 7, 2},
		{6, 1, 8}, {7, 5, 3}, {2, 9, 4},
		{2, 7, 6}, {9, 5, 1}, {4, 3, 8},
		{4, 9, 2}, {3, 5, 7}, {8, 1, 6},
		{4, 3, 8}, {9, 5, 1}, {2, 7, 6},
		{6, 7, 2}, {1, 5, 9}, {8, 3, 4},
		{2, 9, 4}, {7, 5, 3}, {6, 1, 8},
		{8, 1, 6}, {3, 5, 7}, {4, 9, 2}
	};
	int min_val = 81;
	int sum = 0;
	for (size_t i = 0; i < magic.size(); ++i)
	{
		for (size_t j = 0; j < magic[i].size(); ++j)
		{
			sum += abs(magic[i][j] - s[i % 3][j]);
		}
		if (0 == (i + 1) % 3)
		{
			min_val = min(min_val, sum);
			sum = 0;
		}
	}
	return min_val;
}

int main()
{
	vector<vector<int>> s = {
		{4, 9, 2}, {3, 5, 7}, {8, 1, 5}
	};
	auto result = formingMagicSquare(s);
	printf("%d\n", result);
}