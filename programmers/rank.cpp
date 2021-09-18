#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/*
    �÷��̵�-�ͼ� �˰���
    -��� ��ο� ���� �ִ� ��θ� ã�´�

    �� ������ �����ϴ� ��
    - �־��� ���� {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}
    - {A, B}���� A�� B�� �׻� �̱��
    - 2�� �� ���� ��⸦ �ϹǷ� ������ Ȯ�������� ��������
    - 5���� 2������ Ȯ���ϰ� ���� �Ŷ��, 2�� �̱�� ��� �������Ե� ����.
    - {4, 5}, {3, 5}, {1, 5}, {2, 5}�� �����Ѵ�.
    - �̴� {4,2} {2,5}���� {4,5}�� ����� ���̴�.
    - �׷��Ƿ� �÷��̵�-�ͼ� �˰����� ������ �� �ִ�.
*/
int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    // ������ 1���� �����ϹǷ� �迭�� ���� �� 1�� ���Ѵ�
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));

    // �⺻ ����
    for (auto i : results)
        win[i[0]][i[1]] = true;

    // �⺻ ���¸� �̿��ؼ� ��� ������ ����
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                if (win[j][i] && win[i][k])
                    win[j][k] = true;

    // ������ n���� �� �� ������ ��� ������ �ٴ� Ƚ���� n-1
    for (int i = 1; i <= n; ++i)
    {
        int count = 0;
        for (int j = 1; j <= n; ++j)
        {
            // �̱�ų� ���ų� ��� ��ü�� ī��Ʈ
            if (win[i][j] || win[j][i])
                ++count;
        }
        if (n - 1 == count) ++answer;
    }
    return answer;
}

int main()
{
    auto res = solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} });
    printf("%d\n", res);
}