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

char in[1000];
bool chk[26];
int main(int argc, char *argv[]) {
    open();
  
    while (1) {
        fgets(in, sizeof(in), stdin);
        if (!strcmp(in, "END") || !strcmp(in, "END\n")) break;
        memset(chk, 0, sizeof(chk));

        bool flag = true;
        for (int i = 0; in[i]; ++i) {
            if (in[i] == ' ') continue;
            else if (in[i] == '\n') in[i] = 0;
            else if (chk[in[i] - 'A']) {
                flag = false;
                break;
            } 
            else chk[in[i] - 'A'] = true;
        }

        if (flag) printf("%s\n", in);
    }

    return 0;
}