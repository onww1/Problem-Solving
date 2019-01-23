#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char in[1005];
int main(int argc, char *argv[]) {
  int x, y;
  while (1) {
    scanf(" %s", in);
    x = 0, y = 1;
    if (!strcmp(in, "end") || !strcmp(in, "mistake")) return 0;
    while (1) {
      printf("? %d %d\n", x, y);
      fflush(stdout);
      scanf(" %s", in);
      if (in[0] == 'e') return 0;
      else if (in[0] == 'x') {
        int s = x + 1, e = y, m;
        while (s < e) {
          m = (s + e) / 2;
          printf("? %d %d\n", x, m);
          fflush(stdout);
          scanf(" %s", in);
          if (in[0] == 'x') e = m;
          else s = m + 1;
        }
        printf("! %d\n", s);
        fflush(stdout);
        break;
      } else {
        x = y;
        y <<= 1;
      }
    }
  }
}