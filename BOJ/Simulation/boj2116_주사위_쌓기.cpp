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

int n, a[10001][6];

int solve(int a, int b) {
    if (a > b) swap(a, b);
    if (b != 6) return 6;
    else if (a != 5) return 5;
    return 4;
}

int opposite(int idx) {
    if (idx == 0 || idx == 5) return 5 - idx;
    if (idx == 1 || idx == 3) return 4 - idx;
    if (idx == 2 || idx == 4) return 6 - idx;
    return -1;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < 6; ++j) 
            scanf("%d", a[i] + j);
    
    int mx = 0;
    for (int t = 0; t < 6; ++t) {
        int sum = 0, val = a[0][t];
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < 6; ++k) {
                if (a[i][k] == val) {
                    int tmp = val;
                    val = a[i][opposite(k)];
                    sum += solve(tmp, val);
                    break;
                }
            }
        }
        mx = max(mx, sum);
    }
    printf("%d\n", mx);

    close();
    return 0;
}