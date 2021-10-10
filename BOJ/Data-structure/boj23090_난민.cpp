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

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, x, y;
ll xsum, gsum, lsum;
priority_queue<int> gpq, lpq;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        xsum += abs(x);
        gpq.push(y);
        gsum += y;
        while (lpq.size() + 1 < gpq.size()) {
            int gv = gpq.top();
            lpq.push(-gv);
            gpq.pop();
            gsum -= gv; 
            lsum += gv;
        }
        while (!lpq.empty() && !gpq.empty() && gpq.top() > -lpq.top()) {
            int gv = gpq.top(); gpq.pop();
            int lv = -lpq.top(); lpq.pop();
            gpq.push(lv); lpq.push(-gv);
            gsum += lv - gv;
            lsum += gv - lv;
        }
        ll p = gpq.top();
        printf("%lld %lld\n", p, xsum + lsum - gsum + p * ((ll)gpq.size() - (ll)lpq.size()));
    }

    close();
    return 0;
}