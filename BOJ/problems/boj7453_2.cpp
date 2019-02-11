#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 4e3;

int A[MAX], B[MAX], C[MAX], D[MAX], AB[MAX*MAX], CD[MAX*MAX], n;
int main(int argc, char *argv[]) {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d %d %d %d", A + i, B + i, C + i, D + i);
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) {
		AB[i * n + j] = A[i] + B[j];
		CD[i * n + j] = C[i] + D[j];
	}

	sort(AB, AB + n * n);
	long long cnt = 0;

	n *= n;
	for (i = 0; i < n; ++i) {
		int l = 0, r = n - 1, m;
		auto lb = lower_bound(AB, AB + n, -CD[i]);
		auto ub = upper_bound(AB, AB + n, -CD[i]);
		if (lb == AB + n || *lb != -CD[i]) continue;
		cnt += (ub - lb);
	}

	return !printf("%lld\n", cnt);
}