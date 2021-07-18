#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> split(string str, string delim)
{
    vector<string> result;
    size_t pos = 0, curr = 0;
    while (string::npos != pos)
    {
        pos = str.find(delim, curr);
        string temp = str.substr(curr, pos - curr);
        result.push_back(temp);
        curr = pos + 1;
    }
    return result;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    string delim = " ";
    map<string, string> m;
    for (string str : record)
    {
        auto result = split(str, delim);
        if (2 == result.size()) continue;
        else
            m[result[1]] = result[2];
    }
    for (string str : record)
    {
        string temp;
        auto result = split(str, delim);
        auto status = result[0];
        if ("Enter" == status)
            temp = m[result[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        else if ("Leave" == status)
            temp = m[result[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        else continue;
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
    auto res = solution(
        { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    for (string s : res)
    {
        cout << s << endl;
    }
}