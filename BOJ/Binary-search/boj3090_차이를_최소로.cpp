#include <cstdio>
#include <cstring>
typedef long long ll;
const int MAX = 1e5;

int a[MAX + 1], b[MAX + 1], n, t;
int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);

  int s = 0, e = 1e9, m; ll sum;
  while (s < e) {
    m = (s + e) / 2;
    sum = 0LL;

    memcpy(b, a, sizeof(a));
    for (int i = 0; i < n - 1; ++i)
      if (b[i] + m < b[i + 1]) {
        sum += b[i + 1] - (b[i] + m);
        b[i + 1] = b[i] + m;
      }
    for (int i = n - 1; i > 0; --i)
      if (b[i] + m < b[i - 1]) {
        sum += b[i - 1] - (b[i] + m);
        b[i - 1] = b[i] + m;
      }

    if (sum > t) s = m + 1;
    else e = m;
  }

  m = s;
  memcpy(b, a, sizeof(a));
  for (int i = 0; i < n - 1; ++i)
    if (b[i] + m < b[i + 1]) {
      sum += b[i + 1] - (b[i] + m);
      b[i + 1] = b[i] + m;
    }
  for (int i = n - 1; i > 0; --i)
    if (b[i] + m < b[i - 1]) {
      sum += b[i - 1] - (b[i] + m);
      b[i - 1] = b[i] + m;
    }
    
  for (int i = 0; i < n; ++i) printf("%d ", b[i]);
  return !printf("\n");
}