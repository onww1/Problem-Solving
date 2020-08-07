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

int n, len, cnt[105];
char in[105];

struct Trie {
    int v;
    Trie* next[10];
    Trie(int _v): v(_v) { for (int i = 0; i < 10; ++i) next[i] = nullptr; }
    void insert(const char* str, int depth) {
        if (*str == 0) return;
        int val = *str - '0';
        if (next[val] == nullptr) {
            cnt[depth]++;
            next[val] = new Trie(val);
        }
        next[val]->insert(str + 1, depth + 1);
    }
};

int main(int argc, char *argv[]) {
    open();

    scanf("%d %s", &n, in);
    len = strlen(in);
    reverse(in, in + len);
    Trie* root = new Trie(0);
    root->insert(in, 0);
    for (int i = 1; i < n; ++i) {
        scanf(" %s", in);
        reverse(in, in + len);
        root->insert(in, 0);
    }
    for (int i = 0; i < len; ++i)
        if (cnt[i] == n) {
            printf("%d\n", i + 1);
            break;
        }

    close();
    return 0;
}
