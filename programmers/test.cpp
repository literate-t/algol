#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (st.empty() || st.top() != s[i]) st.push(s[i]);
        else st.pop();
    }  
    return st.empty() ? 1 : 0;
}
/*
예를 들어, 문자열 S = baabaa 라면
b aa baa → bb aa → aa →
의 순서로 문자열을 모두 제거할 수 있으므로 1을 반환합니다.
*/

int main()
{
    cout << solution("baabaa") << endl;
    return 0;
}