#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) 
{
    long long answer = 0;
    long long low = 1, high = 0;
    size_t size = times.size();
    for (size_t i = 0; i < size; ++i)
        high = high < times[i] ? times[i] : high;
    high = high * n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long sum = 0;
        for (size_t i = 0; i < size; ++i)
            sum += mid / times[i];
        if (n <= sum)
        {
            answer = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return answer;
}

int main()
{
    cout << solution(6, { 7, 10 }) << endl;
}