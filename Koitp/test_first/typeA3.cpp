#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, s, j, k;
	int rest[1000];

	cin >> t;
	for(int test_case=1; test_case<=t; test_case++)
	{
		cin >> n >> s >> j >> k;
		for(int i=0; i<k; i++)
		{
			cin >> rest[i];
		}

		sort(rest, rest+k);
		
		int cnt = 0;
		j++;
		for(int i=0; i<k; i++)
		{
			if(rest[i] < s) continue;
			else if((rest[i]-s)%j == 0) cnt++;
		}

		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;
}