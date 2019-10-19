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

int n, cnt, p[10005], ch[10005][2], d[10005][2];

void solve(int node, int depth) {
	if (node == -1) return;
	solve(ch[node][0], depth + 1);
	++cnt;
	if (!d[depth][0]) d[depth][0] = cnt;
	d[depth][1] = cnt;
	solve(ch[node][1], depth + 1);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, a, b, c; i <= n; ++i) {
    	scanf("%d %d %d", &a, &b, &c);
    	ch[a][0] = b, ch[a][1] = c;
    	p[b] = a, p[c] = a;
    }

    int root = 0;
    for (int i = 1; i <= n; ++i)
    	if (!p[i]) {
    		root = i;
    		break;
    	}

    solve(root, 1);

    int mx = 0, dd = 0;
    for (int i = 1; i <= n; ++i) {
    	int width = d[i][1] - d[i][0] + 1;
    	if (mx < width) {
    		dd = i;
    		mx = width;
    	}
    }

    printf("%d %d\n", dd, mx);

    close();
    return 0;
}