#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) 
{    
    vector<int> answer;
    size_t size = s.size();
    vector<vector<int>> numbers;
    vector<int> nums;
    string str;
    for (size_t i = 1; i < size - 1; ++i)
    {
        char c = s[i];        
        if (c == '}')
        {
            numbers.push_back(nums);
            nums.clear();
        }
        else if(c >= '0' && c <= '9')
        {
            str += c;
            if (s[i + 1] == ',' || s[i + 1] == '}')
            {
                nums.push_back(stoi(str));
                str = "";
            }
        }
    }
    if (numbers.size() == 1)
        return numbers[0];
    sort(begin(numbers), end(numbers), [](vector<int>& a, vector<int>& b) {
        return a.size() < b.size();
        });
    vector<bool> flag(1000000);
    printf("%zu\n", sizeof(flag) * sizeof(bool));
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        for (size_t j = 0; j < numbers[i].size(); ++j)
        {
            auto n = numbers[i][j];
            if (flag[n] == false)
            {
                answer.push_back(n);
                flag[n] = true;
            }
            //if (answer.empty())
            //    answer.push_back(n);
            //else if (answer.end() == find(answer.begin(), answer.end(), n))
            //        answer.push_back(n);
        }
    }
    return answer;
}

int main()
{
    auto res = solution("{{20,111},{111}}");
    for (int num : res)
        printf("%d\n", num);
}