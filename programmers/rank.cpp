#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/*
    플로이드-와셜 알고리즘
    -모든 경로에 대한 최단 경로를 찾는다

    이 문제에 적용하는 법
    - 주어진 예제 {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}
    - {A, B}에서 A는 B를 항상 이긴다
    - 2는 네 번의 경기를 하므로 순위가 확정적으로 정해진다
    - 5번이 2번에게 확실하게 지는 거라면, 2를 이기는 모든 선수에게도 진다.
    - {4, 5}, {3, 5}, {1, 5}, {2, 5}가 성립한다.
    - 이는 {4,2} {2,5}에서 {4,5}가 도출된 것이다.
    - 그러므로 플로이드-와셜 알고리즘을 적용할 수 있다.
*/
int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    // 선수는 1부터 시작하므로 배열을 만들 때 1를 더한다
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));

    // 기본 상태
    for (auto i : results)
        win[i[0]][i[1]] = true;

    // 기본 상태를 이용해서 모든 정점을 갱신
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                if (win[j][i] && win[i][k])
                    win[j][k] = true;

    // 선수가 n명일 때 한 선수가 모든 선수와 붙는 횟수는 n-1
    for (int i = 1; i <= n; ++i)
    {
        int count = 0;
        for (int j = 1; j <= n; ++j)
        {
            // 이기거나 지거나 경기 자체를 카운트
            if (win[i][j] || win[j][i])
                ++count;
        }
        if (n - 1 == count) ++answer;
    }
    return answer;
}

int main()
{
    auto res = solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} });
    printf("%d\n", res);
}