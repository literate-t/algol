/*
	���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�. 
	����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.
	�� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, 
	���� �������� ���� �� �ִ� �Ҽ��� �� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

	sol>
	1. next_permutation�� �ݺ��ؼ� ������
	2. ���� ������ �߶� ���ڷ� ��ȯ�Ѵ�("1234"�� ���, 1, 12, 123, 1234)
	3. �Ҽ��� ��� set �����̳ʿ� �ִ´�
	3. 1������
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