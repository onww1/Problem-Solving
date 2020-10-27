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

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, cnt[26];
char in[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf(" %s", in);
    for (n = 0; in[n]; n++) cnt[in[n] - 'a']++;
    
    int ov = -1, cn = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) cn++;
        if (2 * cnt[i] > n) ov = i;
    }

    if (ov != -1) {
        if (cnt[ov] >= n - 1 || (cnt[ov] == n - 2 && cn == 2)) puts("NO");
        else {
            int idx = 0, h = n / 2;
            for (int i = 0; i < h; i++) in[idx++] = ov + 'a';
            cnt[ov] -= h;
            for (int i = 0; i < 26; i++) if (cnt[i] && i != ov) {
                cnt[i]--;
                in[idx++] = i + 'a';
                break;
            }
            while (cnt[ov]--) in[idx++] = ov + 'a';
            for (int i = 0; i < 26; i++) {
                if (i == ov) continue;
                while (cnt[i]--)
                    in[idx++] = i + 'a';
            }
            printf("YES\n%s\n", in);
        }
    } else {
        int idx = 0;
        for (int i = 0; i < 26; i++) 
            while (cnt[i]--) 
                in[idx++] = 'a' + i;
        printf("YES\n%s\n", in);
    }

    close();
    return 0;
}
