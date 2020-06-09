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

char in[MAX];
int n, i;
vector<int> divisors; 

int main(int argc, char *argv[]) {
    open();

    while (true) {
        scanf(" %s", in);
        if (in[0] == '.') break;

        for (n = 0; in[n]; ++n);
        divisors.clear();

        divisors.push_back(1);
        for (i = 2; i * i < n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
        if (i * i == n) 
            divisors.push_back(i);
        
        sort(divisors.begin(), divisors.end());

        int answer = 1;
        for (int divisor: divisors) {
            int pos = n / divisor - 1;
            while (pos > 0) {
                for (i = 0; i < divisor; ++i)
                    if (in[i] != in[divisor * pos + i])
                        break;
                if (i != divisor) 
                    break;
                pos--;
            }
            if (!pos) {
                answer = n / divisor;
                break;
            }
        }

        printf("%d\n", answer);
    }
    
    close();
    return 0;
}
