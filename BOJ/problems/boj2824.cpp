#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MAX = 1000;
int A[MAX], B[MAX], n, m;

bool noPrime[31628];
vector <int> prime;

int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", A + i);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d", B + i);

	for (int i = 2; i <= 31627; ++i) {
		if (!noPrime[i]) {
			prime.push_back(i);
			for (int j = i * i; j <= 31627; j += i) noPrime[j] = true;
		}
	}

	ll ans = 1, flag = 0;
	for (int i = 0; i < prime.size(); ++i) {
		int acnt = 0, bcnt = 0;
		for (int j = 0; j < n; ++j) while (A[j] % prime[i] == 0) {
			acnt++;
			A[j] /= prime[i];
		}
		for (int j = 0; j < m; ++j) while (B[j] % prime[i] == 0) {
			bcnt++;
			B[j] /= prime[i];
		}

		int cnt = min(acnt, bcnt);
		for (int j = 0; j < cnt; ++j) {
			if (flag) ans = ans * prime[i] % 1000000000;
			else {
				ans *= prime[i];
				if (ans >= 1000000000) {
					flag = 1;
					ans %= 1000000000;
				}
			}
		}
	}

	map <int, int> mp;
	for (int i = 0; i < n; ++i) if (A[i] > 1) mp[A[i]] += 1;
	for (int i = 0; i < m; ++i) if (B[i] > 1) {
		if (mp[B[i]] > 0) {
			mp[B[i]] -= 1;
			if (flag) ans = ans * B[i] % 1000000000;
			else {
				ans *= B[i];
				if (ans >= 1000000000) {
					flag = 1;
					ans %= 1000000000;
				}
			}
		}
	}

	return !printf(flag ? "%09lld\n" : "%lld\n", ans);
}