#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 500;
int A[MAX + 1][MAX + 1], N;

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			A[i - 1][j] += max(A[i][j], A[i][j + 1]);
		}
	}

	return !printf("%d\n", A[0][0]);
}