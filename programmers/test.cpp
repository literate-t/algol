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
���� ���, ���ڿ� S = baabaa ���
b aa baa �� bb aa �� aa ��
�� ������ ���ڿ��� ��� ������ �� �����Ƿ� 1�� ��ȯ�մϴ�.
*/

int main()
{
    cout << solution("baabaa") << endl;
    return 0;
}