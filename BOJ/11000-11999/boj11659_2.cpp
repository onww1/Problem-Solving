#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
int A[MAX + 1], N, M;

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", A + i);
		A[i] += A[i - 1];
	}

	int s, e;
	while (M--) {
		scanf("%d %d", &s, &e);
		if (s > e) swap(s, e);
		printf("%d\n", A[e] - A[s - 1]);
	}

	return 0;
}