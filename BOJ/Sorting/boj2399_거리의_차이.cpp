#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 10000;
ll N, A[MAX + 1], P[MAX + 1], ans;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", A + i);
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; ++i) P[i] = A[i] + P[i - 1];
	for (ll i = 1; i <= N; ++i) {
		// left
		ans += A[i] * (i - 1) - P[i - 1];
		// right
		ans += P[N] - P[i] - A[i] * (N - i);
	}
	return !printf("%lld\n", ans);
}