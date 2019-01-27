#include <cstdio>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ll n, a[7] = {1, 0, 1, 0, 0, 0, 0};
  scanf("%lld", &n);
  return !printf("%s\n", a[n%7LL] ? "CY" : "SK");
}
