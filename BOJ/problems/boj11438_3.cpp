/*
 *  BOJ 11438. LCA 2
 * 
 *  시간 복잡도 : O((N + M) * logN)
 *  공간 복잡도 : O(NlogN) 
 *  
 *  boj11437 LCA 문제랑 똑같은데 범위만 2배만큼 커졌습니다.
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

const int MAX = 1e5;
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

  depth[0] = -1;
  init(1, 0);

  M = readInt();
  while (M--) printf("%d\n", LCA(readInt(), readInt()));
  
  return 0;
}

// LCA 초기화 함수
void init(int node, int parent) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent;

  for (int i = 1; i < 17; ++i) {
    int tmp = ac[node][i - 1];
    ac[node][i] = ac[tmp][i - 1];
  }

  for (int next : edges[node])
    if (next != parent)
      init(next, node);
}

// LCA를 구하는 함수
int LCA(int a, int b) {
  if (depth[a] < depth[b]) { int tmp = a; a = b; b = tmp; }

  for (int i = 16; i >= 0; --i) {
    if (depth[a] - depth[b] >= (1 << i)) 
      a = ac[a][i];
  }

  if (a == b) return a;

  for (int i = 16; i >= 0; --i) {
    if (ac[a][i] != ac[b][i]) {
      a = ac[a][i];
      b = ac[b][i];
    }
  }

  return ac[a][0];
}