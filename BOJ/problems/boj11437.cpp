/*
 *  BOJ 11437. LCA 
 * 
 *  시간 복잡도 : O((N + M) * logN)
 *  공간 복잡도 : O(NlogN)
 * 
 *  LCA의 개념을 공부할 수 있는 기초 문제였습니다.
 *  트리의 depth를 기록하고, 각 노드의 조상을 1, 2, 4, 8, ... 칸씩 뛰면서 저장해놓고, 
 *  나중에 LCA를 묻는 쿼리가 들어왔을 때, depth를 먼저 맞추고, 그 상태에서 2의 거듭제곱씩 뛰면서 
 *  공통 조상을 O(log N)만에 찾아내는 것입니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

// Fast I/O
const int BUFFER_SIZE = 1 << 18;
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

const int MAX = 5e4;
int N, M, ac[MAX + 1][17], depth[MAX + 1];
vector <int> edges[MAX + 1];

void init(int node, int parent);
int LCA(int a, int b);

int main(int argc, char *argv[]) {
  N = readInt();
  for (int i = 1; i < N; ++i) {
    int u = readInt(), v = readInt();
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  // 트리의 연결관계를 가지고, 1번 노드가 루트인 트리의 관계를 초기화합니다.
  depth[0] = -1;
  init(1, 0);

  M = readInt();
  while (M--) printf("%d\n", LCA(readInt(), readInt()));
  
  return 0;
}

// 각 노드의 depth를 구하고, 노드별 2의 거듭제곱 위칸에 있는 조상들의 인덱스를 저장합니다.
void init(int node, int parent) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent; // 바로 위에는 인자로 들어온 parent죠.

  // 자신의 2^N 칸 위 조상은 자신의 2^(N-1)칸 위 조상의 2^(N-1)칸 위 조상과 같죠.
  for (int i = 1; i < 17; ++i) {
    int tmp = ac[node][i - 1];
    ac[node][i] = ac[tmp][i - 1];
  }

  for (int next : edges[node])
    if (next != parent)
      init(next, node);
}

int LCA(int a, int b) {
  // a의 depth를 더 깊게 하여 일관성있는 처리를 도모했습니다.
  if (depth[a] < depth[b]) { int tmp = a; a = b; b = tmp; }

  // 두 노드의 depth를 같게 맞춰주었습니다.
  for (int i = 16; i >= 0; --i) {
    if (depth[a] - depth[b] >= (1 << i)) 
      a = ac[a][i];
  }

  // depth를 맞췄을 때 같은 노드면 그게 최소 공통 조상입니다.
  if (a == b) return a;

  // depth를 맞췄을 때, 다른 노드이면 또 위로 올라가면서 공통 조상을 찾습니다.
  for (int i = 16; i >= 0; --i) {
    if (ac[a][i] != ac[b][i]) {
      a = ac[a][i];
      b = ac[b][i];
    }
  }

  // 루프를 통해 최종적으로 공통 조상의 바로 밑까지 도달하므로 현재 상태에서 바로 윗 조상을 리턴합니다.
  return ac[a][0];
}