#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x1f1f1f1f
using namespace std;
typedef long long ll;

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
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

struct edge {
  int v, w;
};

bool operator< (edge a, edge b) {
  return a.w > b.w;
}

void dijkstra(int src, int *dist);

vector <edge> edges[805];
int main(int argc, char *argv[]) {
  int n, e, u, v, w, i, m1, m2;
  n = readInt();
  e = readInt();
  for (i = 0; i < e; ++i) {
    u = readInt();
    v = readInt();
    w = readInt();
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  m1 = readInt();
  m2 = readInt();

  int dist1[805], dist2[805], dist3[805];
  memset(dist1, 0x1f, sizeof(dist1));
  memset(dist2, 0x1f, sizeof(dist2));
  memset(dist3, 0x1f, sizeof(dist3));
  dijkstra(1, dist1);
  dijkstra(n, dist2);
  dijkstra(m1, dist3);

  int ans = min(dist1[m1] + dist2[m2], dist1[m2] + dist2[m1]) + dist3[m2];
  return !printf("%d\n", ans > INF ? -1 : ans);
}

void dijkstra(int src, int *dist) {
  priority_queue <edge> pq;
  dist[src] = 0;
  pq.push({src, 0});

  int v, w;
  while (!pq.empty()) {
    v = pq.top().v;
    w = pq.top().w;
    pq.pop();

    for (auto it : edges[v]) {
      if (dist[it.v] > dist[v] + it.w) {
        dist[it.v] = dist[v] + it.w;
        pq.push({it.v, dist[it.v]});
      }
    }
  }
}