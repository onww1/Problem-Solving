#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int N, M, mx;
bool visited[MAX + 1];
vector <int> edges[MAX + 1];
vector <int> ans;

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0, A, B; i < M; ++i) {
		scanf("%d %d", &A, &B);
		edges[B].push_back(A);
	}

	for (int i = 1; i <= N; ++i) {
		memset(visited, false, sizeof(visited));
		queue <int> Q;
		Q.push(i); visited[i] = true;
		int cnt = 0;
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			++cnt;
			for (int next : edges[cur]) {
				if (!visited[next]) {
					Q.push(next);
					visited[next] = true;
				}
			}
		}
		if (cnt > mx) {
			mx = cnt;
			ans.clear();
			ans.push_back(i);
		} else if (cnt == mx) ans.push_back(i);
	}

	for (int node : ans) printf("%d ", node);
	puts("");
	return 0;
}