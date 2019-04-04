#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int p[1000];

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> p[i];
	}

	sort(p, p+n);

	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum += p[i];
		if(i+1 < n) p[i+1] += p[i];
	}

	cout << sum << '\n';
	return 0;
}