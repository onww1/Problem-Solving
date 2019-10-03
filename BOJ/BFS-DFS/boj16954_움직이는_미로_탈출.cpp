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
typedef pair<int, pii> piii;
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

char in[8][9];
int vv[8][8], t, r, c;

int main(int argc, char *argv[]) {
    open();

    for (int i = 0; i < 8; ++i) scanf(" %s", in[7 - i]);

    queue <ti3> q;
    q.push({0, 0, 0}); vv[0][0] = 1;
    while (!q.empty()) {
        tie(t, r, c) = q.front(); q.pop();
        if (r == 7 && c == 7) return !printf("1");
        for (int k = 0; k < 8; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr > 7 || dc < 0 || dc > 7) continue;
            if (dr + t < 8 && in[dr + t][dc] == '#') continue;
            if (!vv[dr][dc] && (dr + t > 6 || in[dr + t + 1][dc] != '#')) {
                vv[dr][dc] = 1;
                q.push({t + 1, dr, dc});
            }
        }
        if (vv[r][c] < 8 && (r + t > 6 || in[r + t + 1][c] != '#')) {
            vv[r][c]++;
            q.push({t + 1, r, c});
        }
    }

    puts("0");
    close();
    return 0;
}