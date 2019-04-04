#include <cstdio>
#define MOD 45678LL
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ll n;
  scanf("%lld", &n);
  return !printf("%d\n", ( (n - 1LL) * (3LL * n + 8LL) / 2LL + 5LL ) % MOD);
}

