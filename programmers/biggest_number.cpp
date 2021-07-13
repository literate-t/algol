#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    
    string answer = "";
    vector<string> strings;
    for (size_t i = 0; i < numbers.size(); ++i)
        strings.push_back(to_string(numbers[i]));

    sort(strings.begin(), strings.end(), [](string& a, string& b) {
        return (a + b) > (b + a);
        });
    for (size_t i = 0; i < strings.size(); ++i)
        answer.append(strings[i]);
    if (answer[0] == '0')
        return "0";
    return answer;
}

int main()
{
    cout << solution({ 0, 0, 0 }) << endl;
}