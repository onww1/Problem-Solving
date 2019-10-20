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

int n, c[128][128], f[128][128];
vector <int> edges[128];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
    	char a, b; int v;
    	scanf(" %c %c %d", &a, &b, &v);
    	if (!c[a][b]) {
    		edges[a].push_back(b);
    		edges[b].push_back(a);
    	}
    	c[a][b] += v; 
    	c[b][a] += v;
    }

    int ans = 0, S = 'A', T = 'Z';
    while (1) {
    	int prv[128];
    	memset(prv, -1, sizeof(prv));
    	queue <int> q; q.push(S);
    	while (!q.empty() && prv[T] == -1) {
    		int cur = q.front(); q.pop();
    		for (int next : edges[cur]) {
    			if (c[cur][next] - f[cur][next] > 0 && prv[next] == -1) {
    				q.push(next);
    				prv[next] = cur;
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