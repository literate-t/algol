#include <vector>
#include <iostream>
#include <set>
using namespace std;
/*
*   �־��� ���� �� 3���� ���� ������ �� �Ҽ��� �Ǵ� ����� ������ ���Ϸ��� �մϴ�. 
    ���ڵ��� ����ִ� �迭 nums�� �Ű������� �־��� ��, 
    nums�� �ִ� ���ڵ� �� ���� �ٸ� 3���� ��� ������ �� 
    �Ҽ��� �Ǵ� ����� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/
int solution(vector<int> nums) {
    int answer = 0;
    set<int> temp_nums;
    int size = nums.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            for (int k = 2; k < size; ++k)
            {
                temp_nums.insert(nums[i] + nums[j] + nums[k]);
            }
        }
    }   
    return answer;
}

int main()
{
    cout << solution({ 1, 2, 7, 6, 4 }) << endl;
}