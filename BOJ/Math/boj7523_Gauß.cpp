#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int T;
ll N, M;

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  for (int test_case = 1; test_case <= T; ++test_case) {
    scanf("%lld %lld", &N, &M);
    if (test_case > 1) puts("");
    printf("Scenario #%d:\n", test_case);
    if (N * M < 0) {
      bool minus = false;
      if (abs(N) > abs(M)) minus = true;
      N *= -1;
      if (minus) printf("-%lld\n", N * (N + 1) / 2LL - M * (M + 1) / 2LL);
      else printf("%lld\n", M * (M + 1) / 2LL - N * (N + 1) / 2LL);
    } else if (N < 0) {
      N *= -1;
      M *= -1;
      printf("-%lld\n", N * (N + 1) / 2LL - M * (M - 1) / 2LL);
    } else {
      printf("%lld\n", M * (M + 1) / 2LL - N * (N - 1) / 2LL);
    }
  }
  return 0;
}