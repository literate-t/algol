#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

long long init(vector<long long>& tree, vector<long long>& arr, int node, int start, int end)
{
	if (start == end) 
		return tree[node] = arr[end];
	else 
	{
		int mid = (start + end) / 2;		
		return tree[node] = init(tree, arr, node * 2, start, mid) + init(tree, arr, node * 2 + 1, mid + 1, end);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int sum_start, int sum_end)
{
	if (start > sum_end  || sum_start > end) return 0;
	else if (sum_start <= start && end <= sum_end ) return tree[node];
	else
	{
		int mid = (start + end) / 2;
		return sum(tree, node * 2, start, mid, sum_start, sum_end) + sum(tree, node * 2 + 1, mid + 1, end, sum_start, sum_end);
	}
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (end != start)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m += k;
	vector<long long> arr(n);
	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	for (int i = 0; i < n; ++i)
		scanf("%lld", &arr[i]);
	
	init(tree, arr, 1, 0, n - 1);
	while (m--)
	{
		int a;
		scanf("%d", &a);
		if (1 == a) // b번째 수를 c로 변경
		{
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			b -= 1;
			long long diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, 0, n - 1, b, diff);
		}
		else if (2 == a) // 구간 합 (b~c)
		{
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(tree, 1, 0, n - 1, b - 1, c - 1));
		}
	}
}