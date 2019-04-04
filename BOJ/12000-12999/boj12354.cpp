#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, N, A;
	vector <int> lis;

	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		lis.clear();
		scanf("%d %d", &N, &A);
		lis.push_back(A);
		for (int i = 1; i < N; ++i) {
			scanf("%d", &A);
			if (lis.back() < A) lis.push_back(A);
			else *lower_bound(lis.begin(), lis.end(), A) = A;
		}
		printf("Case #%d: %d\n", tc, N - (int)lis.size());
	}
	return 0;
}