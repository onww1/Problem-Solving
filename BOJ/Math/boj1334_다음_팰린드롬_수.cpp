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

int n;
char in[52] = {'0', };

int main(int argc, char *argv[]) {
    open();

    scanf(" %s", in + 1);
    for (n = 0; in[n + 1]; ++n);
    int l = (n + 1) / 2;
    int r = (n + 1) / 2 + (n % 2 == 0);

    bool flag = true;
    while (l > 0) {
        if (in[l] != in[r]) {
            if (in[l] > in[r]) flag = false;
            break;
        }
        l--; r++;
    }

    if (flag) {
        for (l = (n + 1) / 2; l >= 0; --l) {
            in[l]++;
            if (in[l] > '9') {
                in[l] -= 10;
                if (l == 1) {
                    n++;
                    in[1] = '1';
                    if (n > 2) in[(n + 1) / 2] = '0';
                    break;
                }
                continue;
            }
            break;
        }
    }

    l = (n + 1) / 2;
    r = (n + 1) / 2 + (n % 2 == 0);
    while (l >= 1) {
        in[r] = in[l];
        r++; l--;
    }

    in[n + 1] = 0;
    printf("%s\n", in + 1);

    close();
    return 0;
}
