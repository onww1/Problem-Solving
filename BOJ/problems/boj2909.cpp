#include <cstdio>
using namespace std;

int get_pow(int base, int exp) {
  int ret = 1;
  while (exp) {
    if (exp % 2) ret *= base;
    base *= base;
    exp /= 2;
  }
  return ret; 
}
int main(int argc, char *argv[]) {
  int c, k;
  scanf("%d %d", &c, &k);
  c /= get_pow(10, k-1);
  c = (c + 5) / 10;
  c *= get_pow(10, k);
  return !printf("%d\n", c);
}