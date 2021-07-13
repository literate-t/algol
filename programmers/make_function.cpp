#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int get_days(int rest, int speed)
{
    if (rest % speed == 0)
        return rest / speed;
    return rest / speed + 1;
}

//vector<int> solution(vector<int> progresses, vector<int> speeds)
//{
//    vector<int> answer;
//    queue<int> complete_days;
//
//    for (int i = 0; i < progresses.size(); ++i)
//    {
//        int rest = 100 - progresses[i];
//        complete_days.push(get_days(rest, speeds[i]));
//    }
//    int count = 1;
//    int prev = complete_days.front();
//    complete_days.pop();
//    while (!complete_days.empty())
//    {
//        int curr = complete_days.front();
//        complete_days.pop();
//
//        if (prev >= curr)
//            ++count;
//        else
//        {
//            answer.push_back(count);
//            count = 1;
//            prev = curr;
//        }
//    }    
//    answer.push_back(count);
//    return answer;
//}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> complete_days;

    for (int i = 0; i < progresses.size(); ++i)
        progresses[i] = (get_days(100 - progresses[i], speeds[i]));

    int prev = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        if (answer.empty() || prev < progresses[i])
        {
            answer.push_back(1);            
            prev = progresses[i];
        }
        else
        {
            ++answer.back();
        }
    }
    return answer;
}

int main()
{
    auto result = solution({ 93, 30, 55 }, { 1, 30, 5 });
    for (int n : result)
    {
        cout << n << endl;
    }
}