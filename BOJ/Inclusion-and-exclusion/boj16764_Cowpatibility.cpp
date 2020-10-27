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
typedef pair <int, int> pi2;
typedef pair <int, pi2> pi3;
typedef pair <int, pi3> pi4;
typedef pair <int, pi4> pi5;

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

int n, a[5];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    ll ans = 0, lim = 1 << 5;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", a + j);
        sort(a, a + 5);
        for (int j = 1; j < lim; j++) {
            vector<int> p;
            for (int k = 0; k < 5; k++) 
                if (j & (1 << k)) 
                    p.push_back(a[k]);
            v.push_back(p);
        }
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i - 1]) {
            if (cnt > 1) {
                int p = v[i - 1].size();
                if (p & 1) ans += 1LL * (cnt - 1) * cnt / 2;
                else ans -= 1LL * (cnt - 1) * cnt / 2;
            }
            cnt = 1;
        } else cnt++;
    }
    if (cnt > 1) {
        int p = v.back().size();
        if (p & 1) ans += 1LL * (cnt - 1) * cnt / 2;
        else ans -= 1LL * (cnt - 1) * cnt / 2;
    }
    printf("%lld\n", 1LL * n * (n - 1) / 2 - ans);

    close();
    return 0;
}
