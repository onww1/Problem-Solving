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

int n, ans;
vector<int> v;
map<int,int> s;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ans = 1;
    for (int i = 0; i + 1 < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            int len = 2, last = v[j], d = v[j] - v[i], idx = j;
            if (s[d] >= last) continue;
            while (true) {
                last += d;
                auto it = lower_bound(v.begin() + idx + 1, v.end(), last);
                if (it == v.end() || *it != last) break;
                len++; idx = it - v.begin();
            }
            s[d] = last - d;
            ans = max(ans, len);
        }
    }
    printf("%d\n", ans);

    close();
    return 0;
}

