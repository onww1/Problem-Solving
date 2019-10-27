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

int k, d, l, x[7], y[7];
vector <piii> v;

int _abs(int a) { return a < 0 ? -a : a; }

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &k);
    for (int i = 1; i <= 6; ++i) {
    	scanf("%d %d", &d, &l);
    	if (d >= 3) {
    		x[i] = x[i - 1];
    		if (d == 4) {
    			y[i] = y[i - 1] + l;
    			v.push_back({x[i], {y[i - 1], y[i]}});
    		}
    		else {
    			y[i] = y[i - 1] - l;
    			v.push_back({x[i], {y[i], y[i - 1]}});
    		}
    	}
    	else {
    		if (d == 1) x[i] = x[i - 1] + l;
    		else x[i] = x[i - 1] - l;
    		y[i] = y[i - 1];
    	} 
    }

    sort(v.begin(), v.end());
    int area = (v[1].X - v[0].X) * (v[0].Y.Y - v[0].Y.X) + (v[2].X - v[1].X) * (v[2].Y.Y - v[2].Y.X);
    printf("%d\n", area * k);

    close();
    return 0;
}
