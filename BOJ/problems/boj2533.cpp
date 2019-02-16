#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int BS = 1 << 16;
char buf[BS];

inline char read() {
  static int idx = BS;
  if (idx == BS) {
    int nidx = fread(buf, 1, BS, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

const int MAX = 1e6;
const int INF = 0x7f7f7f7f;
vector <int> edges[MAX + 1];
int N, DP[2][MAX + 1];

int solve(int node, int parent, int early) {
  int &ret = DP[early][node];
  if (ret != -1) return ret;
  ret = early;

  for (int next : edges[node]) {
    if (next != parent) {
      int val = solve(next, node, 1);
      if (early) val = min(val, solve(next, node, 0));
      ret += val;
    }
  }

  return ret;
}

int main(int argc, char *argv[]) {
  int u, v;

  N = readInt();
  for (int i = 1; i < N; ++i) {
    u = readInt();
    v = readInt();
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  memset(DP, -1, sizeof(DP));
  return !printf("%d\n", min(solve(1, 0, 1), solve(1, 0, 0)));
}