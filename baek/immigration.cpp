#include <cstdio>
int main()
{
	int N, M;
	int e[100000] = {};
	scanf("%d%d", &N, &M);
	long long high = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &e[i]);
		high = high < e[i] ? e[i] : high;
	}

	high = high * M;
	long long low = 1;
	// long long answer = 0;
	while (low <= high)
	{
		long long m = 0;
		long long mid = (low + high) / 2;		
		for (int i = 0; i < N; ++i)
			m += mid / e[i];
		if (m < M)
			low = mid + 1;
		else
		{
			//answer = mid;
			high = mid - 1;
		}
	}
	printf("%lld\n", low);
	//printf("%lld\n", answer);
}
/*
  �̺� Ž���� ���� �ִ밪 ���ϱ�
  �ִ� ���� �ɻ��Ⱑ ���� ���� �ɸ��� �ð� * �ο� ��
* 1�� �ɻ��� 7��
* 2�� �ɻ��� 10���� �ɸ���
* �ɻ� �ο��� 6��
* �ɻ縦 ��ġ�µ� �ɸ��� �ð��� �ּ� ��
*
* �־��� �ɻ�븦 �������� �����غ���.
* 10���� �ð��� �־����ٸ�
* 10/10 + 10/7 = 2
* 2���� �Ա��ɻ縦 ���� �� ����
* 
* 15���� �ð��� �־����ٸ�
* 15/10 + 15/7 = 3
* 3���� �Ա��ɻ縦 ���� �� ���� * 
* 14�е�
* 14/10 + 14/7 = 3
* 3����
* 
*/