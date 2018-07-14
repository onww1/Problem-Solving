#include <iostream>
using namespace std;

int diff(int a, int b)
{
	return a>b?a-b:b-a;
}
int main(int argc, char const *argv[])
{
	int s[10];
	for(int i=0; i<10; i++)
		cin >> s[i];

	int sum = 0;
	for(int i=0; i<10; i++)
	{
		if(diff(sum, 100) > diff(sum+s[i], 100))
			sum += s[i];
		else if(diff(sum, 100) == diff(sum+s[i], 100))
		{
			sum += s[i];
			break;
		}
		else
			break;
	}

	cout << sum << '\n';
	return 0;
}