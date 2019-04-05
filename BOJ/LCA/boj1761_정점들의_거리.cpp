/*
 *  BOJ 1761. 정점들의 거리
 *  
 *  시간 복잡도 : O((N + M) * logN)
 *  공간 복잡도 : O(NlogN)
 * 
 *  LCA를 구하는건 똑같은데 현 노드에서 조상까지의 거리도 같이 저장을 함으로써 
 *  LCA를 찾아나가면서 거리까지 구하도록 만들었습니다. 
 *  
 *  거리를 저장하는 것은 조상을 저장하는 것과 같은 원리로 만들면 됩니다!
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define ancestor first
#define dist second
using namespace std;

typedef pair <int, int> pii;

// Fast I/O
const int BUFFER_SIZE = 1 << 17;
char buf[BUFFER_SIZE];
inline char read() {
  static int idx = BUFFER_SIZE;
  if (idx == BUFFER_SIZE) {
    int nidx = fread(buf, 1, BUFFER_SIZE, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}

const int MAX = 4e4;
int N, M, depth[MAX + 1];
pii ac[MAX + 1][16];
vector <pii> edges[MAX + 1];

void init(int node, int parent, int dist);
int LCA(int a, int b);

int main(int argc, char *argv[]) {
  N = readInt();
  for (int i = 1; i < N; ++i) {
    int u = readInt(), v = readInt(), w = readInt();
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  // LCA 쿼리를 처리하기 위한 정보를 초기화
  depth[0] = -1;
  init(1, 0, 0);

  M = readInt();
  while (M--) printf("%d\n", LCA(readInt(), readInt()));

  return 0;
}

// 깊이, 조상, 거리를 모두 업데이트
void init(int node, int parent, int dist) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = { parent, dist };

  for (int i = 1; i < 16; ++i) {
    int tmp = ac[node][i - 1].ancestor;
    ac[node][i] = { ac[tmp][i - 1].ancestor, ac[tmp][i - 1].dist + ac[node][i - 1].dist };
  }

  for (pii next : edges[node])
    if (next.ancestor != parent)
      init(next.ancestor, node, next.dist);
}

// 최소 공통 조상을 구하고, 그 공통 조상까지의 거리의 합을 반환.
int LCA(int a, int b) {
  int dist = 0;

  // 일관성 있게 a의 깊이를 더 깊게 만들어주자.
  if (depth[a] < depth[b]) { int tmp = a; a = b; b = tmp; }

  // 두 노드의 깊이를 같게 만들어주자.
  for (int i = 15; i >= 0; --i) {
    if (depth[a] - depth[b] >= (1 << i)) {
      dist += ac[a][i].dist;
      a = ac[a][i].ancestor;
    }
  }

  // 만약 깊이가 같은 두 노드가 같은 노드라면 이것이 최소 공통 조상이다.
  if (a == b) return dist;

  // 만약 두 노드가 깊이가 같은데도 같지 않으면, 같은 노드가 나오기 직전까지 이동한다.
  for (int i = 15; i >= 0; --i) {
    if (ac[a][i].ancestor != ac[b][i].ancestor) {
      dist += (ac[a][i].dist + ac[b][i].dist);
      a = ac[a][i].ancestor;
      b = ac[b][i].ancestor;
    }
  }

  // 최소 공통 조상 직전까지 도달한 것이므로 마지막으로 바로 위까지 거리를 더해준다.
  dist += (ac[a][0].dist + ac[b][0].dist);
  return dist;
}