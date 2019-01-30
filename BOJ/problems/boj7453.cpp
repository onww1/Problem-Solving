#include <cstdio>
#include <algorithm>
using namespace std;

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
  int sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}

int x[16000005], y[16000005], a[4001][4];
int main(int argc, char *argv[]) {
  int n, i, j, c1, c2, tmp;
  long long s = 0;
  n = readInt();
  for (i = 0; i < n; ++i) for (j = 0; j < 4; ++j) a[i][j] = readInt();
  for (i = 0; i < n; ++i) 
    for (j = 0; j < n; ++j) {
      x[i * n + j] = a[i][0] + a[j][1];
      y[i * n + j] = a[i][2] + a[j][3];
    }
  n *= n;
  sort(x, x + n);
  sort(y, y + n);

  bool flag = true;
  for (i = 0, j = n - 1; i < n && j >= 0;) {
    if (flag && (x[i] >= 0 || y[j] <= 0)) {
      flag = false;
      c1 = 0, c2 = 0;
      while (i < n && x[i] < 0) ++i;
      while (j >= 0 && y[j] > 0) --j;
      while (i < n && !x[i]) ++i, ++c1;
      while (j >= 0 && !y[j]) --j, ++c2;
      s += (long long)c1 * c2;
    } else if (x[i] + y[j] == 0) {
      c1 = 0, c2 = 0;
      tmp = x[i];
      while (i < n && tmp == x[i]) ++i, ++c1;
      tmp = y[j];
      while (j >= 0 && tmp == y[j]) --j, ++c2;
      s += (long long)c1 * c2;
    }
    else if (x[i] + y[j] > 0) --j;
    else ++i;
  }

  // for (i = 0; i < n; ++i) {
  //   auto lb = lower_bound(y, y + n, -x[i]);
  //   auto ub = upper_bound(y, y + n, -x[i]);
  //   s += (ub - lb);
  // }
  return !printf("%lld\n", s);
}