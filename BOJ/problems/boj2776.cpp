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

const int BUFFER_SIZE = 1 << 17;
char buf[BUFFER_SIZE];
inline char read() {
    static int idx = BUFFER_SIZE;
    if (idx == BUFFER_SIZE) {
        int nidx = fread(buf, 1, BUFFER_SIZE, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return buf[idx++];
}
inline int readInt() {
    int sum = 0, flg = 0;
    char now = read();
    while (now == ' ' || now == '\n') now = read();
    if (now == '-') flg = 1, now = read();
    while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
    return flg ? -sum : sum;
}

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

set <int> s;
int T, N, M, A;

int main(int argc, char *argv[]) {
    open();

    T = readInt();
    while (T--) {
        s.clear();
        N = readInt();
        for (int i = 0; i < N; ++i) {
            A = readInt();
            s.insert(A);
        }
        M = readInt();
        for (int i = 0; i < M; ++i) {
            A = readInt();
            printf("%d\n", s.find(A) == s.end() ? 0 : 1);
        }
    }
    return 0;
}