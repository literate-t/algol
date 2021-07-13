#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    for (int i = 0; i < prices.size(); ++i)
    {
        int count = 0;
        bool flag = false;
        for (int j = i + 1; j < prices.size(); ++j)
        {
            ++count;
            if (prices[j] < prices[i])
            {
                answer.push_back(count);
                flag = true;
                break;
            }
        }
        if (!flag) answer.push_back(count);
    }
    return answer;
}

int main()
{
    auto result = solution({ 1, 2, 3, 2, 3 });
    for (int n : result)
        cout << n;
    cout << endl;
}