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
vector< vector<char> > relation;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m, b, c;
  char v;
  cin >> n;
  relation.resize(n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      cin >> v;
      if (i > j) relation[i].push_back(v);
    }
  }

  cin >> m;
  while (m--) {
    cin >> b >> c;
    if (b == c) cout << '0' << '\n';
    if (b < c) cout << relation[c][b] << '\n';
    else cout << relation[b][c] << '\n';
  }

  return 0;
}
