#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0, n;
	for (int i=0; i<5; ++i) {
		cin >> n;
		sum += n;
	}
	cout << sum << '\n';
	return 0;
}