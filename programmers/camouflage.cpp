#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> c;
    for (int i = 0; i < clothes.size(); ++i)
        ++c[clothes[i][1]];
    if (c.size() == 1)
        return c.begin()->second;
    else
        for (auto [key, value] : c)
            answer *= value + 1;
    return answer - 1;
}
int main()
{
    cout << solution({ {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} }) << endl;
    cout << solution({ {"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"} }) << endl;
}