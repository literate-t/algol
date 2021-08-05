#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool solution(string s)
{
    if (s[0] == ')') return false;

    stack<char> b;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (!b.empty() && c == ')')
            b.pop();
        else
            b.push(c);
    }
    return b.empty() ? true : false;
}

int main()
{
    cout << solution("()()") << endl;       // true
    cout << solution("(())()") << endl;     // true
    cout << solution(")()(") << endl;       // false
    cout << solution("(()(") << endl;       // false
    cout << solution("(()()))") << endl;    // false
    cout << solution("((()))") << endl;     // true
}