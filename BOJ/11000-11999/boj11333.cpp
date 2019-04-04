#include <cstdio>
using namespace std;

const long long MOD = 1000000007LL;
long long DP[10050];

void init() {
  DP[0] = 1LL, DP[3] = 3LL, DP[6] = 13LL;
  for (int i = 9; i < 10000; i += 3) 
    DP[i] = (5LL * DP[i - 3] - 3LL * DP[i - 6] + DP[i - 9] + MOD * MOD) % MOD;
}

int main(int argc, char *argv[]) {
  int t, n, i;
  init();  
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%lld\n", DP[n]);
  }
  return 0;
}
