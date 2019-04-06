#include <cstdio>
int main() {
	int T, D;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &D);
		for (int t = 99; t >= 0; --t) {
			if (t * t + t <= D) {
				printf("%d\n", t);
				break;
			}
		}
	}
	return 0;
}