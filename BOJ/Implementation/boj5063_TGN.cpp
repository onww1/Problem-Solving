#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int r, e, c;
	while(n--)
	{
		cin >> r >> e >> c;
		if(r < e - c)
		{
			cout << "advertise" << '\n';
		}
		else if(r > e - c)
		{
			cout << "do not advertise" << '\n';
		}
		else
		{
			cout << "does not matter" << '\n';
		}
	}
	
	return 0;
}