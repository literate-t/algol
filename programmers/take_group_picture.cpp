#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> condition;
int N;

int get_abs(int val)
{
    return val < 0 ? -val : val;
}

bool is_correct(string& member)
{
    for (int i = 0; i < N; ++i)
    {
        bool flag = false;
        auto f1 = condition[i][0];
        auto f2 = condition[i][2];
        auto op = condition[i][3];
        auto dist = condition[i][4] - '0';
        
        auto diff = get_abs(member.find(f1) - member.find(f2)) - 1;
        if (op == '=')
            flag = dist == diff ? true : false;
        else if (op == '<')
            flag = diff < dist ? true : false;
        else if (op == '>')
            flag = diff > dist ? true : false;
        if (!flag)
            return false;
    }
    return true;
}

int solution(int n, vector<string> data) 
{
    int answer = 0;
    string member = "ACFJMNRT";
    condition = data;
    N = n;
    do
    {
        if (is_correct(member))
            ++answer;
    } while (next_permutation(begin(member), end(member)));
    return answer;
}

int main()
{
    printf("%d\n", solution(2, { "N~F=0", "R~T>2" }));
}