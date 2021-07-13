#include <string>
#include <vector>
#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}
int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; ++i)
    {
        string sub = s.substr(0, i);
        string str = "";
        int count = 1;
        for (int j = i; j <= s.size(); j += i)
        {
            if (sub == s.substr(j, i))
                ++count;
            else
            {
                if (count > 1)
                {
                    str += to_string(count);
                    count = 1;
                }
                str += sub;
                sub = s.substr(j, i);
            }
        }
        if (s.size() % i != 0)
            str += sub;
        answer = min(answer, str.size());
    }
    return answer;
}

int main()
{
    cout << solution("xababcdcdababcdcd") << endl;
}

//int get_min(int a, int b)
//{
//    return a < b ? a : b;
//}
//int solution(string s)
//{
//    int size = s.size();
//    int answer = size;
//    for (int i = 1; i <= size/2; ++i)
//    {
//        string sub = s.substr(0, i);
//        string result = "";
//        int count = 1;
//
//        for (int j = i; j <= size; j+=i)
//        {            
//            if (sub == s.substr(j, i))
//            {
//                ++count;
//                continue;
//            }
//            else
//            {
//                if (count > 1)
//                {
//                    result += to_string(count) + sub;
//                }
//                else
//                {
//                    result += sub;
//                }
//                sub = s.substr(j, i);
//                count = 1;
//            }            
//        }   
//        if (size % i != 0)
//            result += sub;
//
//        answer = get_min(answer, result.size());
//    }
//    return answer;
//}


/*
* aabbaccc -> 2a2ba3c
* 
* ababcdcdababcdcd -> 2ababcdcd
* 
*/