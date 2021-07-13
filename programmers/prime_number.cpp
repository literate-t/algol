#include <vector>
#include <iostream>
#include <set>
using namespace std;
/*
*   주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 
    숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, 
    nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 
    소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.
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