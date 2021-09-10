#include <cstdio>
#include <vector>
#include <string>
using namespace std;

/*
* initial		1초	  			2초			3초			4초			5초(initial)
	.......		.......			OOOOOOO		OOO.OOO		OOOOOOO		.......
	...O...		...O...			OOOOOOO		OO...OO		OOOOOOO		...O...
	....O..		....O..			OOOOOOO		OOO...O		OOOOOOO		....O..
	.......		.......			OOOOOOO		..OO.OO		OOOOOOO		.......
	OO.....		OO.....			OOOOOOO		...OOOO		OOOOOOO		OO.....
	OO.....		OO.....			OOOOOOO		...OOOO		OOOOOOO		OO.....

*/
// 3 7 11..같고-> 한 번 폭발, 5 9 13..이렇게 같음 -> 두 번 폭발
vector<string> bomberMan(int n, vector<string> grid)
{
	vector<pair<size_t, size_t>> pos;
	if (0 == n % 2)
	{
		for (size_t i = 0; i < grid.size(); ++i)
			for (size_t j = 0; j < grid[i].size(); ++j)
				grid[i][j] = 'O';
		return grid;
	}
	else if ((n + 1) % 4 == 0)
		n = 3;
	else if (n != 1 && (n - 1) % 4 == 0)
		n = 5;
	for (size_t t = 2; t <= n; ++t)
	{
		if (0 == t % 2)
		{
			for (size_t i = 0; i < grid.size(); ++i)
			{
				for (size_t j = 0; j < grid[i].size(); ++j)
				{
					if ('O' == grid[i][j])
						pos.push_back({ i, j });
					else
						grid[i][j] = 'O';
				}
			}
		}
		else
		{			
			for (size_t i = 0; i < pos.size(); ++i)
			{
				size_t r = pos[i].first;
				size_t c = pos[i].second;
				grid[r][c] = '.';
				if (r > 0)
					grid[r - 1][c] = '.';
				if (c > 0)
					grid[r][c - 1] = '.';
				if (r < grid.size() - 1 )
					grid[r + 1][c] = '.';
				if (c < grid[r].size() - 1)
					grid[r][c + 1] = '.';

			}	
			pos.clear();
		}
	}
	return grid;
}

int main()
{
	vector<string> grid = {
		".......",
		"...O...",
		"....O..",
		".......",
		"OO.....",
		"OO....."
	};
	int n = 3; // 3 7 11..같고-> 한 번 폭발, 5 9 13..이렇게 같음 -> 두 번 폭발
	auto result = bomberMan(n, grid);
	for (string str : result)
		printf("%s\n", str.c_str());
}