#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
  int n, x, cnt = 0;
  scanf("%d", &n);
  int s = 0, e = 1e9, m;
  while (s <= e) {
    cnt++;
    m = (s + e) / 2;
    printf("> %d\n", m);
    fflush(stdout);

    int res;
    scanf("%d", &res);
    if (res) s = m - 1;
    else e = m + 1;
  }

  int mx = s; bool ch = false;
  int a[31]; a[60 - cnt] = mx;
  for (int i = 0; i < 60 - cnt; ++i) {
    printf("? %d\n", i + 1);
    fflush(stdout);
    scanf("%d", a + i);
    if (a[i] == mx) ch = true;
  }

  int len = 60 - cnt + (ch ? 0 : 1);
  sort(a, a + len);
  int dd = a[1] - a[0];
  for (int i = 2; i < len; ++i) {
    dd = _gcd(dd, a[i] - a[i-1]);
  }

  int first = mx - (n - 1) * dd;
  printf("! %d %d\n", first, dd);
  fflush(stdout);
  return 0;
}