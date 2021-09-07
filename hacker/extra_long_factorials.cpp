#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N = 25;	
	vector<int> answer;
	answer.push_back(1);
	// number to multifly
	for (int i = 2; i <= N; ++i)
	{
		for (auto it = answer.begin(); it != answer.end(); ++it)
			*it *= i;
		for (size_t j = 0; j < answer.size(); ++j)
		{
			auto a = answer[j];
			if (a < 10) continue;

			if (answer.size() == j + 1)
				answer.push_back(0);// increae digit
			answer[j] = a % 10;
			answer[j + 1] += a / 10;
		}
	}
	for (auto it = answer.rbegin(); it != answer.rend(); ++it)
		cout << *it;
}