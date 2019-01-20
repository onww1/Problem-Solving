#include <cstdio>
#include <vector>
using namespace std;

char buf[1 << 17];
inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		int nidx = fread(buf, 1, 1 << 17, stdin);
		if (!nidx) return 0;
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	while (now == ' ' || now == '\n') now = read();
	while ('0' <= now && now <= '9') {
		sum = sum * 10 + now - '0';
		now = read();
	}
	return sum;
}

bool isPossible[105][105];
vector <int> edges[105];
int cnt[105];

void solve(int s, int e) {
	isPossible[s][e] = true;
	for (auto it : edges[e]) if (!isPossible[s][it]) solve(s, it);
}

int main(int argc, char *argv[]) {
	int n, m, u, v, i, j;
	n = readInt();
	m = readInt();
	for (i = 0; i < m; ++i) {
		u = readInt();
		v = readInt();
		edges[u].push_back(v);
	}
	for (i = 1; i <= n; ++i) solve(i, i);
	for (i = 1; i < n; ++i) {
		for (j = i + 1; j <= n; ++j) {
			if (!isPossible[i][j] && !isPossible[j][i]) {
				++cnt[i];
				++cnt[j];
			}
		}
	}

	for (i = 1; i <= n; ++i) printf("%d\n", cnt[i]);
	return 0;
}