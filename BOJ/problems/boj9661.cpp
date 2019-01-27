#include <cstdio>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  int a[5] = {1, 0, 1, 0, 0};  
  ll n;
  scanf("%lld", &n);
  return !printf("%s\n", a[n%5LL] ? "CY" : "SK");
}
