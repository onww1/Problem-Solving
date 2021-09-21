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
const int move_r[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int move_c[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(int argc, char *argv[]) {
    open();

    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    if (n == 2 || n == 3) {
        puts("-1");
        return 0;
    }
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));
    vector<pii> answer;
    int cnt = 0;

    function<void(int,int)> dfs = [&](int row, int col) {
        if (v[row][col]) return;
        v[row][col] = true;
        cnt++;

        for (int k = 0; k < 8; k++) {
            int dr = row + move_r[k];
            int dc = col + move_c[k];
            if (dr < 1 || dr > n || dc < 1 || dc > n || v[dr][dc]) continue;
            answer.emplace_back(row, col);
            dfs(dr, dc);
        }

        if (cnt <= n * n) {
            answer.emplace_back(row, col);
        }
    };

    dfs(r, c);

    printf("%d\n", (int)answer.size());
    for (pii &p: answer) printf("%d %d\n", p.X, p.Y);

    close();
    return 0;
}