#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#define X first
#define Y second
using namespace std;
typedef pair<char, int> pci;

const int TMAX = 1000005, PMAX = 40;
int F[PMAX], LT, LP;
char in[TMAX], P[PMAX];
deque <char> T;
vector <pci> S;

int main(int argc, char *argv[]) {
    scanf(" %s %s", in, P);
    LT = strlen(in), LP = strlen(P);
    T = deque <char>(in, in + LT);

    // 실패함수 계산
    for (int i = 1, j = 0; i < LP; ++i) {
        while (j > 0 && P[i] != P[j]) j = F[j - 1];
        if (P[i] == P[j]) F[i] = ++j;
    }

    // 매칭
    for (int i = 0; !T.empty();) {
        char cur = T.front();
        T.pop_front();

        i = S.empty() ? 0 : S.back().Y;
        while (i > 0 && P[i] != cur) i = F[i - 1];
        if (P[i] == cur) i++;
        S.push_back({cur, i});

        if (i == LP) {
            for (int j = 0; j < LP; ++j) S.pop_back();
            for (int j = 0; j < LP && !S.empty(); ++j) {
                pci val = S.back(); S.pop_back();
                T.push_front(val.X);
                if (val.Y == 0) break;
            }
        }
    }

    if (S.empty()) puts("FRULA");
    else {
        in[S.size()] = 0;
        while (!S.empty()) in[S.size() - 1] = S.back().X, S.pop_back();
        printf("%s\n", in);
    }

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

// const int MAX = 1e6 + 1;
// const int MOD = 1e9 + 7;
// const int INF = 0x3f3f3f3f;
// const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
// const db PI = acos(-1);
// const ldb ERR = 1e-10;
// const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
// const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

// char in[MAX], p[50];
// int plen;
// vector<int> mat;
// vector<char> v;

// int main(int argc, char *argv[]) {
//     open();

//     scanf(" %s %s", in, p);
//     for (plen = 0; p[plen]; ++plen);
//     for (int i = 0, j = 0; in[i]; ++i) {
//         v.push_back(in[i]);
//         if (in[i] == p[j]) ++j;
//         else j = (in[i] == p[0]);
//         mat.push_back(j);
//         while (j == plen) {
//             for (int k = 0; k < plen; ++k) {
//                 v.pop_back();
//                 mat.pop_back();
//             }
//             if (!mat.empty()) 
//                 j = mat.back();
//             else
//                 j = 0;
//         }
//     }

//     if (v.empty()) puts("FRULA");
//     else {
//         in[v.size()] = 0;
//         for (int i = (int)v.size() - 1; i >= 0; --i) {
//             in[i] = v.back();
//             v.pop_back();
//         }
//         printf("%s\n", in);
//     }

//     close();
//     return 0;
// }
