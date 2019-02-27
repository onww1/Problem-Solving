/*
 *  BOJ 11812. K진 트리 
 * 
 *  시간 복잡도 : O(QlogN)  (log의 밑은 K)
 *  공간 복잡도 : O(logN) 
 * 
 *  LCA와 비슷한 접근을 했습니다.
 *  우선 depth를 맞추고, 그 상태에서 하나씩 올라갔습니다. 
 *  N의 범위가 10^15까지이지만 최악의 경우 K가 2일 때 depth가 가장 깊을텐데 
 *  그 때도 50을 넘어가지 않습니다. 그래서 하나씩 넘어가도록 했습니다. 
 *  
 *  trace라는 함수를 통해서 주어진 노드에서 시작해서 parent로 가면서 queue에 
 *  그 노드를 저장하고, 루트를 만날 때까지 진행합니다. 
 *  parent로 가는 것은 관찰해본 결과 그 노드에 (K - 2)를 더하고 K로 나누면 됐습니다. 
 * 
 *  그렇게 하여 루트까지 경로 상에 있는 노드들을 다 queue에 담고, queue의 사이즈가 안맞으면 
 *  depth가 다르다는 것이므로 queue의 사이즈를 맞춰주고, 하나씩 비교해 나갔습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;

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

ll N, K, Q, X, Y;

void trace(ll node, ll base, queue <ll> &q);

int main(int argc, char *argv[]) {
  N = readLL(), K = readLL(), Q = readLL();
  while (Q--) {
    X = readLL(), Y = readLL();
    
    // K가 1일 때는 메모리가 초과되므로 예외로 처리한다.
    if (K == 1LL) {
      printf("%lld\n", abs(X - Y));
      continue;
    }

    // 주어진 노드에 대해서 루트까지의 경로를 queue에 담는다.
    queue <ll> anc_X, anc_Y;
    trace(X, K, anc_X);
    trace(Y, K, anc_Y);

    int ans = 0;

    // 높이가 맞지 않으면 맞춰준다.
    while (anc_X.size() > anc_Y.size()) anc_X.pop(), ans++;
    while (anc_X.size() < anc_Y.size()) anc_Y.pop(), ans++;

    // 노드가 다르면 한 칸 올라간다.
    while (anc_X.front() != anc_Y.front()) {
      anc_X.pop();
      anc_Y.pop();
      ans += 2;
    }

    printf("%d\n", ans);
  }

  return 0;
}

// 주어진 노드에서 시작하여 루트를 만날 때까지 이동하며,
// 그 과정에서 만나는 노드들을 queue에 담습니다.
void trace(ll node, ll base, queue <ll> &q) {
  while (node) {
    q.push(node);
    node = (node + base - 2) / base;
  }
}