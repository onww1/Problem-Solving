#include <cstdio>
#include <algorithm>
using namespace std;

int L, R, A, ans;
int main() {
	scanf("%d %d %d", &L, &R, &A);
	ans = L + R - abs(L - R);
	if (abs(L - R) > A) ans += 2 * A;
	else if (abs(L - R) <= A) {
		ans += 2 * abs(L - R);
		A -= abs(L - R);
		ans += A / 2 * 2;
	}
	return !printf("%d\n", ans);
}