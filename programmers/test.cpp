#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    size_t size = number.size() - k;
    int next = 0;
    int start = 0;
    for (int i = 0; i < size; ++i)
    {
        char max = 0;
        for (int j = start; j <= k + next; ++j)
        {
            if (max < number[j])
            {
                max = number[j];
                start = j + 1;
            }
        }            
        answer += max;
        next += 1;
    }
    return answer;
}
/*

1924  K:2, 두 자리
192 4
0~2(K)

1231234 K:3, 네 자리
1231 234
0~3(K)

4177252841 K:4, 여섯 자리
41772 52841
0~4

*/
int main()
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
}