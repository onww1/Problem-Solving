#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, pii> piii;
typedef tuple <int, int, int> ti3;

clock_t start_time, end_time;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
    TEST(start_time = clock());
}

void close() {
    TEST(end_time = clock());
    TEST(printf("Total time : %Lf seconds\n", (long double)(end_time - start_time) / CLOCKS_PER_SEC));
}

const int SZ = 1 << 17;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, root, node_num, tree[2 * SZ];
int num[SZ], idx[SZ], w[SZ], hld[SZ], parent[SZ], depth[SZ];
bool isBlack[SZ];
vector <int> edges[SZ];

void SUpdate(int pos, int val, int node = 1, int start = 0, int end = n - 1) {
	if (pos < start || end < pos) return;
	if (start == end && pos == start) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) >> 1;
	SUpdate(pos, val, node * 2, start, mid);
	SUpdate(pos, val, node * 2 + 1, mid + 1, end);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int SQuery(int left, int right, int node = 1, int start = 0, int end = n - 1) {
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return min(SQuery(left, right, node * 2, start, mid),
			   SQuery(left, right, node * 2 + 1, mid + 1, end));
}

void preprocess(int node) {
	w[node] = 1;
	for (int next : edges[node]) 
		if (!w[next]) {
			parent[next] = node;
			depth[next] = depth[node] + 1;
			preprocess(next);
			w[node] += w[next];
		}
}

void numbering(int node) {
	int heavy = -1;
	num[node] = node_num++;
	idx[num[node]] = node;
	for (int next : edges[node])
		if (parent[next] == node && (heavy == -1 || w[heavy] < w[next]))
			heavy = next;
	if (heavy != -1) {
		hld[heavy] = hld[node];
		numbering(heavy);
	}
	for (int next : edges[node])
		if (parent[next] == node && next != heavy) {
			hld[next] = next;
			numbering(next);
		}
}

void init_HLD(int n, int r) {
	root = hld[r] = parent[r] = r;
	depth[r] = node_num = 0;
	memset(w, 0, sizeof(w));
	preprocess(r); numbering(r);
}

int Query(int v) {
	int ret = INF, u = 1;
	while (hld[u] != hld[v]) {
		if (depth[hld[u]] > depth[hld[v]]) {
			ret = min(ret, SQuery(num[hld[u]], num[u]));
			u = parent[hld[u]];
		} else {
			ret = min(ret, SQuery(num[hld[v]], num[v]));
			v = parent[hld[v]];
		}
	}
	if (depth[u] > depth[v]) swap(u, v);
	ret = min(ret, SQuery(num[u], num[v]));
	return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
    	scanf("%d %d", &u, &v);
    	edges[u].push_back(v);
    	edges[v].push_back(u);
    }
    memset(tree, 0x3f, sizeof(tree));
    init_HLD(n, 1);

    scanf("%d", &m);
    for (int i = 0, u, v; i < m; ++i) {
    	scanf("%d %d", &u, &v);
    	if (u == 1) {
    		isBlack[v] = !isBlack[v];
    		SUpdate(num[v], isBlack[v] ? num[v] : INF);
    	} else {
    		int ans = Query(v);
    		printf("%d\n", ans == INF ? -1 : idx[ans]);
    	}
    }

    close();
    return 0;
}
