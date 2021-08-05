#include <iostream>
using namespace std;
#include <cmath>
int solution(int n, int a, int b)
{
    int answer = 0;
    while (a != b)
    {
        a = ceil(a / 2.f);
        b = ceil(b / 2.f);
        //a = (a + 1) >> 1;
        //b = (b + 1) >> 1;
        ++answer;
    }
    return answer;
}
/*
* 
* 1 2 3 4 5 6 7 8
* 1seed-> 1,2
* 2seed-> 3,4
* 3seed-> 5,6
* 4seed-> 7,8
* 2seed와 4seed가 언제 만나나
*  
* 1 2 3 4 
* 1 2
* 
* 101
*/
int main()
{
    cout << solution(8, 4, 7) << endl; // 3
}