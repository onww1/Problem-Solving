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

ll get_pow(ll base, ll exp);

char in[500050];
int main(int argc, char *argv[]) {
  int n, i, l = -1, r = -1, lc = -1, rc = -1, cnt = 0;
  scanf("%s", in);
  n = strlen(in);
  for (i = 0; i < n; ++i) {
    if (l == -1 && in[i] == '[') l = i;
    if (l != -1 && in[i] == ':') {lc = i; break;} 
  }
  if (l == -1 || lc == -1) return !printf("-1\n");
  for (i = n-1; i >= 0; --i) {
    if (r == -1 && in[i] == ']') r = i;
    if (r != -1 && in[i] == ':') {rc = i; break;}
  }
  if (r == -1 || rc == lc) return !printf("-1\n");
  for (i = lc + 1; i < rc; ++i) if (in[i] == '|') ++cnt;
  return !printf("%d\n", 4 + cnt);
}

ll get_pow(ll base, ll exp) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2) {
      ret *= base;
      ret %= MOD;
    }
    base *= base;
    base %= MOD;
    exp /= 2LL;
  }
  return ret;
}