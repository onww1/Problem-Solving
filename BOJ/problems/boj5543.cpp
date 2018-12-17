#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int minBurger=2000, minDrink=2000, in;

	for(int i=0; i<3; i++)
	{
		cin >> in;
		if(in < minBurger)
			minBurger = in;
	}

	for(int i=0; i<2; i++)
	{
		cin >> in;
		if(in < minDrink)
			minDrink = in;
	}

	cout << (minBurger + minDrink - 50) << '\n';

	return 0;
}