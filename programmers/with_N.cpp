#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <cmath>
using namespace std;

int solution(int N, int number) 
{
    int answer = -1;
    vector<unordered_set<int>> d(9);
    vector<set<int>> ds(9);
    for (int i = 1; i <= 8; ++i)
    {
        int num = 0, count = i;
        while (count-- > 0)
            num += N * pow(10, count);
        d[i].insert(num);
    }
    for (int i = 2; i <= 8; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            for (const auto a : d[j])
            {
                for (const auto b : d[i - j])
                {
                    auto& dd = d[i];
                    dd.insert(a + b);
                    dd.insert(a * b);
                    dd.insert(a - b);
                    if (b != 0)
                        dd.insert(a / b);
                }
            }
        }
    }
    for (int i = 1; i <= 8; ++i)
    {
        if (d[i].find(number) != d[i].end())
            return i;
    }
    return answer;
}

/*
*   d[1] = 5
*   d[2] = (d[1] +-/* d[1]) -> 55, 5 + 5, 5 - 5, 5 * 5, 5 / 5
*   d[3] = (d[1] +-/* d[2]) + (d[2] +-/* d[1])
*   d[4] = (d[1] +-/* d[3]) + (d[2] +-/* d[2] + (d[3] +-/* d[1])
*   d[n] = (d[1] +-/* d[n-1]) + (d[2] +-/* d[n-2]) + ... + (d[n-1] +-/* d[1])
*/

int main()
{
    printf("%d\n", solution(5, 12)); // 4
    printf("%d\n", solution(2, 11)); // 3
}