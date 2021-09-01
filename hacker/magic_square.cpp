#include <cstdio>
int abs(int v)
{
	return v < 0 ? -v : v;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int input[3][3] =
	{
		{9, 3, 3}, {3, 3, 2}, {1, 8, 1}
	};


	int magic[24][3] =
	{
		{8, 3, 4}, {1, 5, 9}, {6, 7, 2},
		{6, 1, 8}, {7, 5, 3}, {2, 9, 4},
		{2, 7, 6}, {9, 5, 1}, {4, 3, 8},
		{4, 9, 2}, {3, 5, 7}, {8, 1, 6},
		{4, 3, 8}, {9, 5, 1}, {2, 7, 6},
		{6, 7, 2}, {1, 5, 9}, {8, 3, 4},
		{2, 9, 4}, {7, 5, 3}, {6, 1, 8},
		{8, 1, 6}, {3, 5, 7}, {4, 9, 2}
	};
	int min_val = 30, sum = 0;
	for (int i = 0; i < 24; ++i)
	{
		for (int j = 0; j < 3; ++j)
			sum += abs(magic[i][j] - input[i % 3][j]);

		if (0 == (i + 1) % 3)
		{
			min_val = min(sum, min_val);
			sum = 0;
		}
	}
	printf("%d\n", min_val);
}