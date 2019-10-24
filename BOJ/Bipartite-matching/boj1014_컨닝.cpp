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
const int move_r[] = {-1, -1, 0, 0, 1, 1};
const int move_c[] = {-1, 1, -1, 1, -1, 1};

int t, n, m, b, mp[10][10], nm[10][10], bmat[50];
char in[11];
bool visited[50];
vector <int> edges[50];

bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b : edges[a])
		if (bmat[b] == -1 || dfs(bmat[b])) {
			bmat[b] = a;
			return true;
		}
	return false;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
    	scanf("%d %d", &n, &m); b = 0;
    	for (int i = 0; i < n; ++i) {
    		scanf(" %s", in);
    		for (int j = 0; j < m; ++j) {
    			mp[i][j] = (in[j] == 'x');
    			b += mp[i][j];
    		}
    	}

    	int aa = 0, bb = 0;
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < m; j += 2) {
    			edges[aa].clear();
    			nm[i][j] = aa++;
    		}
    	for (int i = 0; i < n; ++i)
    		for (int j = 1; j < m; j += 2) 
    			nm[i][j] = bb++;

    	for (int j = 0; j < m; j += 2)
    		for (int i = 0; i < n; ++i) {
    			if (mp[i][j]) continue;
    			for (int k = 0; k < 6; ++k) {
    				int dr = i + move_r[k];
    				int dc = j + move_c[k];
    				if (dr < 0 || dr >= n || dc < 0 || dc >= m || mp[dr][dc]) continue;
    				edges[nm[i][j]].push_back(nm[dr][dc]);
    			}
    		}

    	int mx = 0;
    	memset(bmat, -1, sizeof(bmat));
    	for (int i = 0; i < aa; ++i) {
    		memset(visited, 0, sizeof(visited));
    		if (dfs(i)) mx++;
    	}

    	printf("%d\n", n * m - b - mx);
    }

    close();
    return 0;
}
