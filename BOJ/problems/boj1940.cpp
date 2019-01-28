#include <cstdio>
#include <algorithm>
using namespace std;

int a[15000], cnt;
int main(int argc, char *argv[]) {
  int n, m, in, i;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%d", &in);
    a[i] = in;
  }
  sort(a, a+n);

  int s = 0, e = n-1;
  while (s < e) {
    if (a[s] + a[e] == m) ++cnt, ++s, --e;
    else if (a[s] + a[e] > m) --e;
    else ++s;
  }
  return !printf("%d\n", cnt);
}

// int a[100001];
// int main(int argc, char *argv[]) {
//   int n, m, c, i, cnt = 0;
//   scanf("%d %d", &n, &m);
//   for (i = 0; i < n; ++i) {
//     scanf("%d", &c);
//     ++a[c];
//   }
//   int l = 1, r = 100000;
//   while (l < r) {
//     if (l + r == m) cnt += min(a[l], a[r]), ++l, --r;
//     else if (l + r > m) --r;
//     else ++l;
//   }
//   if (2 * r == m) cnt += a[r]/2;
//   return !printf("%d\n", cnt);
// }