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

int w, h, vis, cnt, src, v[22][22], d[11][11], dp[11][1 << 11];
char in[22][22];
vector <pii> pos;
map <pii, int> idx;

int solve(int node, int visited) {
	if (visited == (1 << cnt) - 1) return 0;

	int &ret = dp[node][visited];
	if (~ret) return ret;
	ret = INF;

	for (int i = 0; i < cnt; ++i) {
		if (visited & (1 << i)) continue;
		ret = min(ret, d[node][i] + solve(i, visited | (1 << i)));
	}

	return ret;
}

int main(int argc, char *argv[]) {
    open();

    while (1) {
    	scanf("%d %d", &w, &h);
    	if (!w && !h) break;
    	cnt = 0; pos.clear(); idx.clear();
    	memset(d, 0x3f, sizeof(d));

    	for (int i = 0; i < h; ++i) {
    		scanf(" %s", in[i]);
    		for (int j = 0; j < w; ++j) {
    			if (in[i][j] == 'o') {
    				src = cnt;
    				pos.push_back({i, j});
    				idx[pii(i, j)] = cnt++;
    			}
    			else if (in[i][j] == '*') {
    				pos.push_back({i, j});
    				idx[pii(i, j)] = cnt++;
    			}
    		}
    	}

    	for (int i = 0; i < pos.size(); ++i) {
    		queue <pii> q; 
    		q.push(pos[i]);
    		memset(v, 0, sizeof(v));
    		d[i][i] = 0;
    		v[pos[i].X][pos[i].Y] = 1;
    		while (!q.empty()) {
    			int r = q.front().X;
    			int c = q.front().Y;
    			q.pop();

    			if (in[r][c] == 'o' || in[r][c] == '*')
    				d[i][idx[pii(r, c)]] = v[r][c] - 1;

    			for (int k = 0; k < 4; ++k) {
    				int dr = r + move_r[k];
    				int dc = c + move_c[k];
    				if (dr < 0 || dr >= h || dc < 0 || dc >= w) continue;
    				if (!v[dr][dc] && in[dr][dc] != 'x') {
    					v[dr][dc] = v[r][c] + 1;
    					q.push({dr, dc});
    				}
    			}
    		}
    	}

 		bool impossible = false;
    	for (int i = 1; i < cnt; ++i)
    		for (int j = 0; j < i; ++j)
    			if (d[i][j] == INF)
    				impossible = true;

    	if (impossible) {
    		puts("-1");
    		continue;
    	}

    	memset(dp, -1, sizeof(dp));
    	printf("%d\n", solve(src, 1 << src));
    }

    close();
    return 0;
}
