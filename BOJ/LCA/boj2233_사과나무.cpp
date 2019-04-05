/*
 *  BOJ 2233. 사과나무
 * 
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(NlogN) 
 * 
 *  먼저 들어오는 이진 수열을 스택을 이용해서 각각이 몇 번째 사과인지, 각 사과가 몇 번째 인덱스에 
 *  매칭되는지, 각 사과가 어떻게 연결이 되어 있는지를 파악해서 저장해두고, 그것을 기반으로 앞에서 했던 
 *  LCA에 대한 전처리 작업을 합니다. 그렇게 얻은 데이터를 가지고 주어진 X와 Y의 LCA를 구하고, 
 *  그 LCA에 해당하는 사과의 인덱스를 출력해주면 되는 문제였습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;

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

const int MAX = 2000;
int N, X, Y, apple[2 * MAX + 1], depth[MAX + 1], ac[MAX + 1][11], cnt;
vector <int> edges[MAX + 1], stack;
pii pos[MAX + 1];
char in;

void input();
void init(int node, int parent);
int LCA(int u, int v);

int main(int argc, char *argv[]) {
  input();

  // LCA를 위한 전처리
  depth[0] = -1;
  init(1, 0);

  // X와 Y에 대응되는 두 사과에 대하여 LCA를 구한다.
  int lca = LCA(apple[X], apple[Y]);

  // LCA에 대응되는 사과의 0과 1의 위치를 출력한다.
  return !printf("%d %d\n", pos[lca].X, pos[lca].Y);
}

void input() {
  N = readInt();

  // 사과에 대한 정보를 받아서 각 사과가 몇 번째 사과인지, 사과별로 몇번째 인덱스에 있는지를 저장
  do in = read(); while (in == ' ' || in == '\n');
  stack.push_back(++cnt); 
  pos[cnt].first = 1;
  apple[1] = cnt;

  for (int i = 2; i <= 2 * N; ++i) {
    in = read();
    if (in == '0') {
      stack.push_back(++cnt);
      pos[cnt].first = i;
      apple[i] = cnt;
    } else {
      int cur = stack.back();
      stack.pop_back();
      pos[cur].second = i;
      apple[i] = cur;

      // 트리의 간선을 이어줌
      if (!stack.empty()) {
        edges[cur].push_back(stack.back());
        edges[stack.back()].push_back(cur);
      }
    }
  }

  X = readInt(), Y = readInt();
}

// LCA를 위한 전처리
void init(int node, int parent) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent;

  // 조상을 갱신
  for (int i = 1; i < 11; ++i) {
    int tmp = ac[node][i - 1];
    ac[node][i] = ac[tmp][i - 1];
  }

  // 자손에 대해서도 재귀 호출
  for (int next : edges[node]) 
    if (next != parent)
      init(next, node);
}

int LCA(int u, int v) {
  
  // u의 depth가 더 깊어지도록 한다.
  if (depth[u] < depth[v]) swap(u, v);

  // u와 v의 depth가 같지 않으면 맞춰준다.
  for (int i = 10; i >= 0; --i) {
    if (depth[u] - depth[v] >= (1 << i)) 
      u = ac[u][i];
  }

  // 같은 depth에서도 같지 않으면 공통 조상을 찾아 올라간다.
  if (u != v) {
    for (int i = 10; i >= 0; --i) {
      if (ac[u][i] != ac[v][i]) {
        u = ac[u][i];
        v = ac[v][i];
      }
    }
    u = ac[u][0];
    v = ac[v][0];
  }

  // lca를 리턴
  return u;
}