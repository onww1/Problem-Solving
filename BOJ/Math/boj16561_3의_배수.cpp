#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	N /= 3;
	if (N < 3) cout << 0 << '\n';
	else cout << ((N-1) * (N-2) / 2) << '\n';
	return 0;
}