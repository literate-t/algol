#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	char map[25][25] = {};
	bool flag[25][25] = {};
	int row_dir[] = {0, 1, 0, -1};
	int col_dir[] = {1, 0, -1, 0};
	for (int i = 0; i < N; ++i)
		scanf("%s", map[i]);

	priority_queue<int, vector<int>, greater<int>> pq;
	int count = 0;
	for (int i = 0; i < N; ++i)
	{	
		int answer = 0;
		for (int j = 0; j < N; ++j)
		{			
			if (map[i][j] == '1' && !flag[i][j])
			{
				++count;
				queue<pair<int, int>> q;
				q.push({ i, j });
				int answer = 0;
				while (!q.empty())
				{
					auto [r, c] = q.front();
					q.pop();
					++answer;
					flag[r][c] = true;
					for (int k = 0; k < 4; ++k)
					{
						auto rr = r + row_dir[k];
						auto cc = c + col_dir[k];
						if (rr >= N || rr < 0 || cc >= N || cc < 0) continue;
						else if(map[rr][cc] == '1' && !flag[rr][cc])
						{
							
							flag[rr][cc] = true;
							q.push({ rr, cc });
						}
					}
				}
				if (answer)
					pq.push(answer);
			}	
		}
	}
	printf("%d\n", count);
	while (!pq.empty())
	{
		printf("%d\n", pq.top());
		pq.pop();
	}
}