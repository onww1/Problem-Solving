#include <cstdio>
int A, B, a, b;
int main() {
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &a);
		A += a * (3 - i);
	}
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &b);
		B += b * (3 - i);
	}
	if (A > B) puts("A");
	else if (A < B) puts("B");
	else puts("T");
	return 0;
}