#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int BS = 1 << 17;
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

const int VMAX = 1e4, EMAX = 3e5, INF = 0x7f7f7f7f;
int V, E, M, S, x, y, u, v, w;
vector <pii> edges[VMAX + 1];
int mdist[VMAX + 1], sdist[VMAX + 1];

void dijkstra(priority_queue < pii, vector<pii>, greater<pii> > &pq, int *dist) {
  while (!pq.empty()) {
    pii cur = pq.top();
    pq.pop();

    if (dist[cur.Y] < cur.X) continue;

    for (pii edge : edges[cur.Y]) {
      if (dist[edge.X] > dist[cur.Y] + edge.Y) {
        dist[edge.X] = dist[cur.Y] + edge.Y;
        pq.push({dist[edge.X], edge.X});
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int i;
  V = readInt(), E = readInt();
  for (i = 0; i < E; ++i) {
    u = readInt(), v = readInt(), w = readInt();
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  memset(mdist, 0x7f, sizeof(mdist));
  memset(sdist, 0x7f, sizeof(sdist));
  priority_queue < pii, vector<pii>, greater<pii> > mpq, spq;

  M = readInt(), x = readInt();
  for (i = 0; i < M; ++i) {
    u = readInt();
    mdist[u] = 0;
    mpq.push({0, u});
  }

  S = readInt(), y = readInt();
  for (i = 0; i < S; ++i) {
    u = readInt();
    sdist[u] = 0;
    spq.push({0, u});
  }

  dijkstra(mpq, mdist);
  dijkstra(spq, sdist);

  int mn = INF;
  for (i = 1; i <= V; ++i) 
    if (mdist[i] && sdist[i] && mdist[i] <= x && sdist[i] <= y) 
      mn = min(mn, sdist[i] + mdist[i]);
  
  return !printf("%d\n", mn == INF ? -1 : mn);
}