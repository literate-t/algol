#include <cstdio>

/*
	��Ŭ���� ȣ����
	�� �� a, b�� �ְ�(a > b)
	a�� b�� ���� �������� r�� ���� ��
	a, b�� �ִ�������
	b, r�� �ִ������� ����
	�� ������ ���� b�� r�� ���� ������ r1�� ���ϰ�
	�ٽ� r�� r1�� ���� �������� ���ϴ� ������ �ݺ���
	�������� 0�� �Ǿ��� �� '������ ��'�� a�� b�� �ִ� �������
	�ּ� ������� �� ���� ���ؼ� �ִ� ������� ������ �ȴ�
	
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