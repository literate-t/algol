#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = yellow; i >= 0; --i) {
        if (yellow % i != 0) continue;
        else if (i * 2 + (yellow / i) * 2 + 4 == brown) {
            answer.push_back(i + 2);
            answer.push_back(yellow / i + 2);
            break;
        }
    }
    return answer;
}

int main()
{
    auto result = solution(24, 24);
    for (int n : result)
        cout << n << " ";
    //auto result = sqrt(63);
    //cout << result;
}