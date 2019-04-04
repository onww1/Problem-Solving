#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0, min = 100, in;
	for(int i=0; i<7; i++)
	{
		cin >> in;
		if(in%2 == 1)
		{
			sum += in;
			if(min > in) 
				min = in;
		}
	}

	if(min == 100) cout << -1 << '\n';
	else cout << sum << '\n' << min << '\n';

	return 0;
}