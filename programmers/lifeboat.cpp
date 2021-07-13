#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(people.begin(), people.end());
    int i = 0;
    for (int j = people.size() - 1; j >= i; --j)
    {
        if (people[i] + people[j] <= limit)
            ++i;
        ++answer;
    }
    return answer;
}
int main()
{
    cout << solution({ 50, 50, 70, 80 }, 100) << endl;
    cout << solution({ 50, 70, 80 }, 100) << endl;
}