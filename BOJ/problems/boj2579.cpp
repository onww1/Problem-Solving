#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 300;
int A[MAX + 1], DP[MAX + 1], N;

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", A + i);

	DP[1] = A[1], DP[2] = A[1] + A[2];
	for (int i = 3; i <= N; ++i) 
		DP[i] = A[i] + max(DP[i - 3] + A[i - 1], DP[i - 2]);
	
	return !printf("%d\n", DP[N]);
}