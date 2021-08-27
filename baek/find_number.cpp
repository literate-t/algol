#include <cstdio>
#include <algorithm>
int A[100000];
int N;
int binary_search(int find)
{
	int low = 0, high = N - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (find < A[mid])
			high = mid - 1;
		else if (find > A[mid])
			low = mid + 1;
		else
			return 1;
	}
	return 0;
}
int main()
{
	int find[100000] = {};
	int M;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	std::sort(&A[0], &A[N]);
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
		scanf("%d", &find[i]);
	for (int i = 0; i < M; ++i)
		printf("%d\n", binary_search(find[i]));
}