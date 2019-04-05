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

int A, B, C;
bool visited[201][201][201], CC[201];

int main(int argc, char *argv[]) {
    open();
  
    scanf("%d %d %d", &A, &B, &C);
    queue <piii> Q;
    Q.push({C, {0, 0}});
    visited[0][0][C] = CC[C] = true;

    while (!Q.empty()) {
        int WC = Q.front().X;
        int WA = Q.front().Y.X;
        int WB = Q.front().Y.Y;
        Q.pop();

        if (WA == 0) CC[WC] = true;

        // C -> A
        if (WA + WC > A && !visited[A][WB][WA + WC - A]) {
            visited[A][WB][WA + WC - A] = true;
            Q.push({WA + WC - A, {A, WB}});
        } else if (WA + WC <= A && !visited[WA + WC][WB][0]) {
            visited[WA + WC][WB][0] = true;
            Q.push({0, {WA + WC, WB}});
        }

        // C -> B
        if (WB + WC > B && !visited[WA][B][WB + WC - B]) {
            visited[WA][B][WB + WC - B] = true;
            Q.push({WB + WC - B, {WA, B}});
        } else if (WB + WC <= B && !visited[WA][WB + WC][0]) {
            visited[WA][WB + WC][0] = true;
            Q.push({0, {WA, WB + WC}});
        }

        // B -> A
        if (WA + WB > A && !visited[A][WA + WB - A][WC]) {
            visited[A][WA + WB - A][WC] = true;
            Q.push({WC, {A, WA + WB - A}});
        } else if (WA + WB <= A && !visited[WA + WB][0][WC]) {
            visited[WA + WB][0][WC] = true;
            Q.push({WC, {WA + WB, 0}});
        }

        // B -> C
        if (WB + WC > C && !visited[WA][WB + WC - C][C]) {
            visited[WA][WB + WC - C][C] = true;
            Q.push({C, {WA, WB + WC - C}});
        } else if (WB + WC <= C && !visited[WA][0][WB + WC]) {
            visited[WA][0][WB + WC] = true;
            Q.push({WB + WC, {WA, 0}});
        }

        // A -> B
        if (WA + WB > B && !visited[WA + WB - B][B][WC]) {
            visited[WA + WB - B][B][WC] = true;
            Q.push({WC, {WA + WB - B, B}});
        } else if (WA + WB <= B && !visited[0][WA + WB][WC]) {
            visited[0][WA + WB][WC] = true;
            Q.push({WC, {0, WA + WB}});
        }

        // A -> C
        if (WA + WC > C && !visited[WA + WC - C][WB][C]) {
            visited[WA + WC - C][WB][C] = true;
            Q.push({C, {WA + WC - C, WB}});
        } else if (WA + WC <= C && !visited[0][WB][WA + WC]) {
            visited[0][WB][WA + WC] = true;
            Q.push({WA + WC, {0, WB}});
        }
    }

    for (int i = 0; i <= C; ++i) if (CC[i]) printf("%d ", i);
    puts("");

    return 0;
}