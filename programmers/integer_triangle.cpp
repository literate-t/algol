#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int wrap(int a)
{
    return a < 0 ? 0 : a;
}

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> d(size, vector<int>(size, 0));

    for (int i = 0; i < triangle.size(); ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            d[i][j] = max(d[wrap(i - 1)][wrap(j - 1)], d[wrap(i - 1)][j]) + triangle[i][j];
        }
    }    
    for (int i = 0; i < d[size - 1].size(); ++i)
        answer = max(answer, d[size - 1][i]);
    return answer;
}
/*
                     [0][0]
                 [1][0]  [1][1]
             [2][0]  [2][1]  [2][2]
        [3][0]   [3][1]   [3][2]   [3][3]

        d[0][0] = t[0][0]
        d[1][0] = d[0][0] + t[1][0]
        d[1][1] = d[0][0] + t[1][1]

        d[2][1] = max(d[2-1][1-1], d[2-1][1]) + t[2][1]

        d[i][j] = max(d[i-1][j-1], d[i-1][j]) + t[i][j]
   
*/
void print(vector<vector<int>> triangle, int answer)
{
    auto result = solution(triangle);
    if (answer == result)
        printf("Correct\n");
    else
        printf("Wrong\n");
}

int main()
{
    print({ {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} }, 30);
}