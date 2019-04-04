#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 40000;
const int INF = 0x3f3f3f3f;
int N, M, P[MAX + 2], DP[MAX + 2];
bool visit[MAX + 2];

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%d", P + i);
	for (int i = 0; i <= N; ++i) DP[i] = i;

	int mx_size = 200;
	while (mx_size * mx_size > N) --mx_size;

	for (int i = 1; i <= N; ++i) {
		memset(visit, 0, sizeof(visit));
		for (int j = i, s = 0; j <= N; ++j) {
			if (!visit[P[j]]) s++, visit[P[j]] = 1;

			if (i + s * s > N + 1 || s > mx_size) break;
			DP[j] = min(DP[j], DP[i - 1] + s * s);
		}
	}

	return !printf("%d\n", DP[N]);
}

