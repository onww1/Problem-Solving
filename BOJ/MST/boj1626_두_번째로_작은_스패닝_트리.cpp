/*
 *  BOJ 1626. 두 번째로 작은 스패닝 트리 
 * 
 *  시간 복잡도 : O(ElogE)
 *  공간 복잡도 : O(VlogV + E)
 * 
 *  우선 크루스칼 알고리즘을 이용하기 위해서 입력으로 들어오는 간선을 통째로 우선순위 큐에 넣어서 
 *  가중치가 작은 것이 먼저 나오도록 만들어 줬습니다. 그렇게 union-find를 사용하여 MST를 만들고, 
 *  그때 사용한 간선들을 edges라는 벡터 배열에 넣어주고, 가중치는 모두 더해뒀습니다. 
 *  그리고 MST에 사용되지 않은 간선들은 remain이라는 큐에 다 모아주고, 나중에 두 번째로 작은 스패닝 트리를 
 *  찾아 나갈때 사용할 수 있도록 하였습니다. 
 * 
 *  만든 MST에 대해서 이전 문제들과 같이 LCA를 구하기 위한 전처리 작업을 하는데 이때 만드는 것은 
 *  깊이, 조상, 구간 내에 가장 큰 값, 구간 내에 두 번째로 큰 값을 찾아서 저장하도록 했습니다. 
 *  제일 큰 값이 두 개가 있더라도 절대 두 번째로 큰 값에 그 값을 넣어서는 안되고 반드시 제일 큰 값보다 
 *  작은 값이 들어가도록 했습니다. 두 번째로 작은 MST를 구할 때, MST의 가중치가 변화가 없는 것은 
 *  무의미하므로 그것을 방지하기 위해서 두 번째로 큰 값을 저장하고 있는 것입니다. 
 * 
 *  그렇게 LCA를 위한 전처리를 하고서, 이전에 모아뒀던 remain 큐에 있는 값을 하나씩 꺼내면서 
 *  사이클 내에 집어넣으려고 하는 가중치와 같지 않은 가장 큰 값을 찾아서 그 차이를 비교했습니다. 
 *  그렇게 하여 그 차이가 가장 작은 것을 채택하여 두 번째로 작은 스패닝 트리에 이용하는 것입니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef pair <int, int> pii;
typedef pair<int, pii> piii;

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

const int MAX = 5e4;
int V, E, mst, cnt;
int pa[MAX + 1], depth[MAX + 1], ac[MAX + 1][16], mx[MAX + 1][16][2];
vector <pii> edges[MAX + 1];
priority_queue < piii, vector<piii>, greater<piii> > pq;
queue <piii> remain;

int _find(int u);
void _union(int u, int v);
void init(int node, int parent, int dist);
int get_max(piii &cur);

int main(int argc, char *argv[]) {
  V = readInt(), E = readInt();
  for (int i = 0; i < E; ++i) {
    int u = readInt(), v = readInt(), w = readInt();
    pq.push({ w, {u, v} });
  }

  // 크루스칼 알고리즘
  memset(pa, -1, sizeof(pa));
  while (!pq.empty()) {
    piii cur = pq.top();
    pq.pop();

    int root_u = _find(cur.Y.X);
    int root_v = _find(cur.Y.Y);
    
    // 같은 그룹이면 다음에 사용할 수 있으므로 remain queue에 넣어주고 다음으로 넘어간다.
    if (root_u == root_v) {
      remain.push(cur);
      continue;
    }

    // 다른 그룹이면 유니온을 시켜준다.
    _union(cur.Y.X, cur.Y.Y);

    // 다른 그룹이면 mst에 포함시킨다. 
    mst += cur.X;
    edges[cur.Y.X].push_back({cur.Y.Y, cur.X});
    edges[cur.Y.Y].push_back({cur.Y.X, cur.X});
    if (++cnt == V - 1) break;
  }

  // mst를 만드는데 선택한 간선이 V - 1개가 아니거나, 간선이 V - 1개만 있으면 
  // 두 번째로 작은 스패닝 트리를 만들 수 없으므로 -1을 출력한다.
  if (cnt < V - 1 || E == V - 1) 
    return !printf("-1\n");

  // 우선순위 큐에 남아있는 간선들을 remain queue로 다 옮겨준다.
  while (!pq.empty()) {
    remain.push(pq.top());
    pq.pop();
  }

  depth[0] = -1;
  init(1, 0, 0);

  // 남은 간선들을 이용하여 cycle을 만들고, 
  // 기존 MST에서 해당 사이클 내의 최댓값을 뽑아서 차이를 비교한다.
  int diff = 0x7fffffff;
  while (!remain.empty()) {
    piii cur = remain.front();
    remain.pop();

    int MAX = get_max(cur);
    if (MAX == -1 || MAX == cur.X) continue;
    diff = min(diff, cur.X - MAX);
  }

  if (diff == 0x7fffffff || diff == 0) return !printf("-1\n");
  return !printf("%d\n", mst + diff);
}

// root를 찾아주는 함수 
int _find(int u) {
  if (pa[u] < 0) return u;
  return pa[u] = _find(pa[u]);
}

// 두 그래프를 합쳐주는 함수
void _union(int u, int v) {
  int root_u = _find(u);
  int root_v = _find(v);
  if (root_u != root_v)
    pa[root_u] = root_v;
}

// MST에 대하여 LCA를 위한 정보를 업데이트
void init(int node, int parent, int dist) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent;
  mx[node][0][0] = dist, mx[node][0][1] = -1;

  // 조상에 대한 정보를 갱신 (mx에서 마지막 인덱스의 경우 0은 가장 큰 값, 1은 그 다음 큰 값을 저장)
  for (int i = 1; i < 16; ++i) {
    int tmp = ac[node][i - 1];
    ac[node][i] = ac[tmp][i - 1];
    if (mx[node][i - 1][0] > mx[tmp][i - 1][0]) {
      mx[node][i][0] = mx[node][i - 1][0];
      mx[node][i][1] = max(mx[node][i - 1][1], mx[tmp][i - 1][0]);
    } else if (mx[node][i - 1][0] < mx[tmp][i - 1][0]) {
      mx[node][i][0] = mx[tmp][i - 1][0];
      mx[node][i][1] = max(mx[tmp][i - 1][1], mx[node][i - 1][0]);
    } else {
      mx[node][i][0] = mx[node][i - 1][0];
      mx[node][i][1] = max(mx[node][i - 1][1], mx[tmp][i - 1][1]);
    }
  }

  // 자식 노드에 대하여 재귀 호출 
  for (pii next : edges[node])
    if (next.X != parent)
      init(next.X, node, next.Y);
}

int get_max(piii &cur) {
  int u = cur.Y.X, v = cur.Y.Y, val = cur.X;

  // u의 깊이를 더 깊게 만든다.
  if (depth[u] < depth[v]) swap(u, v);

  // 가중치의 범위는 음이 아닌 정수이므로 불가능한 -1을 default로 하고, 
  // 주어진 간선이랑 같은 가중치를 갖는 것을 뽑는 것은 무의미한 일이므로 주어진 가중치보다 
  // 작은 간선 중에서 가장 큰 애를 뽑는다.
  int ret = -1;
  
  // 깊이를 맞춘다.
  for (int i = 15; i >= 0; --i) {
    if (depth[u] - depth[v] >= (1 << i)) {
      if (mx[u][i][0] != val) ret = max(ret, mx[u][i][0]);
      else if (mx[u][i][1] != val) ret = max(ret, mx[u][i][1]);
      u = ac[u][i];
    }
  }

  // 깊이를 맞췄는데도 노드가 같지 않다면 LCA를 찾아 올라간다.
  if (u != v) {
    for (int i = 15; i >= 0; --i) {
      if (ac[u][i] != ac[v][i]) {
        if (mx[u][i][0] != val) ret = max(ret, mx[u][i][0]);
        else if (mx[u][i][1] != val) ret = max(ret, mx[u][i][1]);

        if (mx[v][i][0] != val) ret = max(ret, mx[v][i][0]);
        else if (mx[v][i][1] != val) ret = max(ret, mx[v][i][1]);

        u = ac[u][i];
        v = ac[v][i];
      }
    }

    if (mx[u][0][0] != val) ret = max(ret, mx[u][0][0]);
    else if (mx[u][0][1] != val) ret = max(ret, mx[u][0][1]);

    if (mx[v][0][0] != val) ret = max(ret, mx[v][0][0]);
    else if (mx[v][0][1] != val) ret = max(ret, mx[v][0][1]);
  }

  return ret;
}