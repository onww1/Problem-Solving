#include <cstdio>
#include <algorithm>
using namespace std;
long long T, A[3];
int main() {
	scanf("%lld", &T);
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 3; ++i) scanf("%lld", A + i);
		sort(A, A + 3);
		if (tc > 1) puts("");
		printf("Scenario #%d:\n", tc);
		if (A[2] * A[2] == A[1] * A[1] + A[0] * A[0]) puts("yes");
		else puts("no");
	}
	return 0;
}