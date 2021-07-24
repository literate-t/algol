#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) 
{
    size_t size = s.size(); // 8
    size_t answer = size;
    for (size_t i = 1; i <= size / 2; ++i)
    {
        auto sub = s.substr(0, i);
        int count = 1;
        string temp;
        for (size_t j = i; j <= size; j += i)
        {
            auto selected = s.substr(j, i);
            if (sub == selected)
                ++count;
            else
            {
                if (count > 1)
                {
                    temp += to_string(count);
                    count = 1;
                }
                temp += sub;
                sub = selected;
            }
        }
        if (size % i != 0)
            temp += sub;
        answer = answer > temp.size() ? temp.size() : answer;
    }
    return answer;
}

int main()
{
    cout << solution("aabbaccc") << endl;
}