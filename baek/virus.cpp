#include <queue>
#include <cstdio>
using namespace std;
int main()
{
	int N, pair;
	bool visited[101] = {};
	scanf("%d%d", &N, &pair);
	++N;
	int com[101][101] = {};
	for (int i = 0; i < pair; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		com[a][b] = 1;
		com[b][a] = 1;
	}
	
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int answer = -1;
	while (!q.empty())
	{
		auto n = q.front();
		q.pop();
		++answer;
		for (int i = 1; i <= N; ++i)
		{
			if (com[n][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	printf("%d\n", answer);
}