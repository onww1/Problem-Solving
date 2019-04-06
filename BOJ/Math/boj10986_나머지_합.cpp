#include <cstdio>
using namespace std;
typedef long long ll;

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
inline ll readLL() {
  ll sum = 0LL;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10LL + now - '0', now = read();
  return sum;
}

int cnt[1050];
int main(int argc, char *argv[]) {
  ll n = readLL(), m = readLL(), i, sum = 0LL, a;
  for (i = 0; i < n; ++i) {
    a = readLL();
    sum += a;
    ++cnt[sum % m];
  }
  ll ans = 0;
  for (i = 0; i < m; ++i) ans += (ll)cnt[i] * (cnt[i] - 1LL) / 2LL;
  return !printf("%lld\n", ans + cnt[0]);
}