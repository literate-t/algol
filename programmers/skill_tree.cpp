#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        auto skill_tree = skill_trees[i];
        bool flag = true;
        int index = 0;
        for (int j = 0; j < skill_tree.size(); ++j)
        {
            for (int k = 0; k < skill.size(); ++k)
            {
                if (skill_tree[j] == skill[k] && index != k)
                {
                    flag = false;
                    index = 0;
                    break;
                }
                else if (skill_tree[j] == skill[k] && index == k)
                {
                    ++index;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) ++answer;
    }
    return answer;
}

int main()
{
    cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" }) << endl;
}