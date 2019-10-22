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

bool d[128][128];
int n;
char in[20];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) {
    	fgets(in, sizeof(in), stdin);
    	d[in[0]][in[5]] = true;
    }

    for (int k = 0; k < 128; ++k)
    	for (int i = 0; i < 128; ++i)
    		for (int j = 0; j < 128; ++j)
    			d[i][j] |= (d[i][k] && d[k][j]);

   	vector <pair<char, char>> v;
   	for (int i = 'A'; i <= 'z'; ++i)
   		for (int j = 'A'; j <= 'z'; ++j)
   			if (i != j && d[i][j]) v.push_back({i, j});

   	printf("%lu\n", v.size());
   	for (int i = 0; i < v.size(); ++i)
   		printf("%c => %c\n", v[i].X, v[i].Y);

    close();
    return 0;
}
