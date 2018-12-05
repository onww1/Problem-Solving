#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X, N, in;
	cin >> X >> N;
	X *= (N+1);
	while (N--) {
		cin >> in;
		X -= in;
	}
	cout << X << '\n';
	return 0;
}