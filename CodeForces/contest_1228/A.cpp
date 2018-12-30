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

  int n, l, r;
  cin >> n;
  while (n--) {
    cin >> l >> r;
    bool isEnded = false;
    for (int i = l; !isEnded && i < r; ++i) {
      for (int j = 2; !isEnded && i * j <= r; ++j) {
        cout << i << ' ' << (i * j) << '\n';
        isEnded = true;
      }
    }
  }

  return 0;
}
