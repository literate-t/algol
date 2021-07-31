#include <string>
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

int main()
{
    printf("%d\n", solution(2, 10, { 7,4,5,6 }));
    printf("%d\n", solution(100, 100, { 10 }));
    printf("%d\n", solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }));
}