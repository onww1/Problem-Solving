#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  return !printf("%lld\n", (n * m) / 2LL);
}