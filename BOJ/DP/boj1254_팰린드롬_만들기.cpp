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

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int L;
char in[1001];

int main(int argc, char *argv[]) {
    open();

    scanf(" %s", in);
    for (L = 0; in[L]; ++L);

    for (int i = L / 2, j; i < L; ++i) {
        if (i > L / 2 || L % 2 == 0) {
            for (j = 0; i + j < L; ++j) 
                if (in[i + j] != in[i - j - 1]) break;
            if (i + j == L) {
                printf("%d\n", 2 * i);
                break;
            }
        }

        for (j = 1; i + j < L; ++j) 
            if (in[i + j] != in[i - j]) break;
        if (i + j == L) {
            printf("%d\n", i * 2 + 1);
            break;
        }
    }
  
    return 0;
}