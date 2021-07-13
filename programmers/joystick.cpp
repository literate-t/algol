#include <string>
#include <vector>
#include <iostream>
using namespace std;

int GetMinUpDown(char c)
{
    return c - 'A' < 'Z' - c + 1 ? c - 'A' : 'Z' - c + 1;
}
int solution(string name) 
{
    int answer = 0;
    int size = name.size();
    for (int i = 0; i < size; ++i)
        answer += GetMinUpDown(name[i]);

    int max_index = size - 1;
    int min_val = size - 1;
    int next_index = 0;
    for (int i = 0; i < size; ++i)
    {
        if (name[i] != 'A')
        {
            next_index = i + 1;
            while (next_index < max_index && name[next_index] == 'A')
                ++next_index;
            min_val = min(min_val, i + size - next_index + min(i, size - next_index));                            
            i = next_index;
        }
    }
    return answer + min_val;
}

/*
*   01234
*   ABAABAAAABAB
     a 	b
    int answer = str.size() - 1 : 4

    min(2a + b, 2b + a)
    -> a + b + min(a, b)

    A -> Z: 25, 1
    A - 'some'
    Z - 'some' + 1
*/

int main()
{
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;
}