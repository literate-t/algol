#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> stack_char;
	for (int i = 0; i < s.size(); ++i)
	{
		if (!stack_char.empty() && stack_char.top() == s[i]) stack_char.pop();
		else stack_char.push(s[i]);
	}
	return stack_char.empty() ? 1 : 0;
}

int main()
{
	cout << solution("baabaa") << endl;
}