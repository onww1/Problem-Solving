#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;

	int arr[1001] = {1, 1, 0, };
	bool loop = true;
	int idx = 2;
	while(loop)
	{
		while(arr[idx]) idx++;
		int c = 1;
		while(idx * c <= n)
		{
			if(!arr[idx * c])
			{	
				arr[idx * c] = 1;
				k--;
				if(k == 0)
				{
					cout << (idx * c) << '\n';
					loop = false;
					break;
				}
			}
			c++;
		}
	}

	return 0;
}