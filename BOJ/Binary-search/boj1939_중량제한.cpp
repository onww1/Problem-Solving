#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
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
typedef pair<int, pii> piii;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
}

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, M, S, D;
bool visited[MAX + 1];
vector <pii> edges[MAX + 1];

bool BFS(int mx) {
    memset(visited, false, sizeof(visited));
    queue <int> Q; Q.push(S);
    visited[S] = true;
    
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == D) return true;

        for (pii next : edges[cur]) {
            if (!visited[next.X] && next.Y >= mx) {
                Q.push(next.X);
                visited[next.X] = true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    open();
  
    scanf("%d %d", &N, &M);
    for (int i = 0, A, B, C; i < M; ++i) {
        scanf("%d %d %d", &A, &B, &C);
        edges[A].push_back({B, C});
        edges[B].push_back({A, C});
    }
    scanf("%d %d", &S, &D);

    int lo = 1, hi = 1e9, mid = 1, ans = 1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (BFS(mid)) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}