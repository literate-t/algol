#include <cstdio>
#include <queue>
#include <vector>
int min(int a, int b)
{
	return a < b ? a : b;
}
int absolute(int a)
{
	return a < 0 ? -a : a;
}
int main()
{
	int n = 5;
	std::vector<int> c = { 0, 4 };
	std::priority_queue<int> pq;
	for (size_t i = 0; i < n; ++i)
	{
		int min_val = 100'000;
		for (size_t j = 0; j < c.size(); ++j)
			min_val = min(absolute(i - c[j]), min_val);
		pq.push(min_val);
	}
	printf("%d\n", pq.top());
}