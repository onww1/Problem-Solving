#include <cstdio>
using namespace std;
typedef long long ll;

bool noPrime[1000005];
int main(int argc, char *argv[]) {
  ll i, j;
  for (i = 2; i * i <= 1000000; ++i) {
    if (!noPrime[i]) {
      printf("%lld ", i);
      for (j = i; i * j <= 1000000; ++j) 
        noPrime[i * j] = true;
    }
  }
  for (; i <= 1000000; ++i)
    if (!noPrime[i]) printf("%lld ", i);
  return !printf("\n"); 
}