#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, a, b, sa = 100, sb = 100;
	cin >> N;
	while (N--) {
		cin >> a >> b;
		if (a > b) sb -= a;
		if (b > a) sa -= b;
	}
	cout << sa << '\n' << sb << '\n';
	return 0;
}