#include <string>
#include <vector>
#include <queue>
#include <iostream>
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
/*
*   ABCD
*   2132
* 
*   CDAB
*   3221
*/
int main()
{
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
}