#include <cstdio>
typedef long long ll;

const int MAX = 1e6;
int h[MAX + 1], n, m;

bool solve(int height) {
	ll cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (height < h[i]) cnt += (h[i] - height);
	}
	return cnt >= m;
}

int main(int argc, char *argv[]) {
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", h + i);

	int s = 0, e = 1e9, m;
	while (s <= e) {
		m = (s + e) / 2;
		if (solve(m)) s = m + 1;
		else e = m - 1;
	}

	return !printf("%d\n", e);
}