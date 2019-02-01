#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#define INF 1023456789
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct envelope {
  int s, t, d;
  ll w;
};

bool operator< (envelope a, envelope b) {
  if (a.w == b.w) return a.d < b.d;
  return a.w < b.w;
}

bool cmp(envelope a, envelope b) {
  if (a.s == b.s) return a.t < b.t;
  return a.s < b.s;
}

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
inline int readInt() {
  int sum = 0, flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flag ? sum : -sum;
}
inline int readLongLong() {
  ll sum = 0;
  int flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10LL + now - '0', now = read();
  return flag ? sum : -sum;
}

envelope envs[100050];
pll coin[100050];
ll DP[100050][201];
priority_queue <envelope> pq;
int n, m, k;

ll solve(int T, int D) {
  if (T > n) return 0LL;
  ll &ret = DP[T][D];
  if (ret != -1) return ret;
  if (!coin[T].first) return ret = solve(T + 1, D);
  if (D > 0) return ret = min(solve(T + 1, D - 1),
                              solve(coin[T].first + 1, D) + coin[T].second);
  return ret = solve(coin[T].first + 1, D) + coin[T].second;
}

int main(int argc, char *argv[]) {
  int i, j;
  n = readInt();
  m = readInt();
  k = readInt();
  for (i = 0; i < k; ++i) {
    envs[i].s = readInt(); envs[i].t = readInt();
    envs[i].d = readInt(); envs[i].w = readLongLong();
  }

  sort(envs, envs + k, cmp);
  for (int i = 1, p = 0; i <= n; ++i) {
    while (p < k && envs[p].s == i) pq.push(envs[p++]);
    while (!pq.empty() && pq.top().t < i) pq.pop();
    if (!pq.empty()) coin[i] = { pq.top().d, pq.top().w };
  }

  memset(DP, -1, sizeof(DP));
  return !printf("%lld\n", solve(1, m));
}