#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define INF 1023456789LL
#define MOD 998244353LL
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);

set <int> s;
map <int, int> m;
map <int, int>::iterator it;
int in[200050], b[200050], c[200050];
int main(int argc, char *argv[]) {
  int n, i, j, nn = 1;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &in[i]);
    it = m.find(in[i]);
    if (it != m.end()) {
      b[i] = it->second;
      ++c[it->second];
    } else {
      b[i] = nn; 
      c[nn] = 1; 
      m.insert(pair<int,int>(in[i], nn++));
    }
  }

  queue<int> q;
  int cnt = 0, cur;
  i = n-1;
  while (i >= 0 && c[b[i]] == 1) {
    ++cnt; --i;
  }
  cur = b[i--];
  c[cur]--;
  for (; i >= 0; --i) {
    if (b[i] == cur) {
      c[b[i]]--;
      if (!c[b[i]]) {
        ++cnt; --i;
        while (!q.empty()) {
          cur = q.front();
          q.pop();

          if (!c[cur]) continue;
          for (; i >= 0; --i) {
            if (b[i] == cur) {
              c[b[i]]--;
              if (!c[b[i]]) break;
            } else {
              c[b[i]]--;
              if (s.count(b[i]) == 0 && c[b[i]]) {
                s.insert(b[i]);
                q.push(b[i]);
              }
            }
          }
          --i;
        }
        while (i >= 0 && c[b[i]] == 1) {
          ++cnt; --i;
        }
        if (i > 0) {
          cur = b[i];
          c[cur]--;
        }
      }
    } else {
      c[b[i]]--;
      if (s.count(b[i]) == 0 && c[b[i]]) {
        s.insert(b[i]);
        q.push(b[i]);
      }
    }
  }
  
  return !printf("%lld\n", get_pow(2LL, cnt-1));
}

ll get_pow(ll base, ll exp) {
    ll ret = 1LL;
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