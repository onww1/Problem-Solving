#include <cstdio>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main(int argc, char *argv[]) {
	int T;
	pll p[4];
	ll L[6];

	for (scanf("%d", &T); T; T--) {
		for (int i = 0; i < 4; ++i) scanf("%lld %lld", &p[i].X, &p[i].Y);
		for (int i = 0, idx = 0; i < 3; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				L[idx++] = (p[i].X - p[j].X) * (p[i].X - p[j].X) + (p[i].Y - p[j].Y) * (p[i].Y - p[j].Y);
			}
		}
		sort(L, L + 6);
		if (L[0] == L[3] && L[4] == L[5]) puts("1");
		else puts("0");
	}

	return 0;
}