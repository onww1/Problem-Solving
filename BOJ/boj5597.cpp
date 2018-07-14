#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	bool ok[31] = {false, };
	int c;
	for(int i=0; i<28; i++)
	{
		cin >> c;
		ok[c] = true;
	}

	for(int i=1; i<=30; i++)
	{
		if(!ok[i])
			cout << i << '\n';
	}
	return 0;
}