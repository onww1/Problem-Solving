/*
 *  BOJ 11439. 이항 계수 5
 * 
 *  모듈러가 소수가 아니고 임의의 수라서 처음엔 막막했는데 너무 
 *  소수로 되어 있는 문제처럼 생각하려고 해서 그랬었네요. 
 *  n과 k가 400만으로 그렇게 큰 수는 아니므로 소인수분해를 해서 
 *  nCk에 어떤 소인수들이 몇 개씩 있는지 확인하고 그것을 곱해나가면 됐습니다.
 *  
 *  처음에는 각 수마다 소인수 중 가장 작은 수를 표기해놓은 다음,
 *  그것을 토대로 각 수를 소인수분해하면서 어떤 소인수가 몇개가 있는지를 
 *  체크해 나갔습니다. 이렇게 하니 꽤 느리더군요. 
 * 
 *  그래서 다른 분들의 코드를 보면서 공부해보니 저희가 1번 문제를 풀었던 것처럼 하면
 *  어떤 소인수가 몇개 있는지를 금방 할 수 있으니 더 빨랐습니다.
 *  
 *  각각의 방법은 그 코드 위에 쓰겠습니다.
 *  이번 문제를 풀면서 얻은 소득은 거듭 제곱을 재귀로 하는게 더 빠르다는 것을 알았다는 것입니다.
 */

#include <cstdio>
typedef long long ll;
const int MAX = 4000000;

// 반복문으로 거듭제곱 구하기 with D&C
// ll get_pow(ll base, ll exp, ll mod) {
//   ll ret = 1LL;
//   while (exp) {
//     if (exp % 2) ret = ret * base % mod;
//     base = base * base % mod;
//     exp /= 2LL;
//   }
//   return ret;
// }

// 재귀로 거듭제곱 구하기 with D&C
ll get_pow(ll base, ll exp, ll mod) {
  if (!exp) return 1LL;
  if (exp % 2LL) return base * get_pow(base, exp - 1LL, mod) % mod;
  ll half = get_pow(base, exp / 2LL, mod);
  return half * half % mod;
}

/*******************************************************************/

/*
 *  처음 버전
 * 
 *  시간 복잡도 : O(NloglogN + Ksqrt(N/logN))
 *  공간 복잡도 : O(N)
 * 
 *  먼저 에라토스테네스의 체를 이용하여 각 수마다 소인수 중 가장 작은 소인수가 무엇잇지 
 *  표시를 해두고, 이항계수를 구하는 식에서 각 값마다 소인수분해를 해서 소인수의 갯수를 
 *  구하고 모두 곱해줍니다.
 */

// int cnt[MAX + 1], low[MAX + 1];
// int main(int argc, char *argv[]) {
//   int n, k, m;
//   scanf("%d %d %d", &n, &k, &m);
//   if (k == 0 || k == n) return !printf("1\n");

//   // 각 수마다 가장 작은 소인수 표시
//   for (ll i = 2; i <= n; ++i) 
//     if (!low[i]) for (ll j = i; i * j <= n; ++j) low[i * j] = i;

//   if (k > n/2) k = n - k;
//   for (int i = 0, tmp; i < k; ++i) {
//     // 각 수마다 소인수 분해를 해서 해당 소인수의 cnt를 올려줌
//     tmp = n - i;
//     while (low[tmp]) cnt[low[tmp]]++, tmp /= low[tmp];
//     ++cnt[tmp];

//     tmp = k - i;
//     while (low[tmp]) cnt[low[tmp]]--, tmp /= low[tmp];
//     --cnt[tmp];
//   }

//   // 구한 모든 소인수를 곱하고 모듈러 연산을 한 값을 출력
//   ll res = 1LL;
//   for (int i = 2; i <= n; ++i) 
//     if (cnt[i]) res = res * get_pow(i, cnt[i], m) % m;
//   return !printf("%lld\n", res);
// }

/*******************************************************************/

/*
 *  나중 버전
 * 
 *  시간 복잡도 : O(NloglogN * logN)
 *  공간 복잡도 : O(N)
 * 
 *  에라토스테네스의 체를 이용하여 소수를 찾고 그 찾은 소수에 대해서 
 *  문제 1번(BOJ2004)에서처럼 n!, k!, (n-k)!에 대한 그 소수의 갯수를 구하고,
 *  적절한 계산을 통해 nCk가 가지고 있는 그 소수의 갯수를 구합니다. 
 *  그리고 구한 이 값을 바로 결과값에 적용시킵니다.
 *  이렇게 쭉 n까지 하고나면 답이 나옵니다.
 */

int count(int base, int n) {
  int cnt = 0;
  while (n) {
    cnt += n / base;
    n /= base;
  }
  return cnt;
}

bool noPrime[MAX + 1];
int main(int argc, char *argv[]) {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  if (k == 0 || k == n) return !printf("1\n");
  
  ll res = 1LL;
  for (int i = 2; i <= n; ++i) {
    if (!noPrime[i]) {
      noPrime[i] = true;
      for (ll j = (ll)i * i; j <= n; j += i) noPrime[j] = true;
      int cnt = count(i, n) - count(i, k) - count(i, n-k);
      res = res * get_pow(i, cnt, m) % m;
    }
  }
  return !printf("%lld\n", res);
}