#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) 
{
    string answer = "";
    while (n)
    {
        if (n % 3 != 0)
        {
            answer.insert(0, to_string(n % 3));
            n /= 3;
        }
        else
        {
            answer.insert(0, "4");
            n = n / 3 - 1;
        }
    }
    return answer;
}

int main()
{
    cout << solution(4) << endl;
    cout << solution(13) << endl;
}