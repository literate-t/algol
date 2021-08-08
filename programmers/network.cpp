#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> com;
vector<bool> v;

void bfs(int i)
{
	v[i] = true;
	queue<int> q;
	q.push(i);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int j = 0; j < N; ++j)
		{
			if (v[j] == false && com[node][j])
			{
				v[j] = true;
				q.push(j);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	N = n;
	com = computers;
	v.resize(n, false);
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i]) continue;
		++answer;
		bfs(i);
	}

	return answer;
}

int main()
{
	cout << solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} }) << endl; // 2
	cout << solution(3, { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} }) << endl; // 1
}