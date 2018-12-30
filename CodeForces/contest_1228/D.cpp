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

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, i;
  string str;
  ll a[100000];
  ll dp[100000][4] = { 0LL };

  cin >> n >> str >> a[0];
  dp[0][0] = (str[0] == 'h' ? a[0] : 0LL);

  for (i=1; i<n; ++i) {
    cin >> a[i];
    if (str[i] == 'h') dp[i][0] = dp[i-1][0] + a[i];
    else dp[i][0] = dp[i-1][0];
  }
  for (i=1; i<n; ++i) {
    if (str[i] == 'a') dp[i][1] = min(dp[i-1][1] + a[i], dp[i][0]);
    else dp[i][1] = dp[i-1][1];
  }
  for (i=1; i<n; ++i) {
    if (str[i] == 'r') dp[i][2] = min(dp[i-1][2] + a[i], dp[i][1]);
    else dp[i][2] = dp[i-1][2];
  }
  for (i=1; i<n; ++i) {
    if (str[i] == 'd') dp[i][3] = min(dp[i-1][3] + a[i], dp[i][2]);
    else dp[i][3] = dp[i-1][3];
  }
  cout << dp[n-1][3] << '\n';

  return 0;
}
