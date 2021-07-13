#include <string>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool is_prime(int number)
{
    if (number == 0 || number == 1) return false;
    for (int i = 2; i < number; ++i)
        if (number % i == 0)
            return false;
    return true;
}

int solution(string numbers) {
    set<int> answer;
    sort(numbers.begin(), numbers.end());
    do
    {
        for (int i = 1; i <= numbers.size(); ++i)
        {
            int number = stoi(numbers.substr(0, i));
            if (is_prime(number))
                answer.insert(number);                
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    return answer.size();
}

int main()
{
    cout << solution("17") << endl;
}