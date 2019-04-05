/*
 *  BOJ 1280. 나무 심기 
 * 
 *  시간 복잡도 : O(NlogK)  (K = 20만)
 *  공간 복잡도 : O(N) 
 * 
 *  값을 구할 때는 차이를 가지고 하는 것이므로 절대적인 값은 무엇이든 상관이 없어서 0 ~ 199999의 범위를 
 *  1 ~ 200000으로 바꾼 다음 펜윅트리에 순서대로 저장을 해가면서 현재 위치보다 큰 범위에 대해서 차이를 구하고, 
 *  작은 범위에 대해서 차이를 구한 다음 그 값을 더하고, 최종 결과에 곱하는 식으로 진행했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
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

const int MAX = 2e5;
const int MOD = 1e9 + 7;
ll treeV[MAX + 5], treeC[MAX + 5], ans = 1LL, s;
int N, A;

void update(ll arr[], int node, ll diff);
ll sum(ll arr[], int node);

int main(int argc, char *argv[]) {
  N = readInt();
  A = readInt() + 1;
  update(treeV, A, A);
  update(treeC, A, 1);

  for (int i = 1; i < N; ++i) {
    A = readInt() + 1;
    s = (sum(treeV, MAX) - sum(treeV, A) - (i - sum(treeC, A)) * A) % MOD;
    s = (s + sum(treeC, A - 1) * A - sum(treeV, A - 1)) % MOD;
    ans = (ans * s) % MOD;
    update(treeV, A, A);
    update(treeC, A, 1);
  }
  return !printf("%lld\n", ans);
}

// 업데이트 함수
void update(ll arr[], int node, ll diff) {
  while (node <= MAX) {
    arr[node] += diff;
    node += node & -node;
  }
}

// 1 ~ node 의 합을 구하는 함수
ll sum(ll arr[], int node) {
  ll ret = 0;
  while (node > 0) {
    ret += arr[node];
    node -= node & -node;
  }
  return ret;
}