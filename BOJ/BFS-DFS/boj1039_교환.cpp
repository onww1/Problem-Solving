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

int main(int argc, char *argv[]) {
    open();

    char in[10]; int k, len = 0, flag = 1, c[256]{};
    scanf(" %s %d", in, &k);
    while (in[len]) {
        if (c[in[len]]) flag = 0;
        c[in[len]] = 1;
        len++;
    }
    if (len == 1) return !printf("-1\n");

    int idx = 0;
    while (k) {
        int p = 0, v = -1;
        for (int i = len - 1; i >= idx; --i) {
            if (in[i] > v + '0') {
                p = i;
                v = in[i] - '0';
            }
        }
        if (p == idx) {
            if (k % 2 && flag) {
                swap(in[len - 1], in[len - 2]);
            }
            break;
        }
        else {
            swap(in[idx], in[p]);
            idx++;
        }
        k--;
    }
    printf("%s\n", in);

    close();
    return 0;
}
