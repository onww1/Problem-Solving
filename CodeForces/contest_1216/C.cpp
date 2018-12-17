#include <iostream>
#define MOD 998244353
using namespace std;

typedef long long ll;
ll com[2000][2000] = {0, };

ll getCombi(ll N, ll K) {
	ll &ret = com[N][K];
	if (ret != 0) return ret;
	if (N == K || K == 0) return com[N][K] = 1;
	if (K == 1 || K == N-1) return com[N][K] = N;
	return com[N][K] = (getCombi(N-1, K-1) + getCombi(N-1, K))%MOD;
}

ll getPower(ll base, ll exp) {
	if (base == 0 || base == 1 || exp == 0 || exp == -1) return 1;
	ll res = base;
	ll pow = 1;
	while (2 * pow < exp) {
		res = (res * res) % MOD;
		pow *= 2;
	}
	while (pow < exp) {
		res = (res * base) % MOD;
		pow += 1;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M, K;
	cin >> N >> M >> K;

	if (M == 1 && K > 0) cout << 0 << '\n';
	else {
		ll combi = getCombi(N-1, K);
		ll pow = getPower(M-1, K);
		pow = (pow * M) % MOD;
		pow = (pow * combi) % MOD;
		cout << pow << '\n';
	}

	return 0;
}
