#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll cnt[10], N, L, _div = 1;
int main(int argc, char *argv[]) {
	scanf("%lld", &N);
	for (ll tmp = N / 10; tmp; tmp /= 10, _div *= 10, L++);
	
	cnt[0] -= L;
	for (ll C = 1; _div / 10LL; N %= _div, _div /= 10, ++C, L--) {
		ll cur = N / _div;
		for (int i = 0; i < 10; ++i) {
			cnt[i] += _div / 10LL * L * cur;
			if (i < cur) cnt[i] += _div;
		}
		cnt[cur] += (N % _div + 1);
		cnt[0] -=  _div / 10LL * 9 * C;
	}

	for (int i = 1; i <= N; ++i) cnt[i]++;
	for (int i = 0; i < 10; ++i) printf("%lld ", cnt[i]);
	return !printf("\n");
}
