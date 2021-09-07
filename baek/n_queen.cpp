#include <cstdio>
int rows[15];
int answer;
int N;
/*
	rows[0] = 1 -> 0번째 행의 1열에 체스 놓기
*/
int abs(int a)
{
	return a < 0 ? -a : a;
}
bool test(int row)
{
	for (int i = 0; i < row; ++i)
		if (rows[i] == rows[row] || abs(rows[i] - rows[row]) == row - i)
			return false;
	return true;;
}
void n_queen(int row)
{
	if (N == row)
	{
		++answer;
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		rows[row] = i;
		if (test(row))
			n_queen(row + 1);
	}
}

int main()
{
	scanf("%d", &N);
	n_queen(0);
	printf("%d\n", answer);
}