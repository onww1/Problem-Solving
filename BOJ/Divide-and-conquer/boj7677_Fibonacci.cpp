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

struct matrix {
    int value[2][2];
    matrix(int a11, int a12, int a21, int a22) {
        value[0][0] = a11, value[0][1] = a12;
        value[1][0] = a21, value[1][1] = a22;
    }
    matrix operator * (const matrix other) {
        int retval[2][2]{};
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    retval[i][j] = (retval[i][j] + value[i][k] * other.value[k][j]) % 10000;
        return matrix(retval[0][0], retval[0][1], retval[1][0], retval[1][1]);
    }
};

matrix _pow(matrix base, int exp) {
    matrix ret(1, 0, 0, 1);
    while (exp) {
        if (exp % 2) ret = ret * base;
        base = base * base;
        exp /= 2;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    int n;
    while (true) {
        scanf("%d", &n);
        if (n == -1) break;
        matrix mat(1, 1, 1, 0);
        mat = _pow(mat, n);
        printf("%d\n", mat.value[1][0]);
    }

    close();
    return 0;
}
