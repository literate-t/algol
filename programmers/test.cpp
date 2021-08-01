#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) 
{
    size_t size = s.size();
    int answer = size;

    for (size_t i = 1; i <= size / 2; ++i)
    {
        string sub = s.substr(0, i);
        int count = 1;
        string temp;
        for (size_t j = i; j <= size; j += i)
        {
            string str = s.substr(j, i);
            if (sub == str)
                ++count; // 3
            else
            {
                if (count >= 2)
                    temp += to_string(count);
                temp += sub;
                count = 1;
                sub = (str == "" ? sub : str);
            }
        }
        if (size % i != 0)
            temp += sub;
        answer = (answer > temp.size() ? temp.size() : answer);
    }
    return answer;
}


int main()
{
    cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("abcabcabcabcdededededede") << endl;
}