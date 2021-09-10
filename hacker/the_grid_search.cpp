#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string gridSearch(vector<string> G, vector<string> P)
{
	for (size_t i = 0; i < G.size(); ++i)
	{
		if (i > G.size() - P.size())
			break;
		size_t col = 0;
		while (true)
		{
			col = G[i].find(P[0], col);
			if (string::npos == col)
				break;
			else
			{
				size_t index = i + 1;
				bool flag = true;
				for (size_t j = 1; j < P.size(); ++j)
				{
					string temp = G[index++].substr(col, P[j].size());
					if (temp != P[j])
					{
						flag = false;
						break;
					}
				}
				if (true == flag)
					return "YES";
			}
			++col;
		}
	}
	return "NO";
}
int main()
{
	vector<string> G = {
		"111111111111111",
		"111111111111111",
		"111111111111111",
		"111111111111111",
		"111111111111111",
		"111111111111111",
		"101010101010101"
	};
	vector<string> P = {
	"11111",
	"11111",
	"11111",
	"11110"
	};
	auto result = gridSearch(G, P);
	printf("%s\n", result.c_str());
}