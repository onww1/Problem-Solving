#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, HMX, C;
pii P[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &P[i].X, &P[i].Y);
        if (HMX < P[i].Y) {
            HMX = P[i].Y;
            C = 1;
        } else if (HMX == P[i].Y) C++;
    }
    sort(P, P + N);

    vector <pii> st;
    st.push_back({0, 0});

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (C && ((!st.empty() && st.back().Y < P[i].Y) || P[i].Y == HMX)) {
            ans += (st.back().Y * (P[i].X - st.back().X));
            st.push_back(P[i]);
        } 
        if (!C) {
            while (!st.empty() && st.back().Y < P[i].Y) st.pop_back();
            st.push_back(P[i]);
        }

        if (P[i].Y == HMX) C--;
    }

    for (int i = st.size() - 1; i >= 0; --i) {
        if (st[i].Y == HMX) {
            ans += HMX;
            break;
        } else ans += st[i].Y * (st[i].X - st[i - 1].X);
    }

    printf("%d\n", ans);
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

// int n, mxh, mnl, mxl;
// pii p[1001];

// int main(int argc, char *argv[]) {
//     open();

//     scanf("%d", &n);
//     for (int i = 0; i < n; ++i) {
//         scanf("%d %d", &p[i].X, &p[i].Y);
//         if (mxh < p[i].Y) {
//             mxh = p[i].Y;
//             mnl = mxl = p[i].X;
//         } else if (mxh == p[i].Y) {
//             mnl = min(mnl, p[i].X);
//             mxl = max(mxl, p[i].X);
//         }
//     }
//     sort(p, p + n);
//     int ans = mxh * (mxl - mnl + 1);
    
//     pii prv = p[0];
//     for (int i = 1; i < n; ++i) {
//         if (p[i].Y > prv.Y) {
//             ans += prv.Y * (p[i].X - prv.X);
//             prv = p[i];
//         }
//         if (prv.Y == mxh) break;
//     }

//     prv = p[n - 1];
//     for (int i = n - 2; i >= 0; --i) {
//         if (p[i].Y > prv.Y) {
//             ans += prv.Y * (prv.X - p[i].X);
//             prv = p[i];
//         }
//         if (prv.Y == mxh) break;
//     }

//     printf("%d\n", ans);

//     close();
//     return 0;
// }
