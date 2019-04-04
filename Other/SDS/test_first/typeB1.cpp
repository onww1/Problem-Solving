#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, p, m, num[100000];
	long res;

	cin >> t;
	for(int test_case = 1; test_case <= t; test_case++)
	{
		cin >> n >> p >> m;
		for(int i=0; i<n; i++) 
			cin >> num[i];

		sort(num+1, num+n);
		res = num[0];

		for(int i=0; i<n-1; i++)
		{
			if(i<m) res -= (long)num[i+1];
			else res += (long)num[i+1];
		}

		cout << "#" << test_case << " " << res << '\n';
	}
	return 0;
}