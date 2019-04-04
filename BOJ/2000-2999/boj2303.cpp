#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N, A, C[5], P[5], sum, mx, mx_idx;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 5; ++j) scanf("%d", C + j);
		P[0] = P[1] = 0; P[2] = P[3] = P[4] = 1;
		A = 0;
		do {
			sum = 0;
			for (int k = 0; k < 5; ++k) 
				if (P[k]) sum += C[k];
			A = max(A, sum % 10);
		} while (next_permutation(P, P + 5));
		if (A >= mx) mx = A, mx_idx = i;
	}
	return !printf("%d\n", mx_idx);
}