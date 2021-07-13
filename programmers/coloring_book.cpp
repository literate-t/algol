#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool visited[100][100];
int max_size_of_one_area;
int number_of_area;

int bfs(int i, int j, vector<vector<int>> &picture)
{
    const int m_size = picture.size();
    const int n_size = picture[0].size();
    int count = 0;
    int n_dir[4] = { 1, 0, -1, 0 };
    int m_dir[4] = { 0, 1, 0, -1 };

    visited[i][j] = true;
    int node = picture[i][j];

    queue <pair<int, int>> q;
    q.push({ i, j });
    while (!q.empty())
    {
        auto [m, n] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k)
        {
            int mm = m_dir[k] + m;
            int nn = n_dir[k] + n;
            if (mm < 0 || nn < 0 || mm >= m_size || nn >= n_size) continue;

            if (visited[mm][nn] == false && picture[mm][nn] == node)
            {
                q.push({ mm, nn });
                visited[mm][nn] = true;
            }

        }
        ++count;
    }
    return count;
}

int get_max(int a, int b)
{
    return a > b ? a : b;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;

    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            visited[i][j] = false;
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j] == false && picture[i][j] != 0)
            {
                ++number_of_area;
                max_size_of_one_area = get_max(bfs(i, j, picture), max_size_of_one_area);
            }
        }            

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    auto answer = solution(6, 4, { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1 }
        , {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });

    for (int n : answer)
    {
        cout << n << endl;
    }
}