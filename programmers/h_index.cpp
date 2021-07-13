#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    for (int h_index = 0; h_index <= citations.size(); ++h_index)
    {
        int more = 0;
        int less = 0;
        for (int j = 0; j < citations.size(); ++j)
        {
            if (h_index <= citations[j])
                ++more;
            else if (h_index >= citations[j])
                ++less;
        }
        if (more >= h_index && less <= h_index)
            answer = h_index;
    }
    return answer;
}

int main()
{
    cout << solution({ 3, 0, 6, 1, 5 }) << endl;
    // 6 5 3 1 0
}