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

const int MAX = 1e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, ans, dp[MAX][2], w[MAX];
vector <int> edges[MAX], ansv;

int solve(int node, int parent, int in) {
	int &ret = dp[node][in];
	if (~ret) return ret;
	ret = in ? w[node] : 0;

	for (int next : edges[node]) {
		if (next == parent) continue;
		int val = solve(next, node, 0);
		if (!in) val = max(val, solve(next, node, 1));
		ret += val;
	}

	return ret;
}

void restore(int node, int parent, int in) {
	if (in) ansv.push_back(node);
	for (int next : edges[node]) {
		if (next == parent) continue;
		if (in) restore(next, node, 0);
		else restore(next, node, dp[next][0] < dp[next][1]);
	}
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", w + i);
    for (int i = 1, u, v; i < n; ++i) {
    	scanf("%d %d", &u, &v);
    	edges[u].push_back(v);
    	edges[v].push_back(u);
    }
    edges[0].push_back(1);

    memset(dp, -1, sizeof(dp));
    ans = solve(0, -1, 0);
    restore(0, -1, 0);
    sort(ansv.begin(), ansv.end());

    printf("%d\n", ans);
    for (int node : ansv) printf("%d ", node); puts("");

    close();
    return 0;
}