#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int time = 0, next_truck = 0, sum = 0;
    queue<pair<int, int>> bridge;
    while (true)
    {
        ++time;
        if (bridge.size() < bridge_length &&
            sum + truck_weights[next_truck] <= weight)
        {
            auto truck = truck_weights[next_truck++];
            sum += truck;
            bridge.push({ time, truck });
        }
        auto [t, truck] = bridge.front();
        if ((time - t) == bridge_length - 1)
        {
            auto [t, truck] = bridge.front();
            sum -= truck;
            bridge.pop();
        }
        if (next_truck > truck_weights.size() - 1) break;
    }
    return time + bridge_length;
}

int main()
{
    cout << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << solution(100, 100, {10}) << endl;
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
}