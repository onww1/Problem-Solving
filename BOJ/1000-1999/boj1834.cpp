#include <cstdio>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ll n;
  scanf("%lld", &n);
  return !printf("%lld\n", (n - 1) * n / 2LL * (n + 1));
}