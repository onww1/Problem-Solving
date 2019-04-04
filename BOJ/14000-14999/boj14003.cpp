#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e6;
int N, P, A, ans[MAX + 1];
pii cache[MAX + 1];
vector <int> lis;


int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &A);
	lis.push_back(A);
	cache[P++] = { A, 0 };
	for (int i = 1; i < N; ++i) {
		scanf("%d", &A);
		if (A > lis.back()) {
			cache[P++] = { A, lis.size() };
			lis.push_back(A);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), A) - lis.begin();
			cache[P++] = { A, idx };
			lis[idx] = A;
		}
	}

	ans[lis.size() - 1] = lis.back();
	int start = P - 1;
	while (cache[start--].first != lis.back());

	for (int i = start, len = lis.size() - 2; len >= 0 && i >= 0; --i) {
		if (cache[i].first < ans[len + 1] && cache[i].second == len) {
			ans[len] = cache[i].first;
			len--;
		}
	}

	printf("%lu\n", lis.size());
	for (int i = 0; i < lis.size(); ++i) printf("%d ", ans[i]);
	return !printf("\n");
}