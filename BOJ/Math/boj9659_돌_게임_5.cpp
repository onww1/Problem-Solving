#include <cstdio>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ll n;
  scanf("%lld", &n);
  return !printf("%s\n", n % 2LL ? "SK" : "CY");
}
