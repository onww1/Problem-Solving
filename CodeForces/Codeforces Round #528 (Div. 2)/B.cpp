#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll n, k, x;
  cin >> n >> k;

  if (k == 2) cout << (2 * n + 1) << '\n';
  else {
    int mul = n * k;
    for (int R = k-1; R > 0; --R) {
      if (n % R == 0) {
        cout << (mul / R + R) << '\n';
        break;
      }
    }
  }
  
  return 0;

}
