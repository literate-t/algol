#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[200][200];
vector<vector<int>> com;

void bfs(int i, int j)
{
    queue<int> q;
    q.push({ j });
    while (!q.empty())
    {
        auto j = q.front();
        q.pop();
        for (int k = j + 1; k < com[i].size(); ++k)
        {
            if (visited[i][k] == false && com[i][k])
            {
                q.push(k);
                visited[i][k] = true;
                visited[k][i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    com = computers;
    int answer = 0;
    for (int i = 0; i < computers.size(); ++i)
    {
        for (int j = 0; j < computers[i].size(); ++j)
        {
            if (i == j)
            {
                visited[i][j] = true;
                continue;
            }

            else if (visited[i][j] == false && com[i][j])
            {
                visited[i][j] = true;
                visited[j][i] = true;
                bfs(i, j);
                ++answer;
            }
        }
    }
    return answer;
}
/*
* n[0][1] = 1
* n[1][0] = 1
* 
*/
int main()
{
    cout << solution(3, { {1,1,0}, {1, 1, 0}, {0, 0, 1} }) << endl; // 2
    cout << solution(3, { {1,1,0}, {1, 1, 1}, {0, 1, 1} }) << endl; // 1
}