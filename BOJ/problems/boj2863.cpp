#include <cstdio>
#include <algorithm>
using namespace std;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }
int _lcm(int a, int b) { return a / _gcd(a, b) * b; }

struct rational {
  int numerator, denominator;
  rational() { numerator = 0; denominator = 1; }
  rational(int n) { numerator = n; denominator = 1; }
  rational(int n, int d) {
    int g = _gcd(n, d);
    numerator = n / g;
    denominator = d / g;
  }

  rational operator+ (const rational &other) {
    int l = _lcm(this->denominator, other.denominator);
    return rational(this->numerator * l / this->denominator + 
                    other.numerator * l / other.denominator, l);
  }
  bool operator< (const rational &other) {
    int l = _lcm(this->denominator, other.denominator);
    return this->numerator * (l / this->denominator) < other.numerator * (l / other.denominator);
  }
};

void rotate(int *a) {
  int tmp = a[0];
  a[0] = a[2]; a[2] = a[3];
  a[3] = a[1]; a[1] = tmp;
}

int main(int argc, char *argv[]) {
  int a[4], i, mx_idx = 0;
  rational mx;
  for (i = 0; i < 4; ++i) scanf("%d", a + i);
  for (i = 0; i < 4; ++i, rotate(a)) {
    rational val = rational(a[0], a[2]) + rational(a[1], a[3]);
    if (mx < val) {
      mx = val;
      mx_idx = i;
    }
  }
  return !printf("%d\n", mx_idx);
}