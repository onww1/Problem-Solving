#include <iostream>
using namespace std;

typedef long long ll;

ll pow(ll n, ll i) {
	ll ret = 1LL;
	for (ll j=0; j<i; ++j) ret *= n;
	return ret;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, a, b, c;
	while (true) {
		cin >> N;
		if (!N) break;
		cin >> a >> b >> c;

		if (2 * b == a + c) {
			cout << (N * (2 * a + (N-1) * (b-a)) / 2) << '\n';
		}
		else {
			cout << (a * (pow(b/a, N) - 1) / (b/a - 1)) << '\n';
		}
	}
	return 0;
}