/*
 *  BOJ 1322. X와 K
 *  
 *  시간 복잡도 : O(logN)
 *  공간 복잡도 : O(1)
 * 
 *  X + Y = X | Y 가 성립하려면 두 수에서 1인 비트가 서로 달라야 합니다.
 *  그리고 K번째로 작은 수를 찾으라고 하는데 이렇게 하려면 그저 X의 비트에서 
 *  0인 부분에 K의 비트를 하위 비트부터 순서대로 넣어주면 됩니다.
 *  그러면 위의 식을 성립하는 K번째로 작은 수가 됩니다.
 */

#include <cstdio>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ll x, k, ans = 0LL, i, j;
  scanf("%lld %lld", &x, &k);

  // 인덱스 i를 통해서 K의 하위비트부터 순차적으로 접근
  for (i = 0, j = 0; i < 31; ++i, ++j) {
    // 인덱스 j를 통해서 X의 하위비트부터 순차적으로 접근
    for (; j < 63; ++j) {
      // x에서 0인 비트를 찾을 경우 true
      if (!(x & (1LL << j))) {
        // K에서 i번째 비트를 뽑아서 j번째 자리에 붙여줌.
        ans = ans | ((k & (1LL << i)) << (j-i));
        break;
      }
    }
  }
  return !printf("%lld\n", ans);
}