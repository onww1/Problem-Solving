#include <cstdio>
#include <algorithm>
using namespace std;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }

int N, A[100001];

int main() {
	scanf("%d %d", &N, A);
	for (int i = 1; i <= N; ++i) scanf("%d", A + i);
	sort(A, A + N + 1);
	int GCD = A[1] - A[0];
	for (int i = 2; i <= N; ++i) 
		GCD = _gcd(GCD, A[i] - A[i - 1]);
	printf("%d\n", GCD);
	return 0;
}