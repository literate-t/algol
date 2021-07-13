#include <iostream>
using namespace std;
int d[5001];
int main()
{
	for (int i = 0; i < 5001; ++i)
		d[i] = 5000;
	int N;
	cin >> N;
	d[3] = d[5] = 1;
	for (int i = 6; i <= N; ++i)
		d[i] = min(d[i - 3] + 1, d[i - 5] + 1);
	cout << (d[N] >= 5000 ? -1 : d[N]) << endl;
}

/*
* d[18] -> 4
* d[3] -> 1 d[6]-> 2, d[9]-> 3, d[12] -> 4, d[15] -> 5
* d[5] -> 1,  d[10]-> 2,  d[15] -> 3, d[18]-> 4
*				d[13]->3
* 
* d[i] = min(d[i-5] + 1, d[i-3] + 1)
*/