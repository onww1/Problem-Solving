#include <iostream>
using namespace std;

int cal(int n)
{
	int num = 1;
	int div = 2;
	int cnt = 0;
	while(n > 1)
	{
		if(n%div == 0)
		{
			cnt++;
			n/=div;
		}
		else
		{
			num *= (cnt+1);
			cnt = 0;
			div++;
		}
	}

	return (num+1)/2;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int sum = 1;
	for(int i=2; i<=n; i++)
	{
		sum += cal(i);
	}

	cout << sum << '\n';
	return 0;
}