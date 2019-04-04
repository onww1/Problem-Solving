/*
 *  BOJ 11401. 이항 계수 3
 * 
 *  시간 복잡도 : O(klogMOD)
 *  공간 복잡도 : O(1)
 * 
 *  처음에 1부터 n까지 곱하는 factorial을 구하는 과정에서 중간에 
 *  k!과 (n-k)!을 만나면 이 수의 모듈러 곱셈 역원을 구해서 곱해주는 식으로 했다가,
 *  나중에 nCk = n * (n-1) * ... * (n-k+1) / (k * (k-1) * ... * 1) 임을
 *  이용하여 모듈러 곱셈 역원을 한 번만 구하도록 했습니다.
 * 
 *  모듈러 곱셈 역원은 페르마의 소정리를 이용하여 구할 수 있습니다.
 *  어떤 소수 p에 대하여 a^(p-1) = 1 (mod p)이므로 양변을 a로 나누면
 *  a^(p-2) = a^-1 (mod p) 입니다. 즉, a^(p-2)가 a의 모듈러 곱셈 역원이 됩니다.
 */

#include <cstdio>
typedef long long ll;
const ll MOD = 1e9 + 7;

// 분할정복을 이용한 지수 계산
ll pow(ll base, ll exp) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2LL) ret = ret * base % MOD;
    base = base * base % MOD;
    exp /= 2LL;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  ll n, k, nu, de, i;
  scanf("%lld %lld", &n, &k);
  k = k > n/2 ? n-k : k;
  for (nu = de = 1, i = 0; i < k; ++i) {
    nu = nu * (n - i) % MOD;  // numerator
    de = de * (k - i) % MOD;  // denominator
  }
  return !printf("%lld\n", nu * pow(de, MOD - 2) % MOD);
}

// int main(int argc, char *argv[]) {
//   ll n, k, i = 1LL, a = 1LL, ans = 1LL;
//   scanf("%lld %lld", &n, &k);
//   if (n == k || k == 0) return !printf("1\n"); 
//   k = n - k < k ? n - k : k;

//   for (; i <= k; ++i) a = a * i % MOD;
//   ans = ans * pow(a, MOD - 2) % MOD;
//   for (; i <= n - k; ++i) a = a * i % MOD;
//   ans = ans * pow(a, MOD - 2) % MOD;
//   for (; i <= n; ++i) a = a * i % MOD;
//   ans = ans * a % MOD;
//   return !printf("%lld\n", ans);
// }
