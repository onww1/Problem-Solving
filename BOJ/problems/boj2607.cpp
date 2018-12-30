#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int parse(char c);

int main(int argc, char *argv[]) {

  int n, i, count, diff, len, in_len, cnt[26] = {0}, in_cnt[26];
  char str[11], in[11];

  scanf("%d", &n);
  scanf("%s", str);
  len = strlen(str);

  count = 0;
  for (i = 0; i < len; ++i) 
    ++cnt[parse(str[i])];

  --n;
  while (n--) {
    scanf("%s", in);
    in_len = strlen(in);
    diff = 0;
    for (i = 0; i < 26; ++i) in_cnt[i] = 0;

    for (i = 0; i < in_len; ++i)
      ++in_cnt[parse(in[i])];
    
    for (i = 0; i < 26; ++i)
      if (in_cnt[i] != cnt[i]) 
        diff += get_abs(in_cnt[i] - cnt[i]);

    if (diff == 0 || diff == 1 || (diff == 2 && in_len == len)) 
      ++count;
  }

  printf("%d\n", count);
  return 0;
}

int parse(char c) { return c - 'A'; }

ll get_pow(ll base, ll exp) {
  if (exp == 0ll) return 1ll;
  if (exp == 1ll) return base;

  ll half = get_pow(base, exp/2ll);
  ll res = half * half % MOD;
  if (exp % 2ll) res = res * base % MOD;
  return res;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }