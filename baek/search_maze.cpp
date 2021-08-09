#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int row[] = { 0, 1, 0, -1 };
	int col[] = { 1, 0, -1, 0 };
	char temp[100];
	int map[102][102];
	int dist[102][102];
	bool visited[102][102];

	for (int i = 1; i <= N; ++i)
	{
		scanf("%s", temp);
		for (int j = 0; j < M; ++j)
		{
			dist[i][j+1] = 1;
			map[i][j + 1] = temp[j] - '0';
		}
	}
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1][1] = true;
	while (!q.empty())
	{
		auto [r, c] = q.front();
		if (r == N && c == M)
			break;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			auto rr = r + row[i];
			auto cc = c + col[i];
			if (visited[rr][cc] == false && map[rr][cc])
			{
				visited[rr][cc] = true;
				dist[rr][cc] = dist[r][c] + 1;
				q.push({ rr, cc });
			}
		}
	}
	printf("%d", dist[N][M]);
}