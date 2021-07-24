#include <string>
#include <vector>
#include <iostream>
using namespace std;

int matrix[101][101];
int min_val = 10001;

int get_min(int a, int b)
{
    return a < b ? a : b;
}
void rotate(int x1, int y1, int x2, int y2)
{
    int first = matrix[x1][y1];
    for (int i = x1; i < x2; ++i)
    {
        matrix[i][y1] = matrix[i + 1][y1];
        min_val = get_min(min_val, matrix[i][y1]);
    }

    for (int i = y1; i < y2; ++i)
    {
        matrix[x2][i] = matrix[x2][i + 1];
        min_val = get_min(min_val, matrix[x2][i]);
    }

    for (int i = x2; i > x1; --i)
    {
        matrix[i][y2] = matrix[i - 1][y2];
        min_val = get_min(min_val, matrix[i][y2]);
    }

    for (int i = y2; i > y1; --i)
    {
        matrix[x1][i] = matrix[x1][i - 1];
        min_val = get_min(min_val, matrix[x1][i]);
    }
    matrix[x1][y1 + 1] = first;
    min_val = get_min(min_val, first);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    for (int i = 1; i <= rows; ++i)
        for (int j = 1; j <= columns; ++j)
            matrix[i][j] = (i - 1) * columns + j;

    for (size_t i = 0; i < queries.size(); ++i)
    {
        auto x1 = queries[i][0];
        auto y1 = queries[i][1];
        auto x2 = queries[i][2];
        auto y2 = queries[i][3];
        
        rotate(x1, y1, x2, y2);
        answer.push_back(min_val);
        min_val = 10001;
    }
    return answer;
}

int main()
{
    auto result =  solution(6, 6, { {2,2,5,4}, {3,3,6,6}, {5,1,6,3} });
    for (auto number : result)
        cout << number << endl;
}