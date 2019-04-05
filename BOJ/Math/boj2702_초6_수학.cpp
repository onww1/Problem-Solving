#include <cstdio>
using namespace std;

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

int get_lcm(int a, int b) {
  int gcd_val = get_gcd(a, b);
  return a / gcd_val * b;
}

int main(int argc, char *argv[]) {
  int t, a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    printf("%d %d\n", get_lcm(a, b), get_gcd(a, b));
  }
  return 0;
}