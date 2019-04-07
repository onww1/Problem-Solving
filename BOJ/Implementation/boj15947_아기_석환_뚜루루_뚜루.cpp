#define NON_SUBMIT

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

const int MAX = 100000;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

char dict[14][8] = { "baby", "sukhwan", "tururu", "turu",
                     "very", "cute", "tururu", "turu",
                     "in", "bed", "tururu", "turu",
                     "baby", "sukhwan" };
int N;

int main(int argc, char *argv[]) {
  open();

  scanf("%d", &N);
  --N;
  int what = N % 14, t = N / 14;
  if (what % 4 == 2) {
    if (t > 2) printf("tu+ru*%d\n", t + 2);
    else {
      printf("%s", dict[what]);
      for (int i = 0; i < t; ++i) printf("ru");
      puts("");
    }
  }
  else if (what % 4 == 3) {
    if (t > 3) printf("tu+ru*%d\n", t + 1);
    else {
      printf("%s", dict[what]);
      for (int i = 0; i < t; ++i) printf("ru");
      puts("");
    }
  }
  else {
    printf("%s\n", dict[what]);
  }

  return 0;
}