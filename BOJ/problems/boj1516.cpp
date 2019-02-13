#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 500;
vector <int> edges[MAX + 1];
int A[MAX + 1], ans[MAX + 1], in[MAX + 1], n;
bool visited[MAX + 1];

int main(int argc, char *argv[]) {
	int p, i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d %d", A + i, &p);
		while (p != -1) {
			edges[p].push_back(i);
			in[i]++;
			scanf("%d", &p);
		}
	}

	queue <int> q;
	for (i = 1; i <= n; ++i) 
		if (in[i] == 0) q.push(i);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		ans[cur] += A[cur];
		for (int next : edges[cur]) {
			in[next]--;
			ans[next] = max(ans[next], ans[cur]);
			if (in[next] == 0) q.push(next);
		}
	}

	for (i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	return 0;
}