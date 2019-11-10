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

const int MAX = 803;
const int INF = 0x3f3f3f3f;
const int OFFSET = 400;
int n, m, d[MAX][MAX], c[MAX][MAX], f[MAX][MAX], prv[MAX], dist[MAX];
bool inQ[MAX];
vector <int> edges[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    int S = 801, T = 802;
    for (int i = 1; i <= n; ++i) {
    	c[S][i] = 1;
    	edges[S].push_back(i);
    	edges[i].push_back(S);
    }
    for (int i = 1; i <= m; ++i) {
    	c[i + OFFSET][T] = 1;
    	edges[i + OFFSET].push_back(T);
    	edges[T].push_back(i + OFFSET);
    }
    for (int i = 1, l; i <= n; ++i) {
    	scanf("%d", &l);
    	for (int j = 0, u, v; j < l; ++j) {
    		scanf("%d %d", &u, &v);
    		edges[i].push_back(u + OFFSET);
    		edges[u + OFFSET].push_back(i);
    		d[i][u + OFFSET] = v;
    		d[u + OFFSET][i] = -v;
    		c[i][u + OFFSET] = 1;
    	}
    }

    int num_of_works = 0, min_salary = 0;

    while (1) {
    	memset(prv, -1, sizeof(prv));
    	memset(dist, 0x3f, sizeof(dist));
    	memset(inQ, false, sizeof(inQ));

    	queue <int> q;
    	dist[S] = 0, inQ[S] = true;
    	q.push(S);

    	while (!q.empty()) {
    		int cur = q.front(); q.pop();
    		inQ[cur] = false;
    		for (int next : edges[cur]) {
    			if (c[cur][next] > f[cur][next] && dist[next] > dist[cur] + d[cur][next]) {
    				dist[next] = dist[cur] + d[cur][next];
    				prv[next] = cur;
    				if (!inQ[next]) {
    					q.push(next);
    					inQ[next] = true;
    				}
    			}
    		}
    	}

    	if (prv[T] == -1) break;

    	int flow = INF;
    	for (int i = T; i != S; i = prv[i])
    		flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
    	for (int i = T; i != S; i = prv[i]) {
    		min_salary += flow * d[prv[i]][i];
    		f[prv[i]][i] += flow;
    		f[i][prv[i]] -= flow;
    	}

    	num_of_works++;
    }

    printf("%d\n%d\n", num_of_works, min_salary);

    close();
    return 0;
}
