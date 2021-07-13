#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 1, 1);
    for (int i : lost)
        --student.at(i);

    for (int i : reserve)
        ++student.at(i);

    const int size = student.size();
    for (int i = 1; i < size; ++i)
    {
        if (student.at(i) == 2)
        {
            if (student.at(i - 1) == 0)
            {
                ++student.at(i - 1);
                --student.at(i);
            }
            else if (i < size - 1 && student.at(i + 1) == 0)
            {
                ++student.at(i + 1);
                --student.at(i);
            }
        }
    }
    for (int i = 1; i < size; ++i)
    {
        if (student[i] < 1) continue;
        ++answer;
    }
    return answer;
}

int main()
{
    cout << solution(5, {  }, { 1 }) << endl;
}