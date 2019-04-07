#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int N, M;
pii DP[1000][10];
vector <int> st;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0, A; i < M; ++i) scanf("%d", &A), DP[0][A] = {1, 0};
	for (int i = 1; i < N; ++i) {
		scanf("%d", &M);
		for (int j = 0, A; j < M; ++j) {
			scanf("%d", &A);
			for (int k = 1; k < 10; ++k) {
				if (k == A) continue;
				if (DP[i - 1][k].first) {
					DP[i][A] = {1, k};
					break;
				}
			}
		}
	}

	for (int i = 1; i < 10; ++i) if (DP[N - 1][i].first) {
		st.push_back(i);
		break;	
	}

	if (st.empty()) return !printf("-1\n");

	int ptr = DP[N - 1][st.back()].second;
	for (int i = N - 2; ptr != 0; i--) {
		st.push_back(ptr);
		ptr = DP[i][ptr].second;
	}

	while (!st.empty()) printf("%d\n", st.back()), st.pop_back();
	return 0;
}