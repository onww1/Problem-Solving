#include <iostream>
using namespace std;

int cal(int n)
{
	int num = 1;

	while(n>0)
	{
		if(n/10 > 0) num++;
		n/=10;
	}

	return num;
}

int f(int a)
{
	int result = 1;
	for(int i=2; i<=a; i++)
		result *= 10;
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int a[9] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000};
	long sum = 0;

	int num = cal(n);
	for(int i=1; i<num; i++)
	{
		sum += (i * a[i]);
	}
	sum += (num * (n+1-f(num)));
	cout << sum << '\n';
	return 0;
}