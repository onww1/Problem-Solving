#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

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

inline ll readLongLong() {
  ll sum = 0LL, sign = 1LL;
  char now = read();

  while (now == ' ' || now == '\n') now = read();
  if (now == '-') sign = -1LL, now = read();
  while ('0' <= now && now <= '9') {
    sum = sum * 10LL + now - '0';
    now = read();
  }
  return sign * sum;
}

int main(int argc, char *argv[]) {
  ll n, i, val, a[1000050];
  n = readLongLong();
  for (i = 0; i < n; ++i) 
    a[i] = readLongLong();
  sort(a, a + n);
  
  int cnt = 1, mx = 1;
  val = a[0];
  for (i = 1; i < n; ++i) {
    if (a[i-1] == a[i]) ++cnt;
    else {
      if (cnt > mx) {
        val = a[i-1];
        mx = cnt;
      }
      cnt = 1;
    }
  }

  if (cnt > mx) {
    val = a[n-1];
    mx = cnt;
  }

  return !printf("%lld\n", val);
}