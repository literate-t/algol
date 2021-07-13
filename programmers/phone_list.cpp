#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) 
{
    sort(begin(phone_book), end(phone_book));
    for (int i = 0; i < phone_book.size()-1; ++i)
    {
        if (phone_book[i + 1].find(phone_book[i]) == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << solution({ "12","123","1235","567","88" }) << endl;
}