#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N, K, A[MAX + 1];
int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		A[i] += A[i - 1];
	}

	int mx = -1e9;
	for (int i = 0; i + K <= N; ++i) 
		mx = max(mx, A[i + K] - A[i]);

	return !printf("%d\n", mx);
}