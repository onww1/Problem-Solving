#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int in[1005];
int main(int argc, char *argv[]) {
  int n, c, w, i, l;
  ll mx = 0;
  scanf("%d %d %d", &n, &c, &w);
  for (i = 0; i < n; ++i) scanf("%d", in + i);
  sort(in, in + n);
  for (l = 1; l <= in[n-1]; ++l) {
    ll val = 0, sum = 0;
    for (i = 0; i < n; ++i) {
      val = ((1LL * in[i] / l) * (w * l - c));
      if (in[i] % l == 0) val += c; 
      if (val > 0) sum += val;
    }
    mx = max(mx, sum);
  }
  return !printf("%lld\n", mx);
}