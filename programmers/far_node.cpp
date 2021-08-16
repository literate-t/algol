#include <string>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    vector<vector<int>> vec(n + 1, vector<int>(n + 1));
    size_t size = edge.size();
    for (int i = 0; i < size; ++i)
    {
        auto n1 = edge[i][0];
        auto n2 = edge[i][1];
        vec[n1][n2] = 1;
        vec[n2][n1] = 1;
    }
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);

    visited[1] = true;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (vec[node][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
                dist[i] = dist[node] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= n; ++i)
        max = max < dist[i] ? dist[i] : max;
    for (int i = 1; i <= n; ++i)
        if (max == dist[i])
            ++answer;
    return answer;
}

int main()
{
    printf("%d\n", solution(6, { {3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} }));
}