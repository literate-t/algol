#include <cstdio>

/*
	유클리드 호제법
	두 수 a, b가 있고(a > b)
	a를 b로 나눈 나머지인 r이 있을 때
	a, b의 최대공약수는
	b, r의 최대공약수와 같다
	이 성질에 따라 b를 r로 나눈 나머지 r1을 구하고
	다시 r을 r1로 나눈 나머지를 구하는 과정을 반복해
	나머지가 0이 되었을 때 '나누는 수'가 a와 b의 최대 공약수다
	최소 공배수는 두 수를 곱해서 최대 공약수로 나누면 된다
	
*/
int gcd(int a, int b)
{
	int r = -1;
	while (0 != r)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b, int g)
{
	return a * b / g;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int g = gcd(a, b);
	int l = lcm(a, b, g);
	printf("%d %d\n", g, l);
}