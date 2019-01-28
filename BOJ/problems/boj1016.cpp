#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 1000000;
bool chk[MAX + 1];

int main(int argc, char *argv[]) {
	ll mn, mx, i, j, cnt = 0LL;
	scanf("%lld %lld", &mn, &mx);
	for (i = 2; i <= MAX; ++i) {
		for (j = mn / (i * i); j * i * i <= mx; ++j) {
			if (j * i * i >= mn && !chk[j * i * i - mn]) ++cnt, chk[j * i * i - mn] = true;
		}
	}
	return !printf("%lld\n", mx - mn + 1 - cnt);
}