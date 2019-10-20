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

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, c[802][802], f[802][802], prv[802];
vector <int> edges[802];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n + m; ++i) {
    	edges[i * 2 - 1].push_back(i * 2);
    	edges[i * 2].push_back(i * 2 - 1);
    	c[i * 2 - 1][i * 2] = 1;
    }

    for (int i = 1; i <= n; ++i) {
    	int l, a;
    	scanf("%d", &l);
    	for (int j = 0; j < l; ++j) {
    		scanf("%d", &a); a += n;
    		edges[i * 2].push_back(a * 2 - 1);
    		edges[a * 2 - 1].push_back(i * 2);
    		c[i * 2][a * 2 - 1] = 1;
    	}
    }

    for (int i = 1; i <= n; ++i) {
    	edges[0].push_back(i * 2 - 1);
    	edges[i * 2 - 1].push_back(0);
		c[0][i * 2 - 1] = 1;
	}

	for (int i = 1; i <= m; ++i) {
		edges[(n + i) * 2].push_back((n + m) * 2 + 1);
		edges[(n + m) * 2 + 1].push_back((n + i) * 2);
		c[(n + i) * 2][(n + m) * 2 + 1] = 1;
	}

	int ans = 0, S = 0, T = (n + m) * 2 + 1;
	while (1) {
		memset(prv, -1, sizeof(prv));
		queue <int> q; q.push(S);
		while (!q.empty() && prv[T] == -1) {
			int cur = q.front(); q.pop();
			for (int next : edges[cur]) {
				if (c[cur][next] - f[cur][next] > 0 && prv[next] == -1) {
					prv[next] = cur;
					q.push(next);
					if (next == T) break;
				}
			}
		}
		if (prv[T] == -1) break;

		int flow = INF;
		for (int i = T; i != S; i = prv[i])
			flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
		for (int i = T; i != S; i = prv[i]) {
			f[prv[i]][i] += flow;
			f[i][prv[i]] -= flow;
		}
		ans += flow;
	}
	printf("%d\n", ans);

    close();
    return 0;
}