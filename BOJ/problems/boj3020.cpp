#include <cstdio>
using namespace std;

char buf[1 << 20];
inline char read() {
  static int idx = 1 << 20;
  if (idx == 1 << 20) {
    int nidx = fread(buf, 1, 1 << 20, stdin);
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

int a[500001], b[500001];
int main(int argc, char *argv[]) {
  int n = readInt(), h = readInt(), in, i;
  for (i = 0; i < n; ++i) {
    in = readInt();
    if (i % 2) b[in]++;
    else a[in]++; 
  }

  for (i = h - 1; i >= 0; --i) {
    a[i] += a[i + 1];
    b[i] += b[i + 1];
  }

  int mn = 1e9, mn_cnt = 0, c;
  for (i = 1; i <= h; ++i) {
    c = a[i] + b[h-i+1];
    if (c < mn) mn = c, mn_cnt = 1;
    else if (c == mn) mn_cnt++;
  }
  return !printf("%d %d\n", mn, mn_cnt);
}

// int lower_bound(int *a, int size, int d) {
//   int s = 0, e = size, m;
//   while (s < e) {
//     m = (s + e) / 2;
//     if (a[m] >= d) e = m;
//     else s = m + 1;
//   }
//   return e;
// }

// int upper[100005], lower[100005];
// int main(int argc, char *argv[]) {
//   int n, h, i, u, l;
//   scanf("%d %d", &n, &h); n /= 2;
//   for (i = 0; i < n; ++i) {
//     scanf("%d %d", &u, &l);
//     upper[i] = u; lower[i] = l;
//   }
//   sort(upper, upper + n);
//   sort(lower, lower + n);

//   int mn = 1e9, mn_cnt = 0, cnt;
//   for (i = 1; i <= h; ++i) {
//     cnt = n - lower_bound(lower, n, i);
//     cnt += (n - lower_bound(upper, n, h - i + 1));
//     if (cnt < mn) {
//       mn = cnt;
//       mn_cnt = 1;
//     } else if (cnt == mn) mn_cnt++;
//   }
//   return !printf("%d %d\n", mn, mn_cnt);
// }
