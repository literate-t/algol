#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> d(N+1, vector<int>(N+1, 0));
	vector<int> t(N+1, 0);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			scanf("%d", &t[j]);
			int a = d[i - 1][j - 1];
			int b = d[i - 1][j];
			d[i][j] = (a > b ? a : b) + t[j];
		}
	}
	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		auto val = d[N][i];
		max = max < val ? val : max;
	}
	printf("%d", max);
}
/*
*					[1][1]
*				[2][1]  [2][2]
*			[3][1]	[3][2]	 [3][3]
*		[4][1]	[4][2]	 [4][3]	  [4][4]
*	 [5][1]	 [5][2]  [5][3]  [5][4]	 [5][5]
* 
*	

*/