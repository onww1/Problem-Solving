#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 1000000007LL
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

struct point {
  int r, c;
};

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int main(int argc, char *argv[]) {
  int n, a, b, i, j, k;
  vector<point> p;
  vector<point> ab;

  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf(" %d %d", &a, &b);
    p.push_back({a, b});
  }
  for (i = 0; i < n; ++i) {
    scanf(" %d %d", &a, &b);
    ab.push_back({a, b});
  }

  queue<point> candidate;
  for (j = 0; j < n; ++j) 
    candidate.push({p[0].r + ab[j].r, p[0].c + ab[j].c});

  int len = n;
  point pos;
  for (i = 1; i < n; ++i) {
    len = candidate.size();
    for (j = 0; j < len; ++j) {
      pos = candidate.front();
      candidate.pop();

      for (k = 0; k < n; ++k) {
        a = pos.r - ab[k].r;
        b = pos.c - ab[k].c;
        if (a == p[i].r && b == p[i].c) {
          candidate.push(pos);
          break;
        }
      }
    }
  }

  printf("%d %d\n", candidate.front().r, candidate.front().c);
  return 0;
}

ll get_pow(ll base, ll exp) {
  ll ret = 1;
  while (exp > 0) {
    if (exp % 2) {
      ret *= base;
      ret %= MOD;
    }
    base *= base;
    base %= MOD;
    exp /= 2;
  }
  return ret;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }
