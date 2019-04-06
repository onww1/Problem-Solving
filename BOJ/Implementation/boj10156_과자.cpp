#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << ( (a*b)-c>=0?(a*b-c):0 ) << '\n';
	return 0;
}