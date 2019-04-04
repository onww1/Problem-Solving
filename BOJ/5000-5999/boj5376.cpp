#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

char in[20];

ll _pow(ll base, ll exp) {
	ll ret = 1LL;
	while (exp) {
		if (exp % 2) ret *= base;
		base *= base;
		exp /= 2LL;
	}
	return ret;
}

ll _gcd(ll a, ll b) { return b ? _gcd(b, a % b) : a;  }

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll prev = 0LL, post = 0LL;
		int ninf = 0, tot = 0, flg = 1;
		scanf(" %s", in);
		for (int i = 2; in[i]; ++i) {
			if (in[i] == '(' || in[i] == ')') {
				flg = 0;
				continue;
			}
			
			if (flg) prev = prev * 10 + in[i] - '0', ninf++;
			post = post * 10 + in[i] - '0', tot++;
		}

		ll nu = (tot == ninf ? post : post - prev);
		ll de = (tot == ninf ? _pow(10, tot) : (ninf == 0 ? _pow(10, tot) - 1 : _pow(10, tot) - _pow(10, ninf)));
		ll GCD = _gcd(nu, de);
		printf("%lld/%lld\n", nu / GCD, de / GCD);
	}
	return 0;
}

