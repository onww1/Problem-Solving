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

int n, m, h;
deque<pii> p;
vector<int> v;

int dist(pii &a, pii &b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &h);
    for (int i = 0, c; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c);
            if (c == 2) p.emplace_back(i, j);
            else if (c == 1) p.emplace_front(i, j);
        }
    }
    for (int i = 1; i < p.size(); i++) v.push_back(i);

    int mx = 0;
    do {
        int curH = m;
        pii pos = p[0];
        for (int i = 0; i < v.size(); i++) {
            int pos_to_next = dist(pos, p[v[i]]);
            if (pos_to_next > curH) break;
            int next_to_src = dist(p[v[i]], p[0]);
            if (pos_to_next + next_to_src <= curH + h) 
                mx = max(mx, i + 1);
            curH = curH - pos_to_next + h;
            pos = p[v[i]];
        }
    } while (next_permutation(v.begin(), v.end()));

    printf("%d\n", mx);

    close();
    return 0;
}
