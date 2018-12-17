#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, arr[10][10], cnt;
	cin >> t;
	for(int test_case = 1; test_case <= t; test_case++)
	{
		cin >> n;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin >> arr[i][j];
			}
		}

		cnt = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				int check[4] = {0, 0, 0, 0};
				for(int r=i-1; r<=i+1; r++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						if(r<0 || r>=n || c<0 || c>=n) 
							continue;
						check[arr[r][c]]++;
					}
				}
				if(check[0]) 
					continue;
				else if(check[1] && check[2] && check[3]) 
					cnt++;
			}
		}

		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;
}