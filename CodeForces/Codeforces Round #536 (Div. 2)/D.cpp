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

bool visited[100050];
vector <int> edges[100050];
priority_queue <int, vector<int>, greater<int> > pq;

int main(int argc, char *argv[]) {
  int n, m, u, v, i, j;
  n = readInt(), m = readInt();
  for (i = 0; i < m; ++i) {
    u = readInt();
    v = readInt();
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector <int> ans;
  pq.push(1);
  visited[1] = true;
  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();

    ans.push_back(cur);
    for (int next : edges[cur]) {
      if (!visited[next]) {
        visited[next] = true;
        pq.push(next);
      }
    }
  }

  for (i = 0; i < n; ++i) printf("%d ", ans[i]);
  return !printf("\n");
}