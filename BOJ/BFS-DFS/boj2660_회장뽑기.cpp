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

int n, v[51], vis;
vector <int> edges[51];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0, u, v; ; ++i) {
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1) break;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    queue <pii> Q;
    int mn = INF;
    vector <int> ans;
    for (int i = 1, score; i <= n; ++i) {
        ++vis; score = 0;
        Q.push({i, 0}); v[i] = vis;
        while (!Q.empty()) {
            int cur = Q.front().X;
            int d = Q.front().Y;
            Q.pop();

            score = d;
            for (int next : edges[cur]) {
                if (v[next] != vis) {
                    Q.push({next, d + 1});
                    v[next] = vis;
                }
            } 
        }
        if (mn > score) {
            ans.clear(); ans.push_back(i);
            mn = score;
        }
        else if (mn == score) {
            ans.push_back(i);
        }
    }

    printf("%d %lu\n", mn, ans.size());
    for (int v : ans) printf("%d ", v); puts("");

    close();
    return 0;
}