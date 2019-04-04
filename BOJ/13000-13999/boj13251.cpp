#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll _pow(ll base, ll exp) {
	ll ret = 1;
	while (exp) {
		if (exp % 2) ret = ret * base;
		base = base * base;
		exp /= 2;
	}
	return ret;
}


const int MAX = 50;
int a[MAX + 1];
ll comb[MAX + 1][MAX + 1];

bool noPrime[2501] = { 1, 1 };
vector <int> prime;

void init() {
	// prime factor
	for (int i = 2; i <= 2500; ++i) {
		if (!noPrime[i]) {
			prime.push_back(i);
			for (int j = i * i; j <= 2500; j += i) noPrime[j] = true;
		}
	}

	// combination
	for (int i = 0; i <= MAX; ++i) comb[i][0] = comb[i][i] = 1;
	for (int i = 2; i <= MAX; ++i) {
		for (int j = 1; j < i; ++j) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
}

int main(int argc, char *argv[]) {
	
	init();

	int N = 0, M, K;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) scanf("%d", a + i), N += a[i];
	scanf("%d", &K);

	vector <int> candidate;
	for (int i = 0; i < M; ++i) 
		if (a[i] >= K) candidate.push_back(a[i]);
	
	if (candidate.size() == 0) return !printf("0.0\n");

	ll numerator = 0LL;
	for (int i = 0; i < candidate.size(); ++i) 
		numerator += comb[candidate[i]][K];
	
	double ans = 1;
	int cnt[2501] = { 0 };
	for (int j = 0; j < prime.size(); ++j) {
		int nu = N, de1 = K, de2 = N - K;
		while (nu) {
			cnt[prime[j]] -= nu / prime[j];
			nu /= prime[j];
		}
		while (de1) {
			cnt[prime[j]] += de1 / prime[j];
			de1 /= prime[j];
		}
		while (de2) {
			cnt[prime[j]] += de2 / prime[j];
			de2 /= prime[j];
		}
	}

	for (int i = 0; i <= prime.size(); ++i) {
		if (cnt[prime[i]] > 0) ans *= _pow(prime[i], cnt[prime[i]]);
		else if (cnt[prime[i]] < 0) ans /= _pow(prime[i], -cnt[prime[i]]);
	}

	return !printf("%0.12lf\n", ans * numerator);
}

