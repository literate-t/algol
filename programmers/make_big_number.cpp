#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    int start = 0;
    int result_size = number.size() - k;
    for (int i = 0; i < result_size; ++i)
    {
        char max = '0';
        for (int j = start; j <= k + i; ++j)
        {
            if (number[j] > max)
            {
                max = number[j];
                start = j + 1;
            }
        }
        answer.push_back(max);
    }
    return answer;
}

int main()
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
}
