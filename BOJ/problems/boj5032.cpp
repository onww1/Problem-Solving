#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int e, f, c;
	cin >> e >> f >> c;
	int sum = 0;

	e += f;
	while(e >= c)
	{
		sum += e/c;
		f = e/c;
		e -= (c * (e/c));
		e += f;
	}	
	cout << sum << '\n';
	return 0;
}