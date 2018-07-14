#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum=0, a;
	for(int i=0; i<4; i++)
	{
		cin >> a;
		sum += a;
	}

	cout << (sum/60) << '\n' << (sum%60) << '\n';
	return 0;
}