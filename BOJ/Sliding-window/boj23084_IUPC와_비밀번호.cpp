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

int n, p, m, slen, tlen;
char s[2050], t[2050];

int main(int argc, char *argv[]) {
    open();

    scanf(" %s %d", s, &n);
    vector<int> cnt(26, 0);
    slen = strlen(s);
    for (int i = 0; i < slen; i++) 
        cnt[s[i] - 'a']++;

    for (int i = 0; i < n; i++) {
        scanf(" %s", t);
        tlen = strlen(t);
        if (tlen < slen) {
            puts("NO");
            continue;
        }
        
        vector<int> pcnt(cnt.begin(), cnt.end());
        p = slen; m = 0;
        for (int i = 0; i < slen; i++) {
            int idx = t[i] - 'a';
            if (pcnt[idx] > 0) p--;
            else m++;
            pcnt[idx]--;
        }
        bool isYes = (p == 1 && m == 1) || (tlen > slen && p == 0 && m == 0);
        for (int i = slen; !isYes && i < tlen; i++) {
            int idx = t[i - slen] - 'a';
            if (pcnt[idx] < 0) m--;
            else p++;
            pcnt[idx]++;

            idx = t[i] - 'a';
            if (pcnt[idx] > 0) p--;
            else m++;
            pcnt[idx]--;

            if ((p == 1 && m == 1) || (tlen > slen && p == 0 && m == 0)) isYes = true;
        }

        puts(isYes ? "YES" : "NO");
    }

    close();
    return 0;
}