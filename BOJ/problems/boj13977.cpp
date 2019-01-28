/*
 *  BOJ 13977. 이항 계수와 쿼리
 * 
 *  시간 복잡도 : O(n + log p)
 *  공간 복잡도 : O(n)
 * 
 *  400만까지 팩토리얼과 모듈러 곱셈 역원을 전처리를 해놓고,
 *  쿼리가 들어올 때 O(1)에 처리를 해주었습니다.
 *  
 *  팩토리얼은 자연스럽게 연속된 자연수의 곱임을 알 수 있습니다.
 *  그런데 팩토리얼의 모듈러 곱셈 역원은 항 간의 어떤 관계를 가졌을까요?
 *  결과부터 말씀드리면 inv[n-1] = inv[n] * n % MOD 입니다. 
 *  이것은 (n-1)! ^ -1 = n * n! ^ -1 이기에 성립하는 것입니다.
 *  따라서 전처리 후 O(1)에 쿼리를 처리할 수 있게 되었습니다.
 */

#include <cstdio>
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX = 4e6;

char buf[1 << 17];
inline char read() {
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

ll pow(ll base, ll exp) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2LL) ret = ret * base % MOD;
    base = base * base % MOD;
    exp /= 2LL;
  }
  return ret;
}

int fac[4000001] = {1}, inv[4000001];
int main(int argc, char *argv[]) {
  int m, n, k;
  for (ll i = 1; i <= MAX; ++i) fac[i] = fac[i-1] * i % MOD;
  inv[MAX] = pow(fac[MAX], MOD - 2);
  for (ll i = MAX; i > 0; --i) inv[i-1] = inv[i] * i % MOD;

  m = readInt();
  while (m--) {
    n = readInt();
    k = readInt();
    printf("%lld\n", (ll)fac[n] * inv[k] % MOD * inv[n-k] % MOD);
  }
  return 0;
}