#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 10, E = 19;
const int INF = 100000000;

vector<vector<int>> nodes(N, vector<int>(N));
vector<int> dist(N, INF);
using PairInt = pair<int, int>;

void dijkstra(int start)
{
	// 방문할 노드를 담아두는 곳(최소 가중치인 곳)
	// first는 방문한 노드까지의 최소 가중치, second는 방문한 노드
	priority_queue<PairInt, vector<PairInt>, greater<PairInt>> pq; 
	// 시작 노드의 가중치는 0
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		auto [length, current] = pq.top(); pq.pop();
		if (dist[current] < length) continue;

		for (int i = 0; i < nodes[current].size(); ++i)
		{
			if (0 == nodes[current][i]) continue;

			auto sum = dist[current] + nodes[current][i];
			if (sum < dist[i])
			{
				dist[i] = sum;
				pq.push({ sum, i });
			}
		}
	}
}

int main()
{
	nodes[0][1] = 10;
	nodes[0][2] = 17;
	nodes[0][3] = 30;
	nodes[0][4] = 25;
	nodes[0][5] = 23;
	nodes[1][2] = 20;
	nodes[2][4] = 17;
	nodes[3][1] = 19;
	nodes[3][6] = 24;
	nodes[4][7] = 25;
	nodes[4][8] = 39;
	nodes[5][3] = 16;
	nodes[5][4] = 28;
	nodes[5][6] = 18;
	nodes[6][9] = 20;
	nodes[7][8] = 29;
	nodes[8][5] = 20;
	nodes[8][9] = 28;
	nodes[9][7] = 40;	

	dijkstra(0);

	cout << dist[9] << endl;
}