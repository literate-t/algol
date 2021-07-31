#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Truck
{
    int weight = 0;
    int tick = 0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0, sum = 0, index = 0;
    vector<Truck> trucks;
    vector<int> after_bridge;
    queue<int> on_bridge;

    for (int i = 0; i < truck_weights.size(); ++i)
    {
        Truck truck;
        truck.weight = truck_weights[i];
        trucks.push_back(truck);
    }
    while(true)
    {
        ++answer;
        if (index < trucks.size() && on_bridge.size() < bridge_length
            && sum + trucks[index].weight <= weight)
        {
            auto weight = trucks[index++].weight;
            sum += weight;
            on_bridge.push(weight);
        }
        for (int i = 0; i < index; ++i)
        {
            if (trucks[i].tick == -1) continue;
            ++trucks[i].tick;
            if (trucks[i].tick == bridge_length)
            {
                trucks[i].tick = -1;
                auto t = on_bridge.front();
                on_bridge.pop();
                sum -= t;
                after_bridge.push_back(t);                
            }
        }      
        if (after_bridge.size() == trucks.size()) break;
    }

    return ++answer;
}

/*
* #include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0, sum = 0, index = 0;
    queue<pair<int, int>> bridge;
    while (true)
    {
        ++answer;
        if (!bridge.empty() && answer - bridge.front().second == bridge_length)
        {
            sum -= bridge.front().first;
            bridge.pop();
        }

        if (index <= truck_weights.size() - 1 && sum + truck_weights[index] <= weight && bridge.size() < bridge_length)
        {
            auto truck = truck_weights[index++];
            sum += truck;
            bridge.push({ truck, answer });
        }

        if (bridge.empty())
            break;
    }
    return answer;
}
*/

int main()
{
    cout << solution(2, 10, { 7,4,5,6 }) << endl;
    cout << solution(100, 100, { 10 }) << endl;
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
}