#include <cstdio>
int main()
{
	int N;
	scanf("%d", &N);
	int d[100000] = {};
	int arr[100000] = {};
	int answer = 0;
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	d[0] = arr[0];
	for (int i = 1; i < N; ++i)
		d[i] = d[i - 1] + arr[i] > d[i - 1] ? d[i - 1] + arr[i] : d[i - 1];
	
	for (int i = 0; i < N; ++i)
		answer = answer < d[i] ? d[i] : answer;
	printf("%d", answer);
}
/*
* d[i] -> i��° ��Ҹ� �������� �������� ���� ���� ���� ū ��
* d[i] -> max(d[i-1] + arr[i], d[i-1])
* 
* 10 -4 3 1 5 6 -35 12 21 -1
* 
*/