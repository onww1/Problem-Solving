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
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Process {
    int i, t, p, b;
    Process(int _i, int _t, int _p, int _b): i(_i), t(_t), p(_p), b(_b) {}
    bool operator< (const Process &other) const {
        if (p - t != other.p - other.t) return p - t < other.p - other.t;
        if (b != other.b) return b > other.b;
        return i > other.i;
    }
};

int main(int argc, char *argv[]) {
    open();

    int n, t, p, b;
    vector<Process> processes;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &t, &p, &b);
        processes.emplace_back(i, t, p, b);
    }

    priority_queue<Process> pq;
    int cur = 0;
    for (int i = 0; i < n;) {
        if (pq.empty()) cur = max(cur, processes[i].t);
        while (i < n && processes[i].t <= cur) {
            pq.push(processes[i]);
            i++;
        }
        Process pc = pq.top(); pq.pop();
        printf("%d ", pc.i);
        cur = max(cur, pc.t) + pc.b;
    }

    while (!pq.empty()) {
        printf("%d ", pq.top().i);
        pq.pop();
    }
    puts("");

    close();
    return 0;
}