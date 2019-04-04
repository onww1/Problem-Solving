#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e3;

ll S[MAX * MAX], A[MAX + 1], B[MAX + 1], n, m, t, sp;

int main(int argc, char *argv[]) {
	ll i, j, cnt = 0;
	scanf("%lld", &t);
	scanf("%lld", &n); 
	for (i = 1; i <= n; ++i) {
		scanf("%lld", A + i);
		A[i] += A[i - 1];
		for (j = 0; j < i; ++j) S[sp++] = A[i] - A[j];
	}
	sort(S, S + sp);

	scanf("%lld", &m); 
	for (i = 1; i <= m; ++i) {
		scanf("%lld", B + i);
		B[i] += B[i - 1];
		for (j = 0; j < i; ++j) 
			cnt += (upper_bound(S, S + sp, t - B[i] + B[j]) - lower_bound(S, S + sp, t - B[i] + B[j]));
	}
	
	return !printf("%lld\n", cnt);
}