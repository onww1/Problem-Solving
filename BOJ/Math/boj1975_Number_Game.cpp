#include <cstdio>

int get_pow(int base, int exp) {
  int ret = 1;
  while (exp) {
    if (exp % 2) ret *= base;
    base *= base;
    exp /= 2;
  }
  return ret;
}

int DP[1001];
int main(int argc, char *argv[]) {
  int t, n, i, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n == 1 || DP[n] > 0) {
      printf("%d\n", DP[n]);
      continue;
    }

    int cnt[1001] = {}, num[10] = {};
    int &dp = DP[n];
    for (i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        cnt[i]++;
        n /= i;
      }
    }
    if (n > 1) cnt[n]++;
    
    int ans = 0, tmp = 1;
    for (i = 2; i < 1000; ++i) num[cnt[i]]++;
    for (i = 1; i < 10; ++i) {
      tmp = 1;
      for (j = i; j < 10; ++j) tmp *= get_pow(j/i + 1, num[j]);
      ans += (tmp - 1);
    }
    dp = ans;
    printf("%d\n", ans);
  }
  return 0;
}