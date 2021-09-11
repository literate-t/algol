#include <iostream>
#include <vector>
using namespace std;

void extraLongFactorials(int n)
{
	vector<int> answer;
	answer.push_back(1);
	for (int i = 2; i <= n; ++i)
	{
		int carry = 0;
		for (int j = 0; j < answer.size(); ++j)
		{
			auto res = i * answer[j] + carry;
			if (res < 10)
			{
				answer[j] = res;
				carry = 0;
				continue;
			}
			else if (j + 1 == answer.size())
				answer.push_back(0);
			answer[j] = res % 10;
			carry = res / 10;
		}
	}
	for (auto it = answer.rbegin(); it != answer.rend(); ++it)
		printf("%d", *it);
}

int main()
{
	extraLongFactorials(25);
}