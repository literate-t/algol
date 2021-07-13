#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n;
	auto res = scanf("%d", &n);
	std::vector<int> d(n + 1, 0);
	d[2] = d[3] = 1;
	for (int i = 4; i <= n; ++i)
	{
		d[i] = d[i - 1] + 1;
		if (0 == i % 3)
			d[i] = min(d[i], d[i / 3] + 1);
		if (0 == i % 2)
			d[i] = min(d[i], d[i / 2] + 1);
	}
	printf("%d\n", d[n]);
}