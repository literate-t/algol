#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<int>> container{ {0, 2, 1}, {1, 1, 1}, {2, 0, 0} };
	size_t size = container.size();
	vector<int> each_container(size, 0);
	vector<int> each_type(size, 0);
	
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			each_container[i] += container[i][j];
			each_type[j] += container[i][j];
		}
	}
	sort(each_container.begin(), each_container.end());
	sort(each_type.begin(), each_type.end());
	for (size_t i = 0; i < size; ++i)
	{
		if (each_container[i] != each_type[i])
		{
			printf("Impossible\n");
			return 0;
		}
	}	
	printf("Possible\n");
}
