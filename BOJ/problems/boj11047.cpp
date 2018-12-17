#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;

	int val[10];
	for(int i=0; i<n; i++) cin >> val[i];

	int num = 0;
	for(int i=n-1; i>=0; i--)
	{
		if(k/val[i] > 0)
		{
			num += k/val[i];
			k = k - (k/val[i])*val[i];
			if(k == 0) break;
		}
	}

	cout << num << '\n';
	return 0;
}