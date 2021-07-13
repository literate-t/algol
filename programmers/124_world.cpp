#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) 
{
    string answer = "";
    while (n)
    {
        if (n % 3)
        {
            int a = n % 3;
            answer.insert(0, to_string(a));
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

}