#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2e5;
char A[MAX + 1];
int T, L, g[MAX + 1], tg[MAX + 1], SA[MAX + 1], r[MAX + 1], LCP[MAX + 1];

bool cmp(int x, int y) {
	if (g[x] == g[y]) return g[x + T] < g[y + T];
	return g[x] < g[y];
}

int main(int argc, char *argv[]) {
	scanf("%d %s", &L, A);
	T = 1;

	for (int i = 0; i < L; ++i) {
		SA[i] = i;
		g[i] = A[i] - 'a';
	}

	while (T <= L) {
		g[L] = -1;
		sort(SA, SA + L, cmp);
		tg[SA[0]] = 0;
		for (int i = 1; i < L; ++i) {
			if (cmp(SA[i - 1], SA[i])) tg[SA[i]] = tg[SA[i - 1]] + 1;
			else tg[SA[i]] = tg[SA[i - 1]];
		}
		for (int i = 0; i < L; ++i) g[i] = tg[i];
		T <<= 1;
	}

	for (int i = 0; i < L; ++i) r[SA[i]] = i;
	for (int i = 0, len = 0; i < L; ++i) {
		int k = r[i];
		if (k) {
			int j = SA[k - 1];
			while (A[j + len] == A[i + len]) len++;
			LCP[k] = len;
			if (len) len--;
		}
	}

	int mx = 0;
	for (int i = 1; i < L; ++i) mx = max(mx, LCP[i]);
	return !printf("%d\n", mx);
}