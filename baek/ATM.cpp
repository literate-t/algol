#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int answer = 0;
	for (int i = 0; i < n; ++i)
		answer += arr[i] * (n - i);
	delete[] arr;
	printf("%d\n", answer);
}

/*
*  1 2 3 -> 1, 1+2, 1+2+3 ->10
*  2 1 3 -> 2, 2+1, 2+1+3 ->11
*  3 1 2 -> 3, 3+1, 3+1+2 ->13
*/