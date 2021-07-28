#include <string>
#include <vector>
#include <iostream>
using namespace std;

int get_up_down(char c)
{
    return c - 'A' < 'Z' - c + 1 ? c - 'A' : 'Z' - c + 1;
}

int solution(string name)
{
    int answer = 0;
    int min_val = name.find_last_not_of('A');
    int size = name.size();
    for (int i = 0; i < size; ++i)
    {
        auto c = name[i];
        if ('A' == c) continue;
        else
        {
            answer += get_up_down(c);
            int next_idx = i;
            while ('A' == name[++next_idx]) {}
            int m = i + size - next_idx + min(i, size - next_idx);
            min_val = min(min_val, m);
        }
    }
    return answer + min_val;
}
/*
* AABAAAAB
* 세 가지 루트가 있다
* 1. 끝에서 A가 아닌 인덱스
* 2. 2a + b
* 3. 2b + a
* min(2a + b, 2b + a)
* -> a + b + min(a, b)
*
*/

int main()
{
    cout << solution("JEROEN") << endl; //56
    cout << solution("JAN") << endl; //23
    cout << solution("AABAAAAB") << endl; //6
}