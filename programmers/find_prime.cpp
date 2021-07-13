/*
	한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 
	흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
	각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 
	종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

	sol>
	1. next_permutation을 반복해서 돌린다
	2. 돌릴 때마다 잘라서 숫자로 변환한다("1234"의 경우, 1, 12, 123, 1234)
	3. 소수인 경우 set 컨테이너에 넣는다
	3. 1번으로
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
	sort(numbers.begin(), numbers.end(), greater<char>());
	set<int> answer;
	do
	{
		for (int i = 1; i <= numbers.size(); ++i)
		{
			auto num = stoi(numbers.substr(0, i));
			if (isPrime(num))
				answer.insert(num);
		}

	} while (next_permutation(numbers.begin(), numbers.end()));

	return answer.size();
}

int main()
{
	//cout << solution("17") << endl;
	string s0 = "17";
	sort(s0.begin(), s0.end());
	cout << boolalpha;
	cout << s0 << endl;
	cout << next_permutation(s0.begin(), s0.end()) << endl;
	cout << s0 << endl;
}