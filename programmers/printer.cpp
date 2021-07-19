#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int, int>> index_value_q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); ++i)
    {
        index_value_q.push({ i, priorities[i] });
        pq.push(priorities[i]);
    }

    while (!pq.empty())
    {
        auto [index, value] = index_value_q.front();
        if (pq.top() == value)
        {
            if (location == index)
                return answer;
            else
            {
                ++answer;
                pq.pop();
                index_value_q.pop();
            }
        }
        else
        {
            index_value_q.push({ index, value });
            index_value_q.pop();
        }
    }
}

//int solution(vector<int> priorities, int location)
//{
//    vector<int> numbers;
//    queue<int> index_queue;
//    for (size_t i = 0; i < priorities.size(); ++i)
//        index_queue.push(i);
//    while (!index_queue.empty())
//    {
//        int index = index_queue.front();
//        index_queue.pop();
//        if (*max_element(begin(priorities), end(priorities)) != priorities[index])
//            index_queue.push(index);
//        else
//        {
//            priorities[index] = 0;
//            numbers.push_back(index);
//        }
//    }
//    for (size_t i = 0; i < numbers.size(); ++i)
//        if (numbers[i] == location)
//            return i + 1;
//}

int main()
{
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
}