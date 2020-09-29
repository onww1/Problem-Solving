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
    int size;
    vector<vector<int>> mat;
    matrix(): matrix(1){}
    matrix(int _size) {
        this->size = _size;
        this->mat.resize(size, vector<int>(size, 0));
    }
    void add_element(int r, int c, int v) {
        this->mat[r][c] = v;
    }
    void print() {
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                printf("%d ", this->mat[i][j]);
            }
            puts("");
        }
    }
    matrix operator* (const matrix &other) const {
        matrix ret(this->size);
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                for (int k = 0; k < this->size; ++k) {
                    ret.mat[i][j] = (ret.mat[i][j] + 1LL * this->mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
};

matrix identity_matrix(int size) {
    matrix ret(size);
    for (int i = 0; i < size; ++i) ret.add_element(i, i, 1);
    return ret;
}

matrix pow(matrix base, int exp) {
    matrix ret = identity_matrix(base.size);
    while (exp) {
        if (exp & 1) ret = ret * base;
        base = base * base;
        exp >>= 1;
    }
    return ret;
}

int t, n, d, m;
matrix ps[101];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &t, &n, &d);
    ps[0] = identity_matrix(n);
    for (int i = 1; i <= t; ++i) {
        scanf("%d", &m);
        ps[i] = matrix(n);
        for (int j = 0, a, b, c; j < m; ++j) {
            scanf("%d %d %d", &a, &b, &c);
            ps[i].add_element(--a, --b, c);
        }
        ps[i] = ps[i - 1] * ps[i];
    }
    matrix ans = pow(ps[t], d / t);
    ans = ans * ps[d % t];
    ans.print();

    close();
    return 0;
}
