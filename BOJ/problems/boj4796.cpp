#include <cstdio>
int main() {
	int L, P, V;
	for (int tc = 1; 1; tc++) {
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V) break;
		printf("Case %d: %d\n", tc, V / P * L + (V % P >= L ? L : V % P));
	}
	return 0;
}