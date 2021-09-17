#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T, M, N, K;
	//     c  r  πË√ﬂ

	scanf("%d", &T);	

	int r_dir[] = {0, 1, 0, -1};
	int c_dir[] = {1, 0, -1, 0};

	while (T--)
	{
		scanf("%d", &M);
		scanf("%d", &N);
		scanf("%d", &K);
		vector<vector<int>> map(N, vector<int>(M, 0));
		vector<vector<bool>> checked(N, vector<bool>(M, false));
		queue<pair<int, int>> q;
		int count = 0;
		for (int i = 0; i < K; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			map[b][a] = 1;
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (false == checked[i][j] && map[i][j])
				{
					++count;
					q.push({ i, j });
					checked[i][j] = true;
					while (!q.empty())
					{
						auto [row, col] = q.front();
						q.pop();

						for (int k = 0; k < 4; ++k)
						{
							int r = row + r_dir[k];
							int c = col + c_dir[k];
							if (r < 0 || r + 1 > N || c < 0 || c + 1 > M) continue;

							else if (false == checked[r][c] && map[r][c])
							{
								checked[r][c] = true;
								q.push({ r, c });
							}
						}
					}
				}
			}
		}
		printf("%d\n", count);
	}
}