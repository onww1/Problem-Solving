#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char *argv[]) {
  int n, x, y, xm = 0, ym = 0;
  char c;
  scanf("%d", &n);
  while (n--) {
    scanf(" %c %d %d", &c, &x, &y);
    if (x > y) swap(x, y);
    if (c == '+') {
      xm = max(xm, x);
      ym = max(ym, y);
    } else if (c == '?') {
      if (xm > x || ym > y) printf("NO\n");
      else printf("YES\n");
    }
  }
  return 0;
}