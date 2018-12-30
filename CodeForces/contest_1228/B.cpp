#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define MOD 998244353
using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  string str;

  cin >> n >> str;
  bool con[26] = {false};
  int c_idx[26][2] = {0}, val;
  memset(c_idx, -1, sizeof(int) * 26 * 2);

  for (int i=0; i<n; ++i) {
    val = str[i] - 'a';
    if (c_idx[val][0] < 0) {
      con[val] = true;
      c_idx[val][0] = i;
      c_idx[val][1] = i;
    } else c_idx[val][1] = i;
  }

  
  
  int l, r, lx, rx;
  ll cnt = 1;
  for (int i=0; i<26; ++i) {
    if (!con[i]) continue;
    l = 400000;
    r = -1;
    for (int j=0; j<26; ++j) {
      if (con[j] && i != j) {
        l = c_idx[j][0] < l ? c_idx[j][0] : l;
        r = c_idx[j][1] > r ? c_idx[j][1] : r;
      }
    }
    if (l == 0 && r == n-1) continue;

    if (c_idx[i][0] < l) lx = l - c_idx[i][0] + 1;
    else lx = 1;

    if (c_idx[i][1] > r) rx = c_idx[i][1] - r + 1;
    else rx = 1;

    cnt = (cnt + (ll)lx * (ll)rx - 1LL) % MOD;
  }

  cout << cnt << '\n';
  return 0;
}
