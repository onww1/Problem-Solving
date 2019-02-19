#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;
int N, M, A[MAX + 1], C[MAX + 1], DP[MAX * MAX + 1];

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	for (int i = 0; i < N; ++i) scanf("%d", C + i);
	memset(DP, -1, sizeof(DP));

	DP[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = MAX * MAX; j - C[i] >= 0; --j) {
			if (DP[j - C[i]] != -1) {
				DP[j] = max(DP[j], DP[j - C[i]] + A[i]);
			}
		}
	}

	for (int i = 0; i <= MAX * MAX; ++i)
		if (DP[i] >= M) return !printf("%d\n", i);

	return 0;
}

