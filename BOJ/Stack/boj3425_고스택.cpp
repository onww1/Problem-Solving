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
const int INF = 1e9;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

vector<pii> ops;
vector<int> st;
char cmd[5];
int n, val;

int main(int argc, char *argv[]) {
    open();

    bool outer_loop = true;
    while (outer_loop) {
        ops.clear(); st.clear();
        bool inner_loop = true;
        while (inner_loop) {
            scanf(" %s", cmd);
            if (!strcmp(cmd, "QUIT")) {
                outer_loop = inner_loop = false;
            } else if (!strcmp(cmd, "END")) {
                inner_loop = false;
            } else if (!strcmp(cmd, "NUM")) {
                scanf("%d", &val);
                ops.emplace_back(1, val);
            } else if (!strcmp(cmd, "POP")) {
                ops.emplace_back(2, 0);
            } else if (!strcmp(cmd, "INV")) {
                ops.emplace_back(3, 0);
            } else if (!strcmp(cmd, "DUP")) {
                ops.emplace_back(4, 0);
            } else if (!strcmp(cmd, "SWP")) {
                ops.emplace_back(5, 0);
            } else if (!strcmp(cmd, "ADD")) {
                ops.emplace_back(6, 0);
            } else if (!strcmp(cmd, "SUB")) {
                ops.emplace_back(7, 0);
            } else if (!strcmp(cmd, "MUL")) {
                ops.emplace_back(8, 0);
            } else if (!strcmp(cmd, "DIV")) {
                ops.emplace_back(9, 0);
            } else if (!strcmp(cmd, "MOD")) {
                ops.emplace_back(10, 0);
            } 
        }
        if (!outer_loop) break;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &val);
            st.clear(); st.push_back(val);
            bool isOK = true;
            for (pii &p: ops) {
                switch (p.X) {
                case 1:
                    st.push_back(p.Y);
                    break;
                case 2:
                    if (st.empty()) isOK = false;
                    else st.pop_back();
                    break;
                case 3:
                    if (st.empty()) isOK = false;
                    else st[(int)st.size() - 1] *= -1;
                    break;
                case 4:
                    if (st.empty()) isOK = false;
                    else st.push_back(st.back());
                    break;
                case 5:
                    if (st.size() < 2) isOK = false;
                    else swap(st[(int)st.size() - 1], st[(int)st.size() - 2]);
                    break;
                case 6:
                    if (st.size() < 2) isOK = false;
                    else {
                        val = st.back(); st.pop_back();
                        st[(int)st.size() - 1] += val;
                        if (abs(st.back()) > INF) isOK = false;
                    }
                    break;
                case 7:
                    if (st.size() < 2) isOK = false;
                    else {
                        val = st.back(); st.pop_back();
                        st[(int)st.size() - 1] -= val;
                        if (abs(st.back()) > INF) isOK = false;
                    }
                    break;
                case 8:
                    if (st.size() < 2) isOK = false;
                    else {
                        val = st.back(); st.pop_back();
                        if (1LL * st.back() * val > INF) isOK = false;
                        else st[(int)st.size() - 1] *= val;
                    }
                    break;
                case 9:
                    if (st.size() < 2) isOK = false;
                    else {
                        val = st.back(); st.pop_back();
                        if (!val) isOK = false;
                        else {
                            ll res = abs(st.back()) / abs(val);
                            if (1LL * st.back() * val < 0) res *= -1;
                            st[(int)st.size() - 1] = (int)res;
                        }
                    }
                    break;
                case 10:
                    if (st.size() < 2) isOK = false;
                    else {
                        val = st.back(); st.pop_back();
                        if (!val) isOK = false;
                        else {
                            int res = abs(st.back()) % abs(val);
                            if (st.back() < 0) res *= -1;
                            st[(int)st.size() - 1] = res;
                        }
                    }
                }
                if (!isOK) break;
            }
            if (!isOK || st.size() != 1) puts("ERROR");
            else printf("%d\n", st.back());
        }
        puts("");
    }


    close();
    return 0;
}
