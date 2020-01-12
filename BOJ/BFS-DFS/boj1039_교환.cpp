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

int v[1000001][2], n, m, k;

int get_len(int num) {
    int ret = 0;
    while (num) {
        num /= 10;
        ret++;
    }
    return ret;
}

int get_number(char *str, int len) {
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        ret = ret * 10 + str[i] - '0';
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &k);
    m = get_len(n);

    queue <int> q[2];
    v[n][0] = 1; q[0].push(n);
    
    for (int i = 0; i < k; ++i) {
        int turn = i % 2;
        while (!q[turn].empty()) {
            int cur = q[turn].front();
            q[turn].pop();
            
            char nstr[10]{};
            for (int j = m - 1; j >= 0; --j) {
                nstr[j] = (cur % 10) + '0';
                cur /= 10;
            }
            
            for (int j = 0; j < m - 1; ++j) {
                for (int l = j + 1; l < m; ++l) {
                    if (j == 0 && nstr[l] == '0') continue;
                    swap(nstr[j], nstr[l]);
                    int number = get_number(nstr, m);
                    swap(nstr[j], nstr[l]);
                    if (v[number][1 - turn]) continue;
                    q[1 - turn].push(number);
                    v[number][1 - turn] = 1;
                }
            }
        }
    }

    int mx = -1, f = k % 2;
    for (int i = 1000000; i > 0; --i) {
        if (v[i][f]) {
            mx = i;
            break;
        }
    }

    if (!f && mx == n && m == 2 && n % 10 == 0) mx = -1;
    else if (m == 1) mx = -1;
    printf("%d\n", mx);

    close();
    return 0;
}
