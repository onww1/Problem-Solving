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

int N;

bool isPrime(int V) {
    if (V % 2 == 0) return false;
    for (int i = 3; i * i <= V; i += 2)
        if (V % i == 0) return false;
    return true;
}

void solve(int V, int L) {
    if (L == N) { printf("%d\n", V); return; }

    for (int i = 1; i < 10; i += 2) 
        if (isPrime(V * 10 + i)) 
            solve(V * 10 + i, L + 1);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &N);
    solve(2, 1);
    solve(3, 1);
    solve(5, 1);
    solve(7, 1);
    return 0;
}