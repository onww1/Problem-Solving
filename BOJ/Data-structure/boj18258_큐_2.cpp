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

const int BS = 1 << 17;
char buf[BS];

inline char read() {
    static int idx = BS;
    if (idx == BS) {
        int nidx = fread(buf, 1, BS, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return buf[idx++];
}

inline int readInt() {
    int sum = 0;
    char now = read();
    while (now == ' ' || now == '\n' || now == '\t') now = read();
    while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
    return sum;
}

inline void readWord(char *ptr) {
    char now = read();
    while (now == ' ' || now == '\n' || now == '\t') now = read();
    while ('a' <= now && now <= 'z') *(ptr++) = now, now = read();
    *ptr = 0;
}

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, q[2000000], h, t;
char cmd[10];

int main(int argc, char *argv[]) {
    open();

    n = readInt();
    for (int i = 0, x; i < n; ++i) {
        readWord(cmd);
        if (!strcmp(cmd, "push")) {
            x = readInt();
            q[t++] = x;
        } else if (!strcmp(cmd, "pop")) {
            if (h == t) puts("-1");
            else printf("%d\n", q[h++]);
        } else if (!strcmp(cmd, "size")) {
            printf("%d\n", t - h);
        } else if (!strcmp(cmd, "empty")) {
            printf("%d\n", h == t);
        } else if (!strcmp(cmd, "front")) {
            if (h == t) puts("-1");
            else printf("%d\n", q[h]);
        } else {
            if (h == t) puts("-1");
            else printf("%d\n", q[t - 1]);
        }
    }

    close();
    return 0;
}
