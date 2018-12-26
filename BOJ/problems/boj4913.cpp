#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  bool isPrime;
  vector<long long> prime;
  prime.push_back(2);
  for (long long i=3; i<1000000; i+=2) {
    isPrime = true;
    for (long long j=0; prime[j] * prime[j] <= i; ++j) {
      if (i % prime[j] == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) prime.push_back(i);
  }

  long long L, U, x, y;
  while (1) {
    cin >> L >> U;
    if (L == -1 && U == -1) break;
    x = y = 0;

    for (int i=0; i<prime.size(); ++i) {
      if (L <= prime[i] && prime[i] <= U) {
        ++x;
        if ((prime[i] - 1) % 4 == 0) ++y;
      } else if (prime[i] > U) break;
    }
    cout << L << ' ' << U << ' ' << x << ' ' << y << '\n';
  }

  return 0;
}