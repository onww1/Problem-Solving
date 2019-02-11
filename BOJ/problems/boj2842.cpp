#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 50;
const int move_r[] = { 1, 0, -1, 0, -1, -1, 1, 1};
const int move_c[] = { 0, 1, 0, -1, -1, 1, -1, 1};
char in[MAX][MAX + 1];
int map[MAX][MAX], visited[MAX][MAX], n;
int cnt[1000001];
vector <pii> dst;
pii src;

bool check(int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; }

bool solve(int mn, int mx) {
	memset(visited, 0, sizeof(visited));
	queue <pii> q;
	q.push(src); visited[src.X][src.Y] = 1;

	int r, c, dr, dc, count = 0;
	while (!q.empty()) {
		r = q.front().X;
		c = q.front().Y;
		q.pop();

		if (in[r][c] == 'K') count++;

		for (int k = 0; k < 8; ++k) {
			dr = r + move_r[k];
			dc = c + move_c[k];
			if (check(dr, dc) && !visited[dr][dc] && mn <= map[dr][dc] && map[dr][dc] <= mx) {
				visited[dr][dc] = 1;
				q.push({ dr, dc });
			}
		}
	}

	return count == dst.size();
}

int main(int argc, char *argv[]) {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf(" %s", in[i]);
		for (j = 0; in[i][j]; ++j) {
			if (in[i][j] == 'K') dst.push_back({ i, j });
			else if (in[i][j] == 'P') src = { i, j };
		}
	}

	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) {
		scanf("%d", &map[i][j]);
		cnt[map[i][j]] = 1;
	}

	int lmin = map[src.X][src.Y], rmax = map[src.X][src.Y];
	for (pii k : dst) {
		lmin = min(lmin, map[k.X][k.Y]);
		rmax = max(rmax, map[k.X][k.Y]);
	}

	vector <int> h;
	for (i = 0; i <= 1000000; ++i) {
		if (cnt[i]) {
			h.push_back(i);
			if (i == lmin) lmin = h.size() - 1;
			if (i == rmax) rmax = h.size() - 1;
		}
	}

	int ans = 2e9;
	int left = 0, right = rmax;
	while (left <= lmin && right < h.size()) {
		if (solve(h[left], h[right])) ans = min(ans, h[right] - h[left]), ++left;
		else ++right;
	}

	return !printf("%d\n", ans);
}