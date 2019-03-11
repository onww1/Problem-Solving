#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long double ldb;
int T, N;
ldb D, A, B, F;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %Lf %Lf %Lf %Lf", &N, &D, &A, &B, &F);
		ldb ans = 0;
		for (int i = 1; ; ++i) {
			if (abs(D) < 1e-10) break;
			if (i % 2) {
				ldb tm = D / (F + B);
				ans += F * tm;
				D -= (A + B) * tm;
			} else {
				ldb tm = D / (F + A);
				ans += F * tm;
				D -= (A + B) * tm;
			}
		}
		printf("%d %.3Lf\n", N, ans);
	}
	return 0;
}