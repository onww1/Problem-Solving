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

int get_gcd(int a, int b) {
  if (a < b) return get_gcd(b, a);
  int gcd_val = b;
  while (a % gcd_val) {
    b = a % gcd_val;
    a = gcd_val;
    gcd_val = b;
  }
  return gcd_val;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t, n, gcd_val, val;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 180) {
      cout << -1 << '\n';
      continue;
    }
    
    int min = MOD;
    

    if (n >= 90) {
      if (360 % (180 - n) == 0) {
        val = 360 / (180 - n);
      } else {
        gcd_val = get_gcd(360, 2 * n);
        val = 360 / gcd_val;
      }
    } else {
      gcd_val = get_gcd(360, 2 * n);
      val = 360 / gcd_val;
    }
    cout << val << '\n';
  }

  return 0;
}
