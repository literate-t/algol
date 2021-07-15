#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(begin(people), end(people));
    int less_idx = 0;
    for (int i = people.size() - 1; i >= less_idx; --i)
    {
        ++answer;
        if (people[less_idx] + people[i] > limit) continue;
        else
            ++less_idx;
    }

    return answer;
}
/*
*   70, 50, 80, 50
*   50, 50, 70, 80 / limit 100
* 
*   40, 40, 50, 70, 80, 100 / limit 100
*   50, 60, 70, 80, 100     / 120

* 
* 
*   70, 80, 50     / limit 100
*   50, 70, 80
* 
* 
*/
int main()
{
    cout << solution({ 70, 50, 80, 50 }, 100) << endl;
    cout << solution({ 70, 80, 50 }, 100) << endl;
}