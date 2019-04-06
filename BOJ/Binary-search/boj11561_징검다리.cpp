/*
 *  BOJ 11561. 징검다리 
 * 
 *  징검다리를 최대로 밟는 수를 구하는 문제입니다. 
 *  최대로 밟으려면 처음에 1로 시작해서 늘려가는거죠.
 *  즉, 1부터 시작한 자연수의 연속합 중에서 N을 넘지않는 
 *  최대 수를 찾는 것입니다. 그런데 N의 범위가 10^16이므로 
 *  단순히 찾기 어려울 수 있습니다. 따라서 끝값을 k라고 했을 때, 
 *  k를 이분탐색으로 찾는 것입니다. 자연수의 연속합은 대략 k^2/2 이므로 
 *  범위의 끝을 2e8로 잡았습니다.
 */

#include <cstdio>
typedef long long ll;

int main(int argc, char *argv[]) {
  ll t, n;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    ll s = 1, e = 2e8, m;

    // 이분탐색
    while (s < e) {
      m = (s + e) / 2;
      if (m * (m + 1) > 2LL * n) e = m;
      else s = m + 1;
    }
    printf("%lld\n", s * (s + 1) > 2LL * n ? s - 1 : s);
  }
  return 0;
}