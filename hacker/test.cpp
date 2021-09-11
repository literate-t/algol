#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<string> split(string s, string delim)
{
	size_t off = 0;
	vector<string> result;
	while (true)
	{
		size_t pos = s.find(delim, off);
		size_t count = pos - off;
		string str = s.substr(off, count);
		result.push_back(str);
		off += count + 1;
		if (0 == off) break;
	}
	return result;
}

int main()
{
	//auto res = encryption("chillout");
	//cout << res << endl;
	string delim = " ";
	auto res = split("I am sorry but I love you ´Ù °ÅÁþ¸»", delim);
	for (string str : res)
		cout << str << endl;
}