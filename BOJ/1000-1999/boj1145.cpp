#include <cstdio>
#include <algorithm>
using namespace std;

int _gcd(int a, int b) { return b ? _gcd(b, a%b) : a; }
int _lcm(int a, int b) { return a / _gcd(a, b) * b; }

int main(int argc, char *argv[]) {
  int p[5] = {0, 0, 1, 1, 1}, a[5], i, mn = 1e9;
  for (i = 0; i < 5; ++i) scanf("%d", a + i);
  do {
    int lcm = 1;
    for (i = 0; i < 5; ++i) if (p[i]) lcm = _lcm(lcm, a[i]);
    mn = min(mn, lcm);
  } while (next_permutation(p, p + 5));
  return !printf("%d\n", mn);
}