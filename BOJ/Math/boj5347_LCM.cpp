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
inline ll readLongLong() {
  ll sum = 0LL;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') {
    sum = sum * 10LL + now - '0';
    now = read();
  }
  return sum;
}

ll get_gcd(ll a, ll b) {
  if (a < b) return get_gcd(b, a);
  ll gcd_val = b;
  while (a % gcd_val) {
    b = a % gcd_val;
    a = gcd_val;
    gcd_val = b;
  }
  return gcd_val;
}

ll get_lcm(ll a, ll b) {
  ll gcd_val = get_gcd(a, b);
  return a / gcd_val * b;
}

int main(int argc, char *argv[]) {
  ll n, a, b;
  n = readLongLong();
  while (n--) {
    a = readLongLong();
    b = readLongLong();
    printf("%lld\n", get_lcm(a, b));
  }
  return 0;
}