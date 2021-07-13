#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); ++i)
		pq.push(scoville[i]);
	int count = 0, a = 0, b = 0;
	while (!pq.empty())
	{
		a = pq.top();
		pq.pop();
		if (a >= K)
			return count;
		else if (pq.size() == 0)
			return -1;
		++count;
		b = pq.top();
		pq.pop();
		a = a + b * 2;
		pq.push(a);
	}
}

int main()
{
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7) << endl;;
}

/*
* scoville	K	return
[1, 2, 3, 9, 10, 12]	7	2
*/