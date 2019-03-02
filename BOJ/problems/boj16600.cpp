#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
  long long a;
  scanf("%lld", &a);
  printf("%.12Lf\n", (long double)sqrt(a) * 4);
  return 0;
}