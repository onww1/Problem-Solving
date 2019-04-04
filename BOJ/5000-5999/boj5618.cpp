#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M, V, i, A[3];
	vector <int> D;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	M = max({A[0], A[1], A[2]});

	for (i = 1; i * i < M; ++i) {
		if (M % i == 0) {
			V = 0;
			for (int j = 0; j < N; ++j) V += (A[j] % i);
			if (!V) D.push_back(i);

			V = 0;
			for (int j = 0; j < N; ++j) V += (A[j] % (M / i));
			if (!V) D.push_back(M / i);
		}
	}

	if (i * i == M) {
		V = 0;
		for (int j = 0; j < N; ++j) V += (A[j] % i);
		if (!V) D.push_back(i);
	}

	sort(D.begin(), D.end());
	for (int num : D) printf("%d\n", num);

	return 0;
}