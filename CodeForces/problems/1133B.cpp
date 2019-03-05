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

const int MAX = 3e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, A[MAX + 1], M, Q;
ll sum = 0;
int main(int argc, char *argv[]) {
  open();

  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", A + i);
    sum += A[i];
  }
  sort(A, A + N, greater<int>());
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d", &Q);
    printf("%lld\n", sum - A[Q - 1]);
  }
  return 0;
}