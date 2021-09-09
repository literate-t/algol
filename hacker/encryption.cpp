#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s = "if man was meant to stay on the ground god would have given us roots";
	//string s = "clu hlt io"
	while (s.find(" ") != (size_t)-1)
		s.replace(s.find(" "), 1, "");
	size_t length = s.size();
	size_t row = floor(sqrtf(length));
	size_t column = ceil(sqrtf(length));
	if (row * column < length)
		++row;
	vector<string> str;
	size_t start = 0;
	for (size_t i = 0; i < row; ++i)
	{
		str.push_back(s.substr(start, column));
		start += column;
	}
	string answer = "";
	for (size_t i = 0; i < column; ++i)
	{		
		for (string s : str)
		{
			if (i > s.size() - 1) break;
			answer += s[i];
		}
		answer += ' ';
	}
	printf("%s\n", answer.c_str());
}