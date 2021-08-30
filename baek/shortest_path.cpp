#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using IntPair = pair<int, int>;
const int INF = 3000001;
const int MAX = 20001;
int main()
{
	int N, E, S;
	scanf("%d%d%d", &N, &E, &S);
	vector<IntPair> nodes[MAX];

	priority_queue<IntPair, vector<IntPair>, greater<IntPair>> pq; // first가 가중치, second가 노드 번호
	vector<int> distance(N + 1, INF);

	for (int i = 0; i < E; ++i)
	{
		int n1, n2, e;
		scanf("%d%d%d", &n1, &n2, &e);
		nodes[n1].push_back({ n2, e });
	}

	distance[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty())
	{
		auto [cost, current] = pq.top(); pq.pop();
		if (distance[current] < cost) continue;

		for (size_t i = 0; i < nodes[current].size(); ++i)
		{
			auto sum = distance[current] + nodes[current][i].second;
			auto next = nodes[current][i].first;
			if (sum < distance[next])
			{
				distance[next] = sum;
				pq.push({ sum, nodes[current][i].first });
			}
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		auto num = distance[i];
		if (INF == num) printf("INF\n");
		else printf("%d\n", num);
	}		
}