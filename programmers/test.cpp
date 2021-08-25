#include <cstdio>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;
int solution(int N, int number) 
{
    int answer = 0;
    vector<unordered_set<int>> d(9);
    for (int i = 1; i <= 8; ++i)
    {
        int sum = 0;
        int count = i;
        while (count)
            sum += N * pow(10, --count);
        d[i].insert(sum);
    }

    for (int i = 2; i <= 8; ++i)
    {
        for (int j = 1; j < i; ++j)
        {            
            for (const int p1 : d[j])
            {
                for (const int p2 : d[i - j])
                {                    
                    d[i].insert(p1 + p2);
                    d[i].insert(p1 * p2);
                    d[i].insert(p1 - p2);
                    if (0 != p2)
                        d[i].insert(p1 / p2);
                }
            }
        }
    }
    for (int i = 1; i <= 8; ++i)
    {
        for (int num : d[i])
            if (num == number)
                return i;
    }
    return -1;
}
/*
*	d[i] -> N을 i번 사용해서 만들 수 있는 사칙연산의 결과 경우의 수
*	d[1] = 5
*	d[2] = 55, d[1] +-/* d[1] -> 10, 0, 25, 1
*	d[3] = 555, d[1] +-/* d[2], d[2] + d[1] -> 5, 6, 15, 30, 50, 125..
*	d[4] = 5555, (d[1] +-/* d[3]) + (d[2] + d[2]) + (d[3] + d[1])
*	d[i] = N*i, (d[1] +-/* d[N-1]) + (d[2] +-/* d[N-1) + ... + (d[N-1] + d[1])
*/
int main()
{
    auto answer = solution(5, 12);
    printf("%d", answer);
}