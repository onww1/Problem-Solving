#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, color[200000], size[200000], sum[200000];

	cin >> n;

	for(int i=0; i<n; i++)
	{
		sum[i] = 0;
		cin >> color[i] >> size[i];
	}

	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(color[i] == color[j]) continue;
			else if(size[i] > size[j]) sum[i] += size[j];
			else if(size[i] < size[j]) sum[j] += size[i];
		}
	}

	for(int i=0; i<n; i++)
	{
		cout << sum[i] << '\n';
	}

	return 0;
}