#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	long S;
	cin >> S;

	cout << floor((-1.0 + sqrt(1.0 + 8.0 * (double)S))/2.0) << '\n';

	return 0;
}
