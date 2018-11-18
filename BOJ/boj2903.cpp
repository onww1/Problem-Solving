#include <iostream>
using namespace std;

int pow(int x, int n) {
	int a = 1;
	for (int i=0; i<n; i++) {
		a *= x;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int a = pow(2, n) + 1;
	cout << (a * a) << '\n';
	return 0;
}