#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);

	int gcd_val = b;
	while (a % gcd_val) {
		b = a % gcd_val;
		a = gcd_val;
		gcd_val = b;
	}
	return gcd_val;
}

void solve(int a, int b) {
	int gcd_val = gcd(a, b);
	cout << (a/gcd_val) << "/" << (b/gcd_val) << '\n';
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, first, in;
	cin >> N;
	cin >> first;

	for (int i=0; i<N-1; ++i) {
		cin >> in;
		solve(first, in);
	}
	return 0;
}