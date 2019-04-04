#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define MOD 1000000007
using namespace std;

typedef long long ll;
char map[1000][4];
int dp[4];
int n, cnt = 4;

int get_abs(int a) { return a < 0 ? -a : a; }
int get_min(int a, int b) { return a < b ? a : b; }

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i=0; i<n-2; ++i) scanf("%s", map[i]);
  for (int i=0; i<n-2; ++i) {
    for (int j=0; j<4; ++j) {
      if (map[i][j] == '0') {
        dp[0] += get_min(get_abs(j), 4 - get_abs(j));
        dp[1] += get_min(get_abs(j - 1), 4 - get_abs(j - 1));
        dp[2] += get_min(get_abs(j - 2), 4 - get_abs(j - 2));
        dp[3] += get_min(get_abs(j - 3), 4 - get_abs(j - 3));
        break;
      }
    }
  }

  cnt += get_min(get_min(dp[0], dp[1]), get_min(dp[2], dp[3]));
  cnt += (n-2);
  printf("%d\n", cnt);
  return 0;
}
