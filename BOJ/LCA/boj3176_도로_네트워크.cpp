/*
 *  BOJ 3176. 도로 네트워크 
 * 
 *  시간 복잡도 : O((N + K) * logN)
 *  공간 복잡도 : O(NlogN) 
 * 
 *  이전 문제들과 비슷하게 조상에 대한 정보를 저장하는데, 그 과정에서 그 노드와 조상 사이 구간의 
 *  거리의 최솟값과 최댓값을 저장해주어서 LCA를 찾을 때 함께 갱신해 나갔습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
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
inline ll readLL() {
  ll sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}

const int MAX = 1e5;
int N, K, depth[MAX + 1], ac[MAX + 1][17], mx[MAX + 1][17], mn[MAX + 1][17];
vector <pii> edges[MAX + 1];

void init(int node, int parent, int dist);
pii LCA(int a, int b);

int main(int argc, char *argv[]) {
  N = readInt();
  for (int i = 1; i < N; ++i) {
    int u = readInt(), v = readInt(), w = readInt();
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  depth[0] = -1;
  init(1, 0, 0);

  K = readInt();
  while (K--) {
    pii lca = LCA(readInt(), readInt());
    printf("%d %d\n", lca.first, lca.second);
  }

  return 0;
}

// 깊이, 조상, 구간 최소, 구간 최대를 초기화하는 함수
void init(int node, int parent, int dist) {

  // 들어온 인자를 가지고 기본적인 초기화
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent;
  mx[node][0] = mn[node][0] = dist;

  // 조상에 대한 정보를 갱신
  for (int i = 1; i <= 16; ++i) {
    int tmp = ac[node][i - 1];
    ac[node][i] = ac[tmp][i - 1];
    mx[node][i] = max(mx[node][i - 1], mx[tmp][i - 1]);
    mn[node][i] = min(mn[node][i - 1], mn[tmp][i - 1]);
  }

  // 자식 노드에 대해서도 재귀호출
  for (pii next : edges[node]) 
    if (next.first != parent)
      init(next.first, node, next.second);
}

// 들어온 쿼리에 대하여 두 노드 사이의 최소 거리와 최대 거리를 반환
pii LCA(int a, int b) {
  int MAX = 0, MIN = 1e9;

  // a의 깊이가 더 깊도록 처리 
  if (depth[a] < depth[b]) swap(a, b);

  // a와 b의 깊이가 같아지도록 a의 깊이를 맞춰주자.
  for (int i = 16; i >= 0; --i) {
    if (depth[a] - depth[b] >= (1 << i)) {
      MIN = min(MIN, mn[a][i]);
      MAX = max(MAX, mx[a][i]);
      a = ac[a][i];
    }
  }

  // 깊이를 맞췄는데도 a와 b가 다르면 최소 공통 조상을 찾아서 올라간다.
  if (a != b) {
    // 두 노드가 같아지기 직전까지 올라간다.
    for (int i = 16; i >= 0; --i) {
      if (ac[a][i] != ac[b][i]) {
        MIN = min({MIN, mn[a][i], mn[b][i]});
        MAX = max({MAX, mx[a][i], mx[b][i]});
        a = ac[a][i];
        b = ac[b][i];
      }
    }

    // 마지막으로 공통조상까지의 거리를 가지고 MIN, MAX를 갱신한다. 
    MIN = min({MIN, mn[a][0], mn[b][0]});
    MAX = max({MAX, mx[a][0], mx[b][0]});
  }

  return { MIN, MAX };
}