#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int min = 0, man = 0, a;
	for(int i=0; i<4; i++)
	{
		cin >> a;
		min += a;
	}
	for(int i=0; i<4; i++)
	{
		cin >> a;
		man += a;
	}

	cout << (min>man?min:man) << '\n';
	return 0;
}