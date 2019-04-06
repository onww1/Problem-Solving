#include <iostream>
#define MOD 1'000'000'007
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll A, X;
	cin >> A >> X;

	ll DP[64] = {1LL, };
	DP[0] = A % MOD;
	for (int i=1; i<64; i++) {
		DP[i] = (DP[i-1] * DP[i-1]) % MOD;
	}

	ll res = 1LL;
	ll mask = 1LL;
	for (int i=62; i>=0; i--) {
		if (X & (mask << i)) {
			res = (res * DP[i]) % MOD;
		}
	}

	cout << res << '\n';

	return 0;
}