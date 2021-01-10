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

const int MAX = 3e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct info {
    int r, c, f;
    info(int _r, int _c, int _f): r(_r), c(_c), f(_f){}
    bool operator< (const info& other) const {
        return r <= other.r && c <= other.c;
    }
};

int n, m, p, r, c, f, dp[1005];
vector<info> infos;

int dist(int a, int b) {
    return infos[a].r + infos[a].c - infos[b].r - infos[b].c;
}

bool check(int f) {
    dp[0] = f;
    for (int i = 1; i < p; i++) {
        dp[i] = -1;
        for (int j = 0; j < i; j++) {
            if (infos[j] < infos[i]) {
                int need = dist(i, j);
                if (need > dp[j]) continue;
                dp[i] = max(dp[i], dp[j] - need + infos[i].f);
            }
        }
    }
    return dp[p - 1] != -1;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &p);
    infos.emplace_back(1, 1, 0); 
    infos.emplace_back(n, m, 0);
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &r, &c, &f);
        infos.emplace_back(r, c, f);
    }

    sort(infos.begin(), infos.end(), [&](info a, info b) {
        return a.r == b.r ? a.c < b.c : a.r < b.r;
    });
    p += 2;

    int lo = 0, hi = n + m - 2;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }    

    printf("%d\n", lo);

    close();
    return 0;
}
