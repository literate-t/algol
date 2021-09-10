#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

//int twoPluses(vector<string> grid) 
//{
//	priority_queue<int> answer;
//	int row_dir[] = { -1, 0, 1, 0 };
//	int col_dir[] = { 0, 1, 0, -1 };
//	bool one_plus = false;
//	vector<vector<bool>> checked(grid.size(), vector<bool>(grid[0].size(), false));
//	for (size_t i = 0; i < grid.size(); ++i)
//	{
//		for (size_t j = 0; j < grid[i].size(); ++j)
//		{
//			if (grid[i][j] == 'G')
//			{
//				bool f = true;
//				for (size_t k = 0; k < 4; ++k)
//				{
//					auto rd = row_dir[k] + i;
//					auto cd = col_dir[k] + j;
//					if (rd < 0 || rd > grid.size() - 1 || cd < 0 || cd > grid[0].size() - 1
//						|| grid[rd][cd] == 'B' || true == checked[rd][cd])
//					{
//						f = false;
//						break;
//					}
//				}
//				if (true == f)
//				{
//					int c_min = grid[i].size() - 1 - j < j - 0 ? grid[i].size() - 1 - j : j - 0;
//					int size = j + c_min;
//					for (int c = j + 1; c <= size; ++c)
//					{
//						if (true == checked[i][c])
//						{
//							c_min = c - 1;
//							break;
//						}
//					}
//					size = j - c_min;
//					for (int c = j - 1; c >= size; --c)
//					{
//						if (true == checked[i][c])
//						{
//							c_min = c - 1;
//							break;
//						}
//					}
//					int r_min = grid.size() - 1 - i < i - 0 ? grid.size() - 1 - i : i - 0;
//					size = i + r_min;
//					for (int r = i + 1; r <= size; ++r)
//					{
//						if (true == checked[r][j])
//						{
//							r_min = r - 1;
//							break;
//						}
//					}
//					size = i - r_min;
//					for (int r = i - 1; r >= size; --r)
//					{
//						if (true == checked[r][j])
//						{
//							r_min = r - 1;
//							break;
//						}
//					}
//
//					int min_val = min(c_min, r_min);
//					checked[i][j] = true;
//					size = j + c_min;
//					for (int c = j + 1; c <= size; ++c)
//						checked[i][c] = true;
//
//					size = j - c_min;
//					for (int c = j - 1; c >= size; --c)
//						checked[i][c] = true;
//
//					size = i + r_min;
//					for (int r = i + 1; r <= size; ++r)
//						checked[r][j] = true;
//
//					size = i - r_min;
//					for (int r = i - 1; r >= size; --r)
//						checked[r][j] = true;
//					int p = min_val * 4 + 1;
//					answer.push(p);
//				}
//				else if (false == one_plus)
//				{
//					answer.push(1);
//					one_plus = true;
//				}
//			}
//		}
//	}
//	if (answer.size() > 1)
//	{
//		auto l1 = answer.top(); answer.pop();
//		auto l2 = answer.top(); answer.pop();
//		return l1 * l2;
//	}
//	return 0;
//}

int main()
{	
	vector<string> grid = {
		"GGGGGGGG",
		"GBGBGGBG",
		"GBGBGGBG",
		"GGGGGGGG",
		"GBGBGGBG"
		"GGGGGGGG",
		"GBGBGGBG",
		"GGGGGGGG"
	};
	//vector<string> grid = {
	//"GGGGGGG",
	//"BGBBBBG",
	//"BGBBBBG",
	//"GGGGGGG",
	//"GGGGGGG",
	//"BGBBBBG"
	//};
	auto result = twoPluses(grid);
	printf("%d\n", result);
}