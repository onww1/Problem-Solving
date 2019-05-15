#include <cstdio>

void solve(int N) {
	if (!N) return;
	solve(N / 9);
	printf("%d", N % 9);
}

int main() {
	int T; 
	scanf("%d", &T);
	solve(T); puts("");
	return 0;
}