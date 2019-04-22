#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, L[10001], B[10001];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", L + i);
		sort(L, L + N);
		for (int i = 0; i < N; ++i) {
			if (i % 2) B[N - 1 - i / 2] = L[i];
			else B[i / 2] = L[i];
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) ans = max(ans, abs(B[(i + 1) % N] - B[i]));
		printf("%d\n", ans);
	}
	return 0;
}