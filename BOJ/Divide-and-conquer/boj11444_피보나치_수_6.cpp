#include <cstdio>
typedef long long ll;

const ll MOD = 1e9 + 7;

struct matrix {
	ll A[2][2];
	matrix(ll a, ll b, ll c, ll d) { 
		A[0][0] = a, A[0][1] = b;
		A[1][0] = c, A[1][1] = d;
	}
	matrix operator* (const matrix& other) const {
		matrix ret(0, 0, 0, 0);
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					ret.A[i][j] = (ret.A[i][j] + A[i][k] * other.A[k][j]) % MOD;
		return ret;
	}
};

matrix _pow(matrix base, ll exp) {
	matrix ret(1, 0, 0, 1);
	while (exp) {
		if (exp % 2LL) ret = ret * base;
		base = base * base;
		exp /= 2LL;
	}
	return ret;
}

int main() {
	ll N; scanf("%lld", &N);
	matrix base(1, 1, 1, 0);
	matrix res = _pow(base, N);
	printf("%lld\n", res.A[1][0] % MOD);
	return 0;
}