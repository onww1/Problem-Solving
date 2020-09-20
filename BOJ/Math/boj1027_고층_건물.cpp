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

struct slope {
    ll nu, de;
    slope(): slope(0, 1){}
    slope(int _nu, int _de): nu(_nu), de(_de){}
    bool operator< (const slope &other) const {
        return nu * other.de < other.nu * de;
    }
};

int n, h[51];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", h + i);

    int mx = 0;
    vector<slope> st;
    for (int i = 1; i <= n; ++i) {
        st.clear();
        if (i > 1) st.emplace_back(h[i - 1] - h[i], 1);
        for (int j = i - 2; j > 0; --j) {
            slope val(h[j] - h[i], i - j);
            if (st.back() < val) st.push_back(val);
        }
        if (i < n) st.emplace_back(h[i + 1] - h[i], 1);
        for (int j = i + 1; j <= n; ++j) {
            slope val(h[j] - h[i], j - i);
            if (st.back() < val) st.push_back(val);
        }
        mx = max(mx, (int)st.size());
    }

    printf("%d\n", mx);

    close();
    return 0;
}
