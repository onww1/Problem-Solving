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

int t, m;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m); printf("%d\n", (m + 1) / 2);
        priority_queue <int> mxh;
        priority_queue <int, vector<int>, greater<int>> mnh;
        for (int i = 1, a; i <= m; ++i) {
            scanf("%d", &a);
            while (mxh.size() > mnh.size() && mxh.top() > a) {
                mnh.push(mxh.top());
                mxh.pop();
            }
            mxh.push(a);
            while (!mxh.empty() && !mnh.empty() && mxh.top() > mnh.top()) {
                mnh.push(mxh.top());
                mxh.pop();
            }
            while (mxh.size() > mnh.size() + 1) {
                mnh.push(mxh.top());
                mxh.pop();
            }
            while (mxh.size() < mnh.size() + 1 && !mnh.empty()) {
                mxh.push(mnh.top());
                mnh.pop();
            }
            if (i % 2 == 1) {
                if ((i + 1) / 2 % 10 == 0 || i == m) printf("%d\n", mxh.top());
                else printf("%d ", mxh.top());
            }
        }
    }

    close();
    return 0;
}


// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <unordered_set>
// #include <unordered_map>
// #include <cmath>
// #include <ctime>
// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <map>
// #include <set>
// #define X first
// #define Y second

// #ifdef NON_SUBMIT
// #define TEST(n) (n)
// #else
// #define TEST(n) ((void)0)
// #endif

// #pragma warning(disable:4996)
// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// typedef double db;
// typedef long double ldb;
// typedef pair <int, int> pii;
// typedef pair <ll, ll> pll;
// typedef pair <ll, int> pli;
// typedef pair <int, pii> piii;
// typedef tuple <int, int, int> ti3;

// clock_t start_time, end_time;

// void open() {
//     TEST(freopen("input.txt", "r", stdin));
//     TEST(freopen("output.txt", "w", stdout));
//     TEST(freopen("debug.txt", "w", stderr));
//     TEST(start_time = clock());
// }

// void close() {
//     TEST(end_time = clock());
//     TEST(printf("Total time : %Lf seconds\n", (long double)(end_time - start_time) / CLOCKS_PER_SEC));
// }

// const int MAX = 1e5 + 1;
// const int MOD = 1e9 + 7;
// const int INF = 0x3f3f3f3f;
// const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
// const db PI = acos(-1);
// const ldb ERR = 1e-10;
// const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
// const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

// int t, m;

// int main(int argc, char *argv[]) {
//     open();

//     scanf("%d", &t);
//     while (t--) {
//         scanf("%d", &m);
//         vector<int> ans;
//         priority_queue<int> l;
//         priority_queue<int, vector<int>, greater<int>> r;
//         for (int i = 0, a; i < m; ++i) {
//             scanf("%d", &a);
//             r.push(a);
//             while (!l.empty() && l.top() > r.top()) {
//                 int lval = l.top(); l.pop();
//                 int rval = r.top(); r.pop();
//                 l.push(rval);
//                 r.push(lval);
//             }
//             while (l.size() + 1 < r.size()) {
//                 l.push(r.top()); r.pop();
//             }
//             if (i % 2 == 0) 
//                 ans.push_back(r.top());
//         }
//         printf("%lu\n", ans.size());
//         for (int i = 1; i <= ans.size(); ++i) {
//             printf("%d ", ans[i - 1]);
//             if (i % 10 == 0) puts("");
//         }
//     }

//     close();
//     return 0;
// }
