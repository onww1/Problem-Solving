/*
 *  BOJ 2004. 조합 0의 개수
 * 
 *  시간 복잡도 : O(logN)
 *  공간 복잡도 : O(1)
 * 
 *  조합이 nCm으로 주어지면 팩토리얼로 표현을 했을 때,
 *    nCm = n! / (m! * (n - m)!)
 *  이죠. 이 식에서 각 팩토리얼이 가지는 2와 5의 갯수를 세어 준 다음,
 *  분자의 갯수에서 분모들의 갯수를 빼주면 최종적으로 nCm이 가지고 있는 
 *  2와 5의 갯수가 나옵니다. 그래서 둘 중에 작은 값의 갯수만큼 0을 가집니다. 
 *  2와 5가 곱해져야만 0이 되니까요!
 */

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

// n!을 소인수분해했을 때, base의 갯수
ll count(int base, int n) {
  ll ret = 0;
  while (n) {
    ret += n / base;
    n /= base;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);

  // 2와 5의 갯수를 세줍니다.
  ll two = count(2, n) - count(2, m) - count(2, n-m);
  ll five = count(5, n) - count(5, m) - count(5, n-m);

  // 최종적으로 2와 5 중에서 더 적은 수를 출력합니다.
  return !printf("%lld\n", min(two, five));
}
