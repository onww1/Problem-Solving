#include <cstdio>
using namespace std;
typedef long long ll;

int n, a[1000001];
ll t[1000001];

char buf[1<<17];
int idx = 1<<17;

inline char read()
{
    if (idx == 1<<17)
    {
        fread(buf, 1, 1<<17, stdin);
        idx = 0;
    }
    return buf[idx++];
}

inline int readInt()
{
    int sum = 0;
    char now = read();
    
    while (now == ' ' || now == '\n') now = read();
    while (now >= '0' && now <= '9')
    {
        sum = sum*10 + now-48;
        now = read();
    }
    
    return sum;
}

int main(int argc, char *argv[]) {
  int m, i, x, y, z, tmp;
  ll sum, psum, diff;
  n = readInt();
  m = readInt();
  for (i = 0; i < m; ++i) {
    x = readInt();
    y = readInt();
    z = readInt();
    if (!x) {
      if (y > z) tmp = y, y = z, z = tmp;
      sum = 0LL, psum = 0LL;
      while (z) {
        sum += t[z];
        z -= (z & -z);
      }
      --y;
      while (y) {
        psum += t[y];
        y -= (y & -y);
      }
      printf("%lld\n", sum - psum);
    }
    else {
      diff = (ll)z - a[y];
      a[y] = z;
      while (y <= n) {
        t[y] += diff;
        y += (y & -y);
      }
    }
  }
  return 0;
}