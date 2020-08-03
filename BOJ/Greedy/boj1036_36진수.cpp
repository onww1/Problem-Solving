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

int n, k;
char in[55];
vector<int> diff[36], sum;

int get_num(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char get_char(int n) {
    if (n < 10) return n + '0';
    return 'A' + n - 10;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < 36; ++i) diff[i].resize(55);
    sum.resize(55);
    for (int i = 0, l; i < n; ++i) {
        scanf(" %s", in);
        for (l = 0; in[l]; ++l);
        for (int j = 0; in[j]; ++j) {
            int num = get_num(in[j]);
            sum[l - 1 - j] += num;
            diff[num][l - 1 - j] += 35 - num;
        }
    }
    for (int i = 0; i < 36; ++i) {
        for (int j = 0; j < 54; ++j) {
            diff[i][j + 1] += diff[i][j] / 36;
            diff[i][j] %= 36;
        }
    }
    sort(diff, diff + 36, [](const vector<int>& a, const vector<int>& b) {
        for (int i = 54; i >= 0; --i) 
            if (a[i] != b[i]) 
                return a[i] > b[i];
        return false;
    });
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < 55; ++j)
            sum[j] += diff[i][j];
    for (int i = 0; i < 54; ++i) {
        sum[i + 1] += sum[i] / 36;
        sum[i] %= 36;
    }
    int f = 0;
    for (int i = 54; i >= 0; --i) {
        if (!sum[i] && !f) continue;
        f = 1;
        printf("%c", get_char(sum[i]));
    }
    if (!f) printf("0");
    puts("");

    close();
    return 0;
}
