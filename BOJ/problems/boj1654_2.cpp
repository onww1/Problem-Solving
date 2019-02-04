#include <cstdio>
typedef unsigned long long ull;
const int MAX = 1e6;
int n, k, a[MAX];

bool solve(unsigned len) {
  ull cnt = 0;
  for (int i = 0; i < k; ++i) cnt += (a[i] / len);
  return cnt >= n;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < k; ++i) scanf("%d", a + i);

  unsigned s = 0, e = 1 << 31, m;
  while (s < e) {
    m = (s + e) / 2;
    if (solve(m)) s = m + 1;
    else e = m;
  }
  return !printf("%d\n", solve(s) ? s : s - 1);
}